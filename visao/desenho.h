#ifndef DESENHO_H
#define DESENHO_H

#include <gtkmm.h>

class Desenho : public Gtk::DrawingArea {
private:
  int largura{800};
  int altura{600};
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
  void planoDeFundo(const Cairo::RefPtr<Cairo::Context>& cr);

public:
  Desenho();
  void dimensoes(int largura, int altura);
};

#endif
