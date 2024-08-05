#ifndef CURVA_BEZIER_H
#define CURVA_BEZIER_H

#include "objeto.h"

class CurvaBezier : public Objeto {
public:
  CurvaBezier();
  void renderizar(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
