#ifndef ROTACAO_H
#define ROTACAO_H

#include <gtkmm.h>

struct ComponenteRotacao {
  Gtk::Entry angulo;
  Gtk::CheckButton centroMundo;
  Gtk::CheckButton centroObjeto;
  Gtk::CheckButton pontoQualquer;
  Gtk::Button rotacionar;
  Gtk::Entry X;
  Gtk::Entry Y;
  Gtk::Entry Z;
  Gtk::Box boxPontoArbitrario;
  std::string tipoRotacao{"objeto"};
};

class Rotacao : public Gtk::Frame {
private:
  ComponenteRotacao componente;
  void definirComponente();
  void painel();

public:
  Rotacao();
  ComponenteRotacao& getComponente();
};

#endif
