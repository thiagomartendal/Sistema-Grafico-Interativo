#ifndef VIEWPORT_H
#define VIEWPORT_H

// #include <iostream>
#include <gtkmm.h>

class Viewport : public Gtk::DrawingArea {
private:
  int largura{800};
  int altura{600};
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
  void planoDeFundo(const Cairo::RefPtr<Cairo::Context>& cr);
  bool arraste(GdkEventMotion *evt);

public:
  Viewport();
  void dimensoes(int largura, int altura);
};

#endif
