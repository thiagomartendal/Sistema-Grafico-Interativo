#include "itemMenu.h"

ItemMenu::ItemMenu() {
  ItemMenu::arquivo();
  ItemMenu::ferramentas();
}

ItemMenu::~ItemMenu() {
  delete sair;
  delete selecao;
  delete linha;
}

void ItemMenu::arquivo() {
  sair = new Gtk::MenuItem("Sair");
}

void ItemMenu::ferramentas() {
  selecao = new Gtk::MenuItem("Seleção");
  linha = new Gtk::MenuItem("Linha");
}

Gtk::MenuItem *ItemMenu::getSair() {
  return sair;
}

Gtk::MenuItem *ItemMenu::getSelecao() {
  return selecao;
}

Gtk::MenuItem *ItemMenu::getLinha() {
  return linha;
}
