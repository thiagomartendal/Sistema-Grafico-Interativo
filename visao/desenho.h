#ifndef DESENHO_H
#define DESENHO_H

#include <gtkmm.h>

class Desenho : public Gtk::DrawingArea {
private:
  int largura, altura;

public:
  Desenho(int largura, int altura);
  void tela(const Cairo::RefPtr<Cairo::Context>& cr);
  int getLargura();
  int getAltura();
};

#endif
