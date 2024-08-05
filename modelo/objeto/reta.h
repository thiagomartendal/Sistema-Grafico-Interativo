#ifndef RETA_H
#define RETA_H

#include "objeto.h"

class Reta : public Objeto {
public:
  Reta();
  void renderizar(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
