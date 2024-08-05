#include "painelPoligono.h"

PainelPoligono::PainelPoligono() {
  entrada = Gtk::TextView();
  PainelPoligono::propriedades();
  PainelPoligono::definicao();
}

void PainelPoligono::propriedades() {
  set_margin_top(5);
  set_margin_start(5);
  set_margin_end(5);
  set_margin_bottom(5);
}

void PainelPoligono::definicao() {
  Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL);

  Gtk::Frame fr = Gtk::Frame();
  Gtk::Label titulo = Gtk::Label("Digite as coordenadas separadas por espaço (a cada 2 coordenadas tem-se 1 ponto): ");
  titulo.set_margin_bottom(5);
  entrada.set_size_request(-1, 200);
  fr.set_child(entrada);

  box.append(titulo);
  box.append(fr);
  box.set_halign(Gtk::Align::CENTER);

  append(box);
}

void PainelPoligono::coletarCoordenadas() {
  coordenadas.clear();
  std::string textoEntrada = entrada.get_buffer()->get_text();
  std::stringstream quebra(textoEntrada);
  std::string coordenada;
  int cont = 0;
  while (quebra >> coordenada) {
    coordenadas.push_back(coordenada);
    cont++;
  }
  if (cont % 2 != 0) coordenadas.push_back("0.0");
}
