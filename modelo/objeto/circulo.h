#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include "objeto.h"

class Circulo : public Objeto {
public:
  Circulo();
  void renderizar(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
