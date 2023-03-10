#ifndef ITEM_MENU_H
#define ITEM_MENU_H

#include <gtkmm.h>

class ItemMenu {
private:
  static ItemMenu *itemMenu;
  Gtk::MenuItem *sair;
  ItemMenu();
  void arquivo();

public:
  ~ItemMenu();
  static ItemMenu *inst();
  Gtk::MenuItem *getSair();
};

#endif
