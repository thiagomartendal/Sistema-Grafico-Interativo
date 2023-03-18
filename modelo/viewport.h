#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <iostream>
#include <gtkmm.h>
#include "listaObjeto.h"
#include "ferramenta.h"

class Viewport : public Gtk::DrawingArea {
private:
  int largura{800};
  int altura{600};
  Ferramenta ferramenta{Ferramenta::SELECAO};
  ListaObjeto lista;
  Objeto2D *objeto{new Objeto2D()};
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
  bool clique(GdkEventButton *evt);
  void planoDeFundo(const Cairo::RefPtr<Cairo::Context>& cr);
  bool arraste(GdkEventMotion *evt);
  bool soltarClique(GdkEventButton *evt);

public:
  Viewport();
  ~Viewport();
  void dimensoes(int largura, int altura);
  void setFerramenta(Ferramenta ferramenta);
  ListaObjeto getLista();
};

#endif
