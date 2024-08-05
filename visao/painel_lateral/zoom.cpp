#include "zoom.h"

Zoom::Zoom() : Gtk::Frame("Zoom") {
  Zoom::definirComponente();
  Zoom::painel();
}

void Zoom::definirComponente() {
  componente.zoomMenos = Gtk::Button("-");
  componente.redefinirZoom = Gtk::Button("Redefinir");
  componente.zoomMais = Gtk::Button("+");
  componente.fatorZoom = Gtk::Entry();
  componente.zoomMenos.set_margin_end(5);
  componente.redefinirZoom.set_margin_end(5);
  componente.fatorZoom.get_buffer()->set_text("100%");
  componente.fatorZoom.set_alignment(Gtk::Align::CENTER);
  componente.fatorZoom.set_margin_start(65);
  componente.fatorZoom.set_margin_end(65);
  componente.fatorZoom.set_editable(false);
}

void Zoom::painel() {
  Gtk::Box painel = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box painelBotoes = Gtk::Box(Gtk::Orientation::HORIZONTAL);

  painelBotoes.append(componente.zoomMenos);
  painelBotoes.append(componente.redefinirZoom);
  painelBotoes.append(componente.zoomMais);
  painelBotoes.set_halign(Gtk::Align::CENTER);
  painelBotoes.set_margin_bottom(5);

  painel.append(painelBotoes);
  painel.append(componente.fatorZoom);
  painel.set_margin_top(5);
  painel.set_margin_bottom(5);

  set_child(painel);
  set_margin_start(7);
  set_margin_end(7);
}

ComponenteZoom& Zoom::getComponente() {
  return componente;
}
