#ifndef ITEM_MENU_H
#define ITEM_MENU_H

#include <gtkmm.h>

class ItemMenu {
private:
  static ItemMenu *itemMenu;
  // Arquivo
  Gtk::MenuItem *sair;
  // Ferramentas
  Gtk::MenuItem *selecao;
  Gtk::MenuItem *linha;
  ItemMenu();
  void arquivo();
  void ferramentas();

public:
  ~ItemMenu();
  static ItemMenu *inst();
  Gtk::MenuItem *getSair();
  Gtk::MenuItem *getSelecao();
  Gtk::MenuItem *getLinha();
};

#endif
