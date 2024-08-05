#include "entrada.h"

Entrada::Entrada() {
  X = Gtk::Entry();
  Y = Gtk::Entry();
  Z = Gtk::Entry();
  X.set_placeholder_text("0.0");
  Y.set_placeholder_text("0.0");
  Z.set_placeholder_text("0.0");
}

Gtk::Entry& Entrada::getX() {
  return X;
}

Gtk::Entry& Entrada::getY() {
  return Y;
}

Gtk::Entry& Entrada::getZ() {
  return Z;
}
