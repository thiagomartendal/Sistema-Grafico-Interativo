#ifndef ESTRUTURA_DIMENSAO_H
#define ESTRUTURA_DIMENSAO_H

#include "objeto/ponto.h"

struct Dimensao {
  double largura, altura;
  Ponto P1; // {X1, Y1}
  Ponto P2; // {X1, Y2}
  Ponto P3; // {X2, Y2}
  Ponto P4; // {X2, Y1}
  Ponto centro;
};

class EstruturaDimensao {
private:
  Dimensao window, vieport;

public:
  EstruturaDimensao() = default;
  void definir(double largura, double altura);
  Dimensao& getWindow();
  Dimensao& getVieport();
};

#endif
