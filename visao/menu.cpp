#include "menu.h"

Menu::Menu() {
  Menu::arquivo();
}

void Menu::arquivo() {
  std::unique_ptr<Gtk::MenuItem> arq(new Gtk::MenuItem("Arquivo"));
  std::unique_ptr<Gtk::Menu> menuArquivo(new Gtk::Menu());
  arq->set_submenu(*menuArquivo);
  menuArquivo->append(*ItemMenu::inst()->getSair());
  menuArquivo.release();
  append(*arq.release());
}
