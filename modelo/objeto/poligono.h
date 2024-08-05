#ifndef POLIGONO_H
#define POLIGONO_H

#include "objeto.h"

class Poligono : public Objeto {
public:
  Poligono();
  void renderizar(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
