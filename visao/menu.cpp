#include "menu.h"

Menu::Menu() {
  Menu::arquivo();
  Menu::ferramentas();
}

void Menu::arquivo() {
  std::unique_ptr<Gtk::MenuItem> arq(new Gtk::MenuItem("Arquivo"));
  std::unique_ptr<Gtk::Menu> menuArquivo(new Gtk::Menu());
  arq->set_submenu(*menuArquivo);
  menuArquivo->append(*ItemMenu::inst()->getSair());
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
  menuFerramentas->append(*ItemMenu::inst()->getSelecao());
  menuFerramentas->append(*des.release());
  submenuDesenhar->append(*ItemMenu::inst()->getLinha());
  menuFerramentas.release();
  submenuDesenhar.release();
  append(*frr.release());
}
