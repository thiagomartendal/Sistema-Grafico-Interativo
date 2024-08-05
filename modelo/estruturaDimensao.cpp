#include "estruturaDimensao.h"

/*
 * As dimensões ideais para a window devem ser n vezes maiores ou menores que as
 * dimensões da viewport, ou iguais as da viewport. Dimensões de window fora destas
 * configurações geram transformações incorretas nos objetos, devido o
 * desbalanceamento entre as duas estruturas. Após definir as dimensões das
 * estruturas, deve-se definir as coordenadas de acordo com as dimensões.
 * Exemplos de dimensões ideais:
 * window = {vieport.largura * n, vieport.altura * n}
 * window = {vieport.largura / n, vieport.altura / n}
 * window = {vieport.largura, vieport.altura}
 */

// Define as estruturras da window e da viewport
void EstruturaDimensao::definir(double largura, double altura) {
  double meiaLargura = largura / 2.0;
  double meiaAltura = altura / 2.0;
  double X1 = -1.0 * meiaLargura;
  double Y1 = -1.0 * meiaAltura;
  double X2 = meiaLargura;
  double Y2 = meiaAltura;
  vieport = {largura, altura, Ponto{X1, Y1}, Ponto{X1, Y2}, Ponto{X2, Y2}, Ponto{X2, Y1}, Ponto{0.0, 0.0}};
  window = {largura, altura, Ponto{X1, Y1}, Ponto{X1, Y2}, Ponto{X2, Y2}, Ponto{X2, Y1}, Ponto{0.0, 0.0}};
}

// Retorna a window
Dimensao& EstruturaDimensao::getWindow() {
  return window;
}

// Retorna a viewport
Dimensao& EstruturaDimensao::getVieport() {
  return vieport;
}
