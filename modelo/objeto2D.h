#ifndef OBJETO2D_H
#define OBJETO2D_H

#include <vector>
#include <cairomm/cairomm.h>
#include "cor.h"
#include "ponto.h"

class Objeto2D {
private:
  std::vector<Ponto> pontos;
  unsigned int tamanhoBorda;
  Cor corBorda;
  Cor corFundo;

public:
  Objeto2D() = default;
  ~Objeto2D() = default;
  virtual void addPonto(float X, float Y);
  void setTamanhoBorda(unsigned int tamanho);
  void setCorBorda(unsigned int R, unsigned int G, unsigned int B, float A = 1.0);
  void setCorFundo(unsigned int R, unsigned int G, unsigned int B, float A = 1.0);
  std::vector<Ponto>& getPontos();
  unsigned int getTamanhoBorda();
  Cor getCorBorda();
  Cor getCorFundo();
  virtual void renderizar(const Cairo::RefPtr<Cairo::Context>& cr);
};

#endif
