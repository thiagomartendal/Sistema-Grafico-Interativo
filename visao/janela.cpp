#include "janela.h"

Janela::Janela() {
  Janela::propriedades();
}

Janela::~Janela() {

}

void Janela::propriedades() {
  set_title("Janela");
  set_icon_from_file("img/icone.png");
  set_default_size(1200, 800);
}

void Janela::layoutPrincipal(Menu *menu) {
  std::unique_ptr<Gtk::VBox> layout(new Gtk::VBox());
  layout->pack_start(*menu, false, false, 0);
  Janela::painelCentral(layout);
  add(*layout);
  layout.release();
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
  painelObjetos->set_label_align(0.05);
  painelObjetos->set_size_request(300, -1);
  layoutPainel->pack_start(*painelObjetos.release(), false, false, 2);
}

void Janela::areaViewport(std::unique_ptr<Gtk::HBox> &layoutPainel) {
  std::unique_ptr<Gtk::ScrolledWindow> painelViewport(new Gtk::ScrolledWindow());
  std::unique_ptr<Gtk::HBox> layoutPainelViewport(new Gtk::HBox());
  layoutPainelViewport->set_halign(Gtk::ALIGN_CENTER);
  layoutPainelViewport->set_valign(Gtk::ALIGN_CENTER);
  layoutPainelViewport->pack_start(alinhamento, false, false, 0);
  painelViewport->add(*layoutPainelViewport.release());
  layoutPainel->pack_start(*painelViewport.release(), true, true, 0);
}

Gtk::Alignment& Janela::getAlinhamento() {
  return alinhamento;
}
