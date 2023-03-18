#ifndef RETA_H
#define RETA_H

#include <iostream>
#include "objeto2D.h"

class Reta : public Objeto2D {
private:

public:
  Reta() = default;
  ~Reta() = default;
  void addPonto(float X, float Y) override;
  void setTamanhoBorda(unsigned int tamanho);
  void setCorBorda(unsigned int R, unsigned int G, unsigned int B, float A = 1.0);
  void setCorFundo(unsigned int R, unsigned int G, unsigned int B, float A = 1.0);
  void renderizar(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
