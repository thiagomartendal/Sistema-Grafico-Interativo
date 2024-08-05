#ifndef TRANSFORMACAO_H
#define TRANSFORMACAO_H

#include <iostream>
#include <vector>
#include <cmath>
#include "objeto/ponto.h"
#include "estruturaDimensao.h"

enum Direcao {
  CIMA,
  CIMA_ESQUERDA,
  CIMA_DIREITA,
  ESQUERDA,
  DIREITA,
  BAIXO,
  BAIXO_ESQUERDA,
  BAIXO_DIREITA,
  CENTRO
};

class Transformacao {
private:
  int fatorZoom{100};
  double anguloWindow{0.0};
  std::vector<std::vector<double>> multiplicarMatriz(
   std::vector<std::vector<double>> m1, std::vector<std::vector<double>> m2);
  std::vector<std::vector<double>> matrizAuxiliar(double distanciaX, double distanciaY, std::vector<std::vector<double>> auxiliar);
  Ponto viewportTradicional(Ponto ponto, Dimensao vieport, Dimensao window);
  Ponto viewportPorEscalonamento(Ponto ponto, Dimensao vieport, Dimensao window);
  Ponto viewportNormal(Ponto ponto, Dimensao vieport, Dimensao window);
  void fatorarAngulo(double& angulo);

public:
  Transformacao() = default;
  Ponto viewport(Ponto ponto, Dimensao vieport, Dimensao window);
  Ponto normalizar(double angulo, Dimensao window, Ponto ponto);
  void addAnguloWindow(double angulo);
  void zoom(EstruturaDimensao& dimensao, char tipoZoom);
  void moverWindow(EstruturaDimensao& dimensao, double fator, Direcao direcao);
  void translacao2D(double distanciaX, double distanciaY, std::vector<Ponto>& pontos);
  void escala2D(double escalaX, double escalaY, Ponto pontoEscala, std::vector<Ponto>& pontos);
  void rotacao2D(double angulo, Ponto pontoRotacao, std::vector<Ponto>& pontos);
  int getFatorZoom();
  double getAnguloWindow();
};

#endif
