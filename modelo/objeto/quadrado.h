#ifndef QUADRADO_H
#define QUADRADO_H

#include "objeto.h"

class Quadrado : public Objeto {
public:
  Quadrado();
  void renderizar(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
