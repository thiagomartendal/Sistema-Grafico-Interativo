#include "aplicativo.h"

/*
* Construtor
* São definidos a janela gráfica principal, a classe com os métodos de interação
* entre a visão e o modelo, são chamados os métodos de ações e o renderizador
*/
Aplicativo::Aplicativo() {
  janela = new Janela();
  interacaoObjeto = InteracaoObjeto(janela);
  Aplicativo::acoesMenu();
  Aplicativo::acoesPainelLateral();
  janela->getDesenho()->set_draw_func(sigc::mem_fun(*this, &Aplicativo::atualizarDesenho));
}

// Destrutor
Aplicativo::~Aplicativo() {
  delete janela;
}

// Cria o ponteiro da classe
Glib::RefPtr<Aplicativo> Aplicativo::create() {
  return Glib::make_refptr_for_instance<Aplicativo>(new Aplicativo());
}

/*
* Define Aplicativo::on_startup com o método base de
* Gtk::Application::on_startup
*/
void Aplicativo::on_startup() {
  Gtk::Application::on_startup();
}

// Inicia a janela gráfica principal da aplicação
void Aplicativo::on_activate() {
  add_window(*janela);
  janela->show();
}

/*
* Conecta as ações da barra de menu da classe Janela com os métodos das janelas
* de criação de objetos
*/
void Aplicativo::acoesMenu() {
  Glib::RefPtr<Gio::SimpleActionGroup> acoes = Gio::SimpleActionGroup::create();
  acoes->add_action("sair", sigc::mem_fun(*janela, &Janela::sair));
  acoes->add_action("reta", sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::inserir), TipoPainel::PAINEL_LR, Tipo::RETA));
  acoes->add_action("curva_bezier", sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::inserir), TipoPainel::PAINEL_CB, Tipo::CURVA_BEZIER));
  acoes->add_action("quadrado", sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::inserir), TipoPainel::PAINEL_Q, Tipo::QUADRADO));
  acoes->add_action("circulo", sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::inserir), TipoPainel::PAINEL_C, Tipo::CIRCULO));
  acoes->add_action("triangulo", sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::inserir), TipoPainel::PAINEL_T, Tipo::TRIANGULO));
  acoes->add_action("retangulo", sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::inserir), TipoPainel::PAINEL_R, Tipo::RETANGULO));
  acoes->add_action("poligono", sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::inserir), TipoPainel::PAINEL_P, Tipo::POLIGONO));
  janela->insert_action_group("janela", acoes);
}

/*
* Conecta as ações dos botões do painel lateral com as interações
* correspondentes
*/
void Aplicativo::acoesPainelLateral() {
  /*
  * Ações referentes a um objeto de uma determinada classe devem ser declaradas
  * na própria classe ou onde a mesma é incialmente instânciada
  */
  ComponenteZoom& componenteZoom = janela->getPainel()->getZoom().getComponente();
  componenteZoom.zoomMais.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::zoom), '+'));
  componenteZoom.zoomMenos.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::zoom), '-'));
  componenteZoom.redefinirZoom.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::zoom), '*'));

  ComponenteMovimento& componenteMovimento = janela->getPainel()->getMovimento().getComponente();
  componenteMovimento.cima.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::CIMA));
  componenteMovimento.esquerda.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::ESQUERDA));
  componenteMovimento.centro.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::CENTRO));
  componenteMovimento.direita.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::DIREITA));
  componenteMovimento.baixo.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::BAIXO));
  componenteMovimento.cimaEsquerda.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::CIMA_ESQUERDA));
  componenteMovimento.cimaDireita.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::CIMA_DIREITA));
  componenteMovimento.baixoEsquerda.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::BAIXO_ESQUERDA));
  componenteMovimento.baixoDireita.signal_clicked().connect(sigc::bind(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::moverWindow), Direcao::BAIXO_DIREITA));

  ComponenteRotacaoWindow& componenteRotacaoWindow = janela->getPainel()->getRotacaoWindow().getComponente();
  componenteRotacaoWindow.rotacionarWindow.signal_clicked().connect(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::rotacionarWindow));

  ComponenteTranslacao& componenteTranslacao = janela->getPainel()->getTranslacao().getComponenteTranslacao();
  ComponenteEscalonamento& componenteEscalonamento = janela->getPainel()->getEscalonamento().getComponenteEscalonamento();
  ComponenteRotacao& componenteRotacao = janela->getPainel()->getRotacao().getComponente();
  componenteTranslacao.transladar.signal_clicked().connect(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::transladar));
  componenteEscalonamento.escalar.signal_clicked().connect(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::escalonar));
  componenteRotacao.rotacionar.signal_clicked().connect(sigc::mem_fun(interacaoObjeto, &InteracaoObjeto::rotacionar));
}

// Renderiza os objetos na área de desenho
void Aplicativo::atualizarDesenho(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
  ListaObjeto lista = interacaoObjeto.getLista();
  janela->getDesenho()->tela(cr);
  for (Objeto objeto: lista.getObjetos()) {
    if (objeto.getTipo() == Tipo::RETA) {
      Reta lr = static_cast<Reta&>(objeto);
      lr.renderizar(cr);
    } else if (objeto.getTipo() == Tipo::CURVA_BEZIER) {
      CurvaBezier cb = static_cast<CurvaBezier&>(objeto);
      cb.renderizar(cr);
    } else if (objeto.getTipo() == Tipo::QUADRADO) {
      Quadrado q = static_cast<Quadrado&>(objeto);
      q.renderizar(cr);
    } else if (objeto.getTipo() == Tipo::CIRCULO) {
      Circulo c = static_cast<Circulo&>(objeto);
      c.renderizar(cr);
    } else if (objeto.getTipo() == Tipo::TRIANGULO) {
      Triangulo t = static_cast<Triangulo&>(objeto);
      t.renderizar(cr);
    } else if (objeto.getTipo() == Tipo::RETANGULO) {
      Retangulo r = static_cast<Retangulo&>(objeto);
      r.renderizar(cr);
    } else if (objeto.getTipo() == Tipo::POLIGONO) {
      Poligono p = static_cast<Poligono&>(objeto);
      p.renderizar(cr);
    }
  }
}
