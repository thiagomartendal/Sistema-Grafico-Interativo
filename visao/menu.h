#ifndef MENU_H
#define MENU_H

#include <gtkmm.h>
#include "itemMenu.h"

class Menu : public Gtk::MenuBar {
private:
  void arquivo();
  void ferramenta();

public:
  Menu();
};

#endif
