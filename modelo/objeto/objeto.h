#ifndef OBJETO_H
#define OBJETO_H

#include <vector>
#include <gdkmm.h>
#include "ponto.h"

enum Tipo {
  RETA,
  CURVA_BEZIER,
  QUADRADO,
  CIRCULO,
  TRIANGULO,
  RETANGULO,
  POLIGONO
};

class Objeto {
protected:
  std::string nome;
  std::vector<Ponto> pontos, pontosTransformados;
  Gdk::RGBA contorno, preenchimento;
  double larguraBorda;
  Tipo tipo;

public:
  Objeto();
  void setNome(std::string nome);
  void addPonto(Ponto ponto);
  void addPontoTransformado(Ponto pontoTransformado);
  void setLarguraBorda(double larguraBorda);
  void setContorno(Gdk::RGBA cor);
  void setPreenchimento(Gdk::RGBA cor);
  void limparPontosTransformados();
  virtual void renderizar(const Cairo::RefPtr<Cairo::Context>& cr);
  std::string getNome();
  std::vector<Ponto>& getPontos();
  double getLarguraBorda();
  Gdk::RGBA getContorno();
  Gdk::RGBA getPreenchimento();
  Tipo getTipo();
  Ponto centro();
};

#endif
