#ifndef RETANGULO_H
#define RETANGULO_H

#include "objeto.h"

class Retangulo : public Objeto {
public:
  Retangulo();
  void renderizar(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
