#ifndef OBJETO_H
#define OBJETO_H

#include <vector>
#include "cor.h"
#include "coordenada.h"

class Objeto2D {
private:
  std::vector<Coordenada> pontos;
  Cor corBorda;
  Cor corFundo;

public:
  Objeto2D() = default;
  void addPonto(float X, float Y);
  void setCorBorda(float R, float G, float B, float A = 1.0);
  void setCorFundo(float R, float G, float B, float A = 1.0);
};

#endif
