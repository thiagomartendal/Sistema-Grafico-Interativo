#ifndef ITEM_MENU_H
#define ITEM_MENU_H

#include <gtkmm.h>

class ItemMenu {
private:
  // Arquivo
  Gtk::MenuItem *sair;
  // Ferramentas
  Gtk::MenuItem *selecao;
  Gtk::MenuItem *linha;
  void arquivo();
  void ferramentas();

public:
  ItemMenu();
  ~ItemMenu();
  Gtk::MenuItem *getSair();
  Gtk::MenuItem *getSelecao();
  Gtk::MenuItem *getLinha();
};

#endif
