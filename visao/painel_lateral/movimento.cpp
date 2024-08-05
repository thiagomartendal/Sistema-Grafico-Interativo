#include "movimento.h"

Movimento::Movimento() : Gtk::Frame("Mover Window") {
  Movimento::definirComponente();
  Movimento::painel();
}

void Movimento::definirComponente() {
  componente.cima = Gtk::Button("↑");
  componente.cimaEsquerda = Gtk::Button("↖");
  componente.cimaDireita = Gtk::Button("↗");
  componente.direita = Gtk::Button("→");
  componente.centro = Gtk::Button("Centro");
  componente.esquerda = Gtk::Button("←");
  componente.baixoEsquerda = Gtk::Button("↙");
  componente.baixoDireita = Gtk::Button("↘");
  componente.baixo = Gtk::Button("↓");

  componente.fatorMovimento.set_margin_end(25);
  componente.fatorMovimento.get_buffer()->set_text("20.0");
  componente.fatorMovimento.set_alignment(Gtk::Align::CENTER);
  componente.fatorMovimento.set_placeholder_text("0.0");
}

void Movimento::painel() {
  Gtk::Label tituloFator = Gtk::Label("Fator: ");
  Gtk::Box painel = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box boxFatorMovimento = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Grid botoes = Gtk::Grid();

  tituloFator.set_margin_start(25);
  tituloFator.set_margin_end(5);

  botoes.set_margin_top(5);
  botoes.set_margin_start(2);
  botoes.set_margin_bottom(5);
  botoes.set_row_spacing(5);
  botoes.set_column_spacing(5);

  botoes.attach(componente.cimaEsquerda, 0, 0);
  botoes.attach(componente.cima, 1, 0);
  botoes.attach(componente.cimaDireita, 2, 0);
  botoes.attach(componente.esquerda, 0, 1);
  botoes.attach(componente.centro, 1, 1);
  botoes.attach(componente.direita, 2, 1);
  botoes.attach(componente.baixoEsquerda, 0, 2);
  botoes.attach(componente.baixo, 1, 2);
  botoes.attach(componente.baixoDireita, 2, 2);
  botoes.set_halign(Gtk::Align::CENTER);

  boxFatorMovimento.append(tituloFator);
  boxFatorMovimento.append(componente.fatorMovimento);
  boxFatorMovimento.set_margin_bottom(5);

  painel.append(botoes);
  painel.append(boxFatorMovimento);

  set_child(painel);
  set_margin_top(5);
  set_margin_start(7);
  set_margin_end(7);
}

ComponenteMovimento& Movimento::getComponente() {
  return componente;
}
