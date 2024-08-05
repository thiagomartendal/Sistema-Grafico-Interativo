#include "rotacaoWindow.h"

RotacaoWindow::RotacaoWindow() : Gtk::Frame("Rotacionar Window") {
  RotacaoWindow::definirComponente();
  RotacaoWindow::painel();
}

void RotacaoWindow::definirComponente() {
  componente.rotacionarWindow = Gtk::Button("Rotacionar");
  componente.anguloWindow.set_placeholder_text("Em graus");
}

void RotacaoWindow::painel() {
  Gtk::Label tituloAngulo = Gtk::Label("Ângulo: ");
  Gtk::Box painel = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box boxAngulo = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box boxRotacionar = Gtk::Box(Gtk::Orientation::HORIZONTAL);

  boxAngulo.set_margin_top(5);
  boxAngulo.set_margin_start(5);
  boxAngulo.set_margin_end(5);
  boxAngulo.set_margin_bottom(5);
  boxAngulo.set_halign(Gtk::Align::CENTER);
  boxRotacionar.set_margin_bottom(5);
  boxRotacionar.set_halign(Gtk::Align::CENTER);

  componente.rotacionarWindow = Gtk::Button("Rotacionar");
  componente.anguloWindow.set_placeholder_text("Em graus");

  boxAngulo.append(tituloAngulo);
  boxAngulo.append(componente.anguloWindow);
  boxRotacionar.append(componente.rotacionarWindow);
  painel.append(boxAngulo);
  painel.append(boxRotacionar);

  set_child(painel);
  set_margin_top(5);
  set_margin_start(7);
  set_margin_end(7);
}

ComponenteRotacaoWindow& RotacaoWindow::getComponente() {
  return componente;
}
