#include "painel.h"

Painel::Painel() : Gtk::Box(Gtk::Orientation::VERTICAL) {

}

void Painel::coletarCoordenadas() {

}

std::vector<std::string> Painel::getCoordenadas() {
  return coordenadas;
}
