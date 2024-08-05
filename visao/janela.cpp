#include "janela.h"

Janela::Janela() {
  Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL);
  Janela::propriedades(box);
  Janela::barraMenu(box);
  Janela::painelCentral(box);
}

Janela::~Janela() {
  delete painel;
  delete desenho;
}

void Janela::propriedades(Gtk::Box& box) {
  set_title("Janela");
  set_default_size(1400, 800);
  set_child(box);
}

void Janela::barraMenu(Gtk::Box& box) {
  Menu menu;
  box.append(*menu.get());
}

void Janela::painelCentral(Gtk::Box& box) {
  Gtk::Box central = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Janela::painelLateral(central);
  Janela::areaDesenho(central);
  box.append(central);
}

void Janela::painelLateral(Gtk::Box& central) {
  painel = new PainelLateral();
  central.append(*painel);
}

void Janela::areaDesenho(Gtk::Box& central) {
  Gtk::Frame base = Gtk::Frame();
  Gtk::Frame contorno = Gtk::Frame();
  Gtk::ScrolledWindow scroll = Gtk::ScrolledWindow();
  Gtk::Viewport vwp = Gtk::Viewport(NULL, NULL);
  desenho = new Desenho(1000, 600);
  contorno.set_child(*desenho);
  contorno.set_valign(Gtk::Align::CENTER);
  contorno.set_halign(Gtk::Align::CENTER);
  base.set_child(contorno);
  base.set_expand();
  vwp.set_child(base);
  vwp.set_expand();
  scroll.set_child(vwp);
  central.append(scroll);
}

void Janela::sair() {
  hide();
}

void Janela::mensagem(std::string mensagem) {
  std::unique_ptr<Gtk::MessageDialog> msg = std::unique_ptr<Gtk::MessageDialog>(new Gtk::MessageDialog(*this, mensagem, false, Gtk::MessageType::WARNING));
  msg->set_modal(true);
  msg->signal_response().connect(sigc::hide(sigc::mem_fun(*msg, &Gtk::Widget::hide)));
  msg->show();
  msg.release();
}

PainelLateral* Janela::getPainel() {
  return painel;
}

Desenho* Janela::getDesenho() {
  return desenho;
}
