#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "objeto.h"

class Triangulo : public Objeto {
public:
  Triangulo();
  void renderizar(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
