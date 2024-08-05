#ifndef MENU_H
#define MENU_H

#include <string>
#include <gtkmm.h>

class Menu {
private:
  Gtk::PopoverMenuBar *barraMenu;
  std::string definicao();

public:
  Menu();
  ~Menu();
  Gtk::PopoverMenuBar* get();
};

#endif
