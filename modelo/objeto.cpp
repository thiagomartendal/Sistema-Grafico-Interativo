#include "objeto.h"

void Objeto2D::addPonto(float X, float Y) {
  pontos.push_back(Coordenada(X, Y));
}

void Objeto2D::setCorBorda(float R, float G, float B, float A) {
  corBorda = Cor(R, G, B, A);
}

void Objeto2D::setCorFundo(float R, float G, float B, float A) {
  corFundo = Cor(R, G, B, A);
}
