#include "painelPontoDuplo.h"

PainelPontoDuplo::PainelPontoDuplo() : Painel() {
  entrada1 = Entrada();
  entrada2 = Entrada();
  PainelPontoDuplo::propriedades();
  PainelPontoDuplo::definicao();
}

void PainelPontoDuplo::propriedades() {
  set_margin_top(5);
  set_margin_start(5);
  set_margin_end(5);
  set_margin_bottom(5);
}

void PainelPontoDuplo::definicao() {
  Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box linha1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box linha2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna1_1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna2_1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna1_2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna2_2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);

  Gtk::Label tituloPonto1 = Gtk::Label("Ponto de Origem: ");
  Gtk::Label tituloPonto2 = Gtk::Label("Ponto de Destino: ");
  Gtk::Label tituloX1 = Gtk::Label("X1 = ");
  Gtk::Label tituloY1 = Gtk::Label("Y1 = ");
  Gtk::Label tituloX2 = Gtk::Label("X2 = ");
  Gtk::Label tituloY2 = Gtk::Label("Y2 = ");

  coluna1_1.append(tituloX1);
  coluna1_1.append(entrada1.getX());
  coluna1_1.set_margin_start(5);
  coluna1_1.set_margin_end(5);

  coluna2_1.append(tituloY1);
  coluna2_1.append(entrada1.getY());
  coluna2_1.set_margin_start(5);
  coluna2_1.set_margin_end(5);

  coluna1_2.append(tituloX2);
  coluna1_2.append(entrada2.getX());
  coluna1_2.set_margin_start(5);
  coluna1_2.set_margin_end(5);

  coluna2_2.append(tituloY2);
  coluna2_2.append(entrada2.getY());
  coluna2_2.set_margin_start(5);
  coluna2_2.set_margin_end(5);

  linha1.append(tituloPonto1);
  linha1.append(coluna1_1);
  linha1.append(coluna2_1);
  linha1.set_halign(Gtk::Align::CENTER);

  linha2.append(tituloPonto2);
  linha2.append(coluna1_2);
  linha2.append(coluna2_2);
  linha2.set_margin_top(5);
  linha2.set_halign(Gtk::Align::CENTER);

  box.append(linha1);
  box.append(linha2);
  box.set_halign(Gtk::Align::CENTER);

  append(box);
}

void PainelPontoDuplo::coletarCoordenadas() {
  coordenadas.clear();
  std::string X1 = entrada1.getX().get_text();
  std::string Y1 = entrada1.getY().get_text();
  std::string X2 = entrada2.getX().get_text();
  std::string Y2 = entrada2.getY().get_text();
  if (X1 == "") X1 = "0.0";
  if (Y1 == "") Y1 = "0.0";
  if (X2 == "") X2 = "0.0";
  if (Y2 == "") Y2 = "0.0";
  coordenadas.push_back(X1);
  coordenadas.push_back(Y1);
  coordenadas.push_back(X2);
  coordenadas.push_back(Y2);
}
