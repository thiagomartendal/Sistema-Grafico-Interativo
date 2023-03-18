#ifndef ACAO_VIEWPORT_H
#define ACAO_VIEWPORT_H

#include <iostream>
#include <vector>
#include <gtkmm.h>
#include "../modelo/objeto2D.h"
#include "../modelo/reta.h"
#include "../visao/viewport.h"

class AcaoViewport {
private:
  std::vector<Objeto2D*> objetos;
  Viewport *viewport;
  Reta *reta;
  std::vector<float> p;
  float x;
  bool desenhar(const Cairo::RefPtr<Cairo::Context>& cr);
  bool clique(GdkEventButton *evt);
  bool arraste(GdkEventMotion *evt);
  bool soltarClique(GdkEventButton *evt);

public:
  AcaoViewport(Viewport *viewport, std::vector<Objeto2D*> &objetos);
  ~AcaoViewport();
};

#endif
