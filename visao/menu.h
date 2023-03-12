#ifndef MENU_H
#define MENU_H

#include <gtkmm.h>
#include "itemMenu.h"

class Menu : public Gtk::MenuBar {
private:
  ItemMenu *itemMenu;
  void arquivo();
  void ferramentas();

public:
  Menu();
  ~Menu();
  ItemMenu *getItemMenu();
};

#endif
