#ifndef ROTACAO_WINDOW_H
#define ROTACAO_WINDOW_H

#include <gtkmm.h>

struct ComponenteRotacaoWindow {
  Gtk::Entry anguloWindow;
  Gtk::Button rotacionarWindow;
};

class RotacaoWindow : public Gtk::Frame {
private:
  ComponenteRotacaoWindow componente;
  void definirComponente();
  void painel();

public:
  RotacaoWindow();
  ComponenteRotacaoWindow& getComponente();
};

#endif
