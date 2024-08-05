#ifndef ZOOM_H
#define ZOOM_H

#include <gtkmm.h>

struct ComponenteZoom {
  Gtk::Button zoomMenos;
  Gtk::Button redefinirZoom;
  Gtk::Button zoomMais;
  Gtk::Entry fatorZoom;
};

class Zoom : public Gtk::Frame {
private:
  ComponenteZoom componente;
  void definirComponente();
  void painel();

public:
  Zoom();
  ComponenteZoom& getComponente();
};

#endif
