#ifndef ENTRADA_PONTO_H
#define ENTRADA_PONTO_H

#include <gtkmm.h>

class Entrada {
private:
  Gtk::Entry X;
  Gtk::Entry Y;
  Gtk::Entry Z;

public:
  Entrada();
  Gtk::Entry& getX();
  Gtk::Entry& getY();
  Gtk::Entry& getZ();
};

#endif
