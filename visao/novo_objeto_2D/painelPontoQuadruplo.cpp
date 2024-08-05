#include "painelPontoQuadruplo.h"

PainelPontoQuadruplo::PainelPontoQuadruplo() {
  entrada1 = Entrada();
  entrada2 = Entrada();
  entrada3 = Entrada();
  PainelPontoQuadruplo::propriedades();
  PainelPontoQuadruplo::definicao();
}

void PainelPontoQuadruplo::propriedades() {
  set_margin_top(5);
  set_margin_start(5);
  set_margin_end(5);
  set_margin_bottom(5);
}

void PainelPontoQuadruplo::definicao() {
  Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box linha1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box linha2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box linha3 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box linha4 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna1_1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna2_1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna1_2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna2_2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna1_3 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna2_3 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna1_4 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box coluna2_4 = Gtk::Box(Gtk::Orientation::HORIZONTAL);

  Gtk::Label tituloPonto1 = Gtk::Label("Ponto de Formação 1: ");
  Gtk::Label tituloPonto2 = Gtk::Label("Ponto de Formação 2: ");
  Gtk::Label tituloPonto3 = Gtk::Label("Ponto de Controle 1: ");
  Gtk::Label tituloPonto4 = Gtk::Label("Ponto de Controle 2: ");
  Gtk::Label tituloX1 = Gtk::Label("X1 = ");
  Gtk::Label tituloY1 = Gtk::Label("Y1 = ");
  Gtk::Label tituloX2 = Gtk::Label("X2 = ");
  Gtk::Label tituloY2 = Gtk::Label("Y2 = ");
  Gtk::Label tituloX3 = Gtk::Label("X3 = ");
  Gtk::Label tituloY3 = Gtk::Label("Y3 = ");
  Gtk::Label tituloX4 = Gtk::Label("X4 = ");
  Gtk::Label tituloY4 = Gtk::Label("Y4 = ");

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

  coluna1_3.append(tituloX3);
  coluna1_3.append(entrada3.getX());
  coluna1_3.set_margin_start(5);
  coluna1_3.set_margin_end(5);

  coluna2_3.append(tituloY3);
  coluna2_3.append(entrada3.getY());
  coluna2_3.set_margin_start(5);
  coluna2_3.set_margin_end(5);

  coluna1_4.append(tituloX4);
  coluna1_4.append(entrada4.getX());
  coluna1_4.set_margin_start(5);
  coluna1_4.set_margin_end(5);

  coluna2_4.append(tituloY4);
  coluna2_4.append(entrada4.getY());
  coluna2_4.set_margin_start(5);
  coluna2_4.set_margin_end(5);

  linha1.append(tituloPonto1);
  linha1.append(coluna1_1);
  linha1.append(coluna2_1);
  linha1.set_halign(Gtk::Align::CENTER);

  linha2.append(tituloPonto2);
  linha2.append(coluna1_2);
  linha2.append(coluna2_2);
  linha2.set_margin_top(5);
  linha2.set_halign(Gtk::Align::CENTER);

  linha3.append(tituloPonto3);
  linha3.append(coluna1_3);
  linha3.append(coluna2_3);
  linha3.set_margin_top(5);
  linha3.set_halign(Gtk::Align::CENTER);

  linha4.append(tituloPonto4);
  linha4.append(coluna1_4);
  linha4.append(coluna2_4);
  linha4.set_margin_top(5);
  linha4.set_halign(Gtk::Align::CENTER);

  box.append(linha1);
  box.append(linha2);
  box.append(linha3);
  box.append(linha4);
  box.set_halign(Gtk::Align::CENTER);

  append(box);
}

void PainelPontoQuadruplo::coletarCoordenadas() {
  coordenadas.clear();
  std::string X1 = entrada1.getX().get_text();
  std::string Y1 = entrada1.getY().get_text();
  std::string X2 = entrada2.getX().get_text();
  std::string Y2 = entrada2.getY().get_text();
  std::string X3 = entrada3.getX().get_text();
  std::string Y3 = entrada3.getY().get_text();
  std::string X4 = entrada3.getX().get_text();
  std::string Y4 = entrada3.getY().get_text();
  if (X1 == "") X1 = "0.0";
  if (Y1 == "") Y1 = "0.0";
  if (X2 == "") X2 = "0.0";
  if (Y2 == "") Y2 = "0.0";
  if (X3 == "") X3 = "0.0";
  if (Y3 == "") Y3 = "0.0";
  if (X4 == "") X4 = "0.0";
  if (Y4 == "") Y4 = "0.0";
  coordenadas.push_back(X1);
  coordenadas.push_back(Y1);
  coordenadas.push_back(X2);
  coordenadas.push_back(Y2);
  coordenadas.push_back(X3);
  coordenadas.push_back(Y3);
  coordenadas.push_back(X4);
  coordenadas.push_back(Y4);
}
