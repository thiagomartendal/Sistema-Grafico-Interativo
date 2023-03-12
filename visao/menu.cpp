#include "menu.h"

Menu::Menu() {
  itemMenu = new ItemMenu();
  Menu::arquivo();
  Menu::ferramentas();
}

Menu::~Menu() {
  delete itemMenu;
}

ItemMenu* Menu::getItemMenu() {
  return itemMenu;
}

void Menu::arquivo() {
  std::unique_ptr<Gtk::MenuItem> arq(new Gtk::MenuItem("Arquivo"));
  std::unique_ptr<Gtk::Menu> menuArquivo(new Gtk::Menu());
  arq->set_submenu(*menuArquivo);
  menuArquivo->append(*itemMenu->getSair());
  menuArquivo.release();
  append(*arq.release());
}

void Menu::ferramentas() {
  std::unique_ptr<Gtk::MenuItem> frr(new Gtk::MenuItem("Ferramentas"));
  std::unique_ptr<Gtk::MenuItem> des(new Gtk::MenuItem("Desenhar"));
  std::unique_ptr<Gtk::Menu> menuFerramentas(new Gtk::Menu());
  std::unique_ptr<Gtk::Menu> submenuDesenhar(new Gtk::Menu());
  frr->set_submenu(*menuFerramentas);
  des->set_submenu(*submenuDesenhar);
  menuFerramentas->append(*itemMenu->getSelecao());
  menuFerramentas->append(*des.release());
  submenuDesenhar->append(*itemMenu->getLinha());
  menuFerramentas.release();
  submenuDesenhar.release();
  append(*frr.release());
}
