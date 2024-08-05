#include "painelPontoUnico.h"

PainelPontoUnico::PainelPontoUnico() : Painel() {
  entrada = Entrada();
  PainelPontoUnico::propriedades();
  PainelPontoUnico::definicao();
}

void PainelPontoUnico::propriedades() {
  set_margin_top(5);
  set_margin_start(5);
  set_margin_end(5);
  set_margin_bottom(5);
}

void PainelPontoUnico::definicao() {
  Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box linha1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box linha2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);

  Gtk::Label tituloPonto = Gtk::Label("Ponto de Origem: ");
  Gtk::Label tituloX = Gtk::Label("X = ");
  Gtk::Label tituloY = Gtk::Label("Y = ");
  Gtk::Label tituloLado = Gtk::Label("Lado: ");
  tituloLado.set_margin_end(5);

  lado = Gtk::Entry();
  lado.set_placeholder_text("Tamanho do lado do quadrado");

  coluna1.append(tituloX);
  coluna1.append(entrada.getX());
  coluna1.set_margin_start(5);
  coluna1.set_margin_end(5);

  coluna2.append(tituloY);
  coluna2.append(entrada.getY());
  coluna2.set_margin_start(5);
  coluna2.set_margin_end(5);

  linha1.append(tituloPonto);
  linha1.append(coluna1);
  linha1.append(coluna2);

  linha2.append(tituloLado);
  linha2.append(lado);
  linha2.set_margin_top(5);
  linha2.set_halign(Gtk::Align::CENTER);

  box.append(linha1);
  box.append(linha2);

  append(box);
}

void PainelPontoUnico::coletarCoordenadas() {
  coordenadas.clear();
  std::string X1 = entrada.getX().get_text();
  std::string Y1 = entrada.getY().get_text();
  std::string valorLado = lado.get_text();
  if (X1 == "") X1 = "0.0";
  if (Y1 == "") Y1 = "0.0";
  if (valorLado == "") valorLado = "1.0";
  coordenadas.push_back(X1);
  coordenadas.push_back(Y1);
  coordenadas.push_back(valorLado);
}
