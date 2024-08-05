#include "interacaoObjeto.h"

/*
* Construtor
* São definidas as classes de lista de objetos, transformações gráficas e a
* estrutura de dimensões que armazena a window e a viewport
*/
InteracaoObjeto::InteracaoObjeto(Janela* janela) {
  lista = ListaObjeto();
  transformacao = Transformacao();
  dimensao = EstruturaDimensao();
  this->janela = janela;
  InteracaoObjeto::definirDimensoes();
}

// Inicializa a window e a viewport
void InteracaoObjeto::definirDimensoes() {
  double largura = (double)janela->getDesenho()->getLargura();
  double altura = (double)janela->getDesenho()->getAltura();
  dimensao.definir(largura, altura);
}

/*
* Produz um objeto gráfico a partir dos dados registrados em uma caixa de
* dialogo
*/
void InteracaoObjeto::inserir(TipoPainel painel, Tipo tipoObjeto) {
  // 0 0 0 100 100 200 200 200 300 100 300 0 200 -100 100 -100 <= Polígono
  Glib::RefPtr<NovoObjeto2D> novoObjeto2D = Glib::make_refptr_for_instance<NovoObjeto2D>(new NovoObjeto2D(painel, *janela));
  ProduzirObjeto produzir = ProduzirObjeto(novoObjeto2D);
  novoObjeto2D->getOk().signal_clicked().connect([=](){
    InteracaoObjeto::confirmarObjeto(tipoObjeto, produzir);
    novoObjeto2D->hide();
  });
}

// Normaliza o objeto gráfico produzido e o insere na lista de objetos
void InteracaoObjeto::confirmarObjeto(Tipo tipoObjeto, ProduzirObjeto produzir) {
  produzir.definirObjeto(tipoObjeto);
  Objeto objeto = produzir.getObjeto();

  for (Ponto ponto: objeto.getPontos()) {
    Ponto normalizado = transformacao.normalizar(transformacao.getAnguloWindow(), dimensao.getWindow(), ponto);
    Ponto transformado = transformacao.viewport(normalizado, dimensao.getVieport(), dimensao.getWindow());
    objeto.addPontoTransformado(transformado);
  }

  lista.inserir(objeto);
  janela->getPainel()->inserirObjeto(objeto.getNome(), produzir.getTipo());
  janela->getDesenho()->queue_draw();
}

/*
* Realiza a transformada de viewport para converter as coordenadas dos objetos
* gráficos para a área de exibição
*/
void InteracaoObjeto::executarTransformadaViewport(double angulo) {
  for (Objeto& objeto: lista.getObjetos()) {
    objeto.limparPontosTransformados();
    for (Ponto p: objeto.getPontos()) {
      Ponto n = transformacao.normalizar(angulo, dimensao.getWindow(), p);
      objeto.addPontoTransformado(transformacao.viewport(n,
       dimensao.getVieport(), dimensao.getWindow()));
    }
  }
}

/*
* Método da ação do zoom
* Realiza a transformação de zoom e executa a transformada de viewport
*/
void InteracaoObjeto::zoom(char tipoZoom) {
  ComponenteZoom& componente = janela->getPainel()->getZoom().getComponente();
  transformacao.zoom(dimensao, tipoZoom);
  InteracaoObjeto::executarTransformadaViewport(transformacao.getAnguloWindow());
  janela->getDesenho()->queue_draw();
  componente.fatorZoom.get_buffer()->set_text(std::to_string(transformacao.getFatorZoom()) + "%");
}

/*
* Método da ação dos movimentos da window
* Realiza a transformação de moviento e executa a transformada de viewport
*/
void InteracaoObjeto::moverWindow(Direcao direcao) {
  ComponenteMovimento& componente = janela->getPainel()->getMovimento().getComponente();
  double fator = std::stod(componente.fatorMovimento.get_buffer()->get_text());
  transformacao.moverWindow(dimensao, fator, direcao);
  InteracaoObjeto::executarTransformadaViewport(transformacao.getAnguloWindow());
  janela->getDesenho()->queue_draw();
}

/*
* Método da ação de translação dos objetos gráficos
* Realiza a transformação de translação e executa a transformada de viewport
*/
void InteracaoObjeto::transladar() {
  ComponenteTranslacao& componente = janela->getPainel()->getTranslacao().getComponenteTranslacao();
  int pos = janela->getPainel()->getObjetoSelecionado();
  std::string X = componente.Dx.get_buffer()->get_text();
  std::string Y = componente.Dy.get_buffer()->get_text();
  double distanciaX = std::stod(((X == "") ? "0.0" : X));
  double distanciaY = std::stod(((Y == "") ? "0.0" : Y));
  if (pos != -1) {
    transformacao.translacao2D(distanciaX, distanciaY, lista.getObjetos()[pos].getPontos());
    InteracaoObjeto::executarTransformadaViewport();
    janela->getDesenho()->queue_draw();
  } else janela->mensagem("Nenhum objeto foi selecionado.");
}

/*
* Método da ação de escalonamento dos objetos gráficos
* Realiza a transformação de escalonamento e executa a transformada de viewport
*/
void InteracaoObjeto::escalonar() {
  ComponenteEscalonamento& componente = janela->getPainel()->getEscalonamento().getComponenteEscalonamento();
  int pos = janela->getPainel()->getObjetoSelecionado();
  std::string X = componente.Sx.get_buffer()->get_text();
  std::string Y = componente.Sy.get_buffer()->get_text();
  double escalaX = std::stod(((X == "") ? "0.0" : X));
  double escalaY = std::stod(((Y == "") ? "0.0" : Y));
  if (pos != -1) {
    if (lista.getObjetos()[pos].getTipo() == Tipo::QUADRADO)
      transformacao.escala2D(escalaX, escalaX, lista.getObjetos()[pos].centro(), lista.getObjetos()[pos].getPontos());
    else
      transformacao.escala2D(escalaX, escalaY, lista.getObjetos()[pos].centro(), lista.getObjetos()[pos].getPontos());
    InteracaoObjeto::executarTransformadaViewport();
    janela->getDesenho()->queue_draw();
  } else janela->mensagem("Nenhum objeto foi selecionado.");
}

/*
* Método da ação de rotação dos objetos gráficos
* Realiza a transformação de rotação e executa a transformada de viewport
*/
void InteracaoObjeto::rotacionar() {
  ComponenteRotacao& componente = janela->getPainel()->getRotacao().getComponente();
  int pos = janela->getPainel()->getObjetoSelecionado();
  std::string valorAngulo = componente.angulo.get_buffer()->get_text();
  double angulo = std::stod(((valorAngulo == "") ? "0.0" : valorAngulo));
  Ponto pontoRotacao;
  if (pos != -1) {
    if (componente.tipoRotacao == "objeto")
      pontoRotacao = lista.getObjetos()[pos].centro();
    else if (componente.tipoRotacao == "mundo") pontoRotacao = {0.0, 0.0};
    else {
      std::string X = componente.X.get_buffer()->get_text();
      std::string Y = componente.Y.get_buffer()->get_text();
      std::string Z = componente.Z.get_buffer()->get_text();
      pontoRotacao =
      Ponto{
        std::stod((X == "") ? "0.0" : X),
        std::stod((Y == "") ? "0.0" : Y),
        std::stod((Z == "") ? "0.0" : Z)
      };
    }
    transformacao.rotacao2D(angulo, pontoRotacao, lista.getObjetos()[pos].getPontos());
    InteracaoObjeto::executarTransformadaViewport();
    janela->getDesenho()->queue_draw();
  } else janela->mensagem("Nenhum objeto foi selecionado.");
}

/*
* Método da ação de rotação da window
* Realiza a transformação de rotação de todos os objetos na window e executa a
* transformada de viewport
*/
void InteracaoObjeto::rotacionarWindow() {
  ComponenteRotacaoWindow& componente = janela->getPainel()->getRotacaoWindow().getComponente();
  std::string valorAngulo = componente.anguloWindow.get_buffer()->get_text();
  double angulo = std::stod(((valorAngulo == "") ? "0.0" : valorAngulo));
  transformacao.addAnguloWindow(angulo);
  InteracaoObjeto::executarTransformadaViewport(transformacao.getAnguloWindow());
  janela->getDesenho()->queue_draw();
}

// Retorna a classe da lista de objetos
ListaObjeto InteracaoObjeto::getLista() {
  return lista;
}
