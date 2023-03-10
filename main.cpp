#include <iostream>
#include <gtkmm.h>
#include "./controle/controle.h"

int main(int argc, char *argv[]) {
  Gtk::Main m(argc, argv);
  Controle ctrl = Controle();
  Gtk::Main::run(*ctrl.janela());
  return 0;
}
