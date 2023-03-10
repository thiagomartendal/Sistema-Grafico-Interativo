#include "itemMenu.h"

ItemMenu *ItemMenu::itemMenu = 0;

ItemMenu::ItemMenu() {
  ItemMenu::arquivo();
}

ItemMenu::~ItemMenu() {
  delete itemMenu;
  delete sair;
}

ItemMenu *ItemMenu::inst() {
  if (itemMenu == 0) {
    itemMenu = new ItemMenu();
  }
  return itemMenu;
}

void ItemMenu::arquivo() {
  sair = new Gtk::MenuItem("Sair");
}

Gtk::MenuItem *ItemMenu::getSair() {
  return sair;
}
