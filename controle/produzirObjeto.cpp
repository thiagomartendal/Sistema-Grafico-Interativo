#include "produzirObjeto.h"

/*
* Construtor
* Atribui a caixa de dialogo da criação de objetos gráficos para capturar os
* dados necessários destes objetos
*/
ProduzirObjeto::ProduzirObjeto(Glib::RefPtr<NovoObjeto2D> novoObjeto2D) {
  this->novoObjeto2D = novoObjeto2D;
}

// Cria o objeto gráfico
void ProduzirObjeto::definirObjeto(Tipo tipoObjeto) {
  novoObjeto2D->getPainelPontos()->coletarCoordenadas();
  std::string nome = novoObjeto2D->getNomeObjeto();
  Gdk::RGBA contorno = novoObjeto2D->getCorContorno();
  Gdk::RGBA preenchimento = novoObjeto2D->getCorPreenchimento();
  switch (tipoObjeto) {
    case Tipo::RETA:
      tipo = "Reta";
      objeto = Reta();
    break;
    case Tipo::CURVA_BEZIER:
      tipo = "Curva Bézier";
      objeto = CurvaBezier();
    break;
    case Tipo::QUADRADO:
      tipo = "Quadrado";
      objeto = Quadrado();
    break;
    case Tipo::CIRCULO:
      tipo = "Círculo";
      objeto = Circulo();
    break;
    case Tipo::TRIANGULO:
      tipo = "Triângulo";
      objeto = Triangulo();
    break;
    case Tipo::RETANGULO:
      tipo = "Retângulo";
      objeto = Retangulo();
    break;
    case Tipo::POLIGONO:
      tipo = "Polígono";
      objeto = Poligono();
    break;
  }
  objeto.setNome(nome);
  objeto.setLarguraBorda(std::stod(novoObjeto2D->getEspessuraContorno()));
  objeto.setContorno(contorno);
  objeto.setPreenchimento(preenchimento);
  if (tipoObjeto == Tipo::QUADRADO || tipoObjeto == Tipo::RETANGULO)
    ProduzirObjeto::definirPontosQuadradoRetangulo(tipoObjeto);
  else ProduzirObjeto::definirPontos();
}

// Atribui os pontos de formação ao objeto (exceto quadrado e retângulo)
void ProduzirObjeto::definirPontos() {
  std::vector<Ponto> pontos;
  for (int i = 0; i < novoObjeto2D->getPainelPontos()->getCoordenadas().size(); i += 2) {
    double X = std::stod(novoObjeto2D->getPainelPontos()->getCoordenadas()[i]);
    double Y = std::stod(novoObjeto2D->getPainelPontos()->getCoordenadas()[i+1]);
    Ponto ponto = Ponto{X, Y};
    objeto.addPonto(ponto);
  }
}

// Atribui os pontos de formação ao  quadrado e ao retângulo
void ProduzirObjeto::definirPontosQuadradoRetangulo(Tipo tipoObjeto) {
  double X1 = std::stod(novoObjeto2D->getPainelPontos()->getCoordenadas()[0]);
  double Y1 = std::stod(novoObjeto2D->getPainelPontos()->getCoordenadas()[1]);
  double X2;
  double Y2;
  if (tipoObjeto == Tipo::QUADRADO) {
    double lado = std::stod(novoObjeto2D->getPainelPontos()->getCoordenadas()[2]);
    X2 = X1 + lado;
    Y2 = Y1 + lado;
  } else {
    X2 = std::stod(novoObjeto2D->getPainelPontos()->getCoordenadas()[2]);
    Y2 = std::stod(novoObjeto2D->getPainelPontos()->getCoordenadas()[3]);
  }
  objeto.addPonto(Ponto{X1, Y1});
  objeto.addPonto(Ponto{X1, Y2});
  objeto.addPonto(Ponto{X2, Y2});
  objeto.addPonto(Ponto{X2, Y1});
}

// Retorna o objeto produzido
Objeto ProduzirObjeto::getObjeto() {
  return objeto;
}

// Retorna a string literal do tipo do objeto
std::string ProduzirObjeto::getTipo() {
  return tipo;
}
