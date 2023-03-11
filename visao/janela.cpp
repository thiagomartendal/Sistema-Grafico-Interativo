#include "janela.h"

Janela::Janela() {
  Janela::propriedades();
  Janela::layout();
  Janela::acoesMenu();
  show_all_children();
}

Janela::~Janela() {

}

void Janela::propriedades() {
  set_title("Janela");
  set_default_size(1200, 800);
  // layout->pack_start(menu, false, false, 0);
  // layout.pack_start(layoutPainel, true, true, 0);
}

void Janela::layout() {
  std::unique_ptr<Gtk::VBox> layout(new Gtk::VBox());
  Janela::menu(layout);
  Janela::painelCentral(layout);
  add(*layout);
  layout.release();
}

void Janela::menu(std::unique_ptr<Gtk::VBox> &layout) {
  std::unique_ptr<Menu> menu(new Menu());
  layout->pack_start(*menu, false, false, 0);
  menu.release();
}

void Janela::acoesMenu() {
  Janela::sair();
}

void Janela::sair() {
  ItemMenu::inst()->getSair()->signal_activate().connect(sigc::mem_fun(this, &Janela::close));
}

void Janela::painelCentral(std::unique_ptr<Gtk::VBox> &layout) {
  std::unique_ptr<Gtk::HBox> layoutPainel(new Gtk::HBox());
  layout->pack_start(*layoutPainel, true, true, 0);
  Janela::painelDeObjetos(layoutPainel);
  Janela::areaViewport(layoutPainel);
  layoutPainel.release();
}

void Janela::painelDeObjetos(std::unique_ptr<Gtk::HBox> &layoutPainel) {
  std::unique_ptr<Gtk::Frame> painelObjetos(new Gtk::Frame());
  painelObjetos->set_label("Objetos");
  painelObjetos->set_size_request(300, -1);
  layoutPainel->pack_start(*painelObjetos.release(), false, false, 2);
}

void Janela::areaViewport(std::unique_ptr<Gtk::HBox> &layoutPainel) {
  std::unique_ptr<Gtk::ScrolledWindow> painelViewport(new Gtk::ScrolledWindow());
  std::unique_ptr<Gtk::HBox> layoutPainelViewport(new Gtk::HBox());
  layoutPainelViewport->set_halign(Gtk::ALIGN_CENTER);
  layoutPainelViewport->set_valign(Gtk::ALIGN_CENTER);
  layoutPainelViewport->pack_start(viewport, false, false, 0); // Área de Viewport
  painelViewport->add(*layoutPainelViewport.release());
  layoutPainel->pack_start(*painelViewport.release(), true, true, 0);
}
