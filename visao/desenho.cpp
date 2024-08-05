#include "desenho.h"

Desenho::Desenho(int largura, int altura) {
  this->largura = largura;
  this->altura = altura;
  set_size_request(largura, altura);
}

void Desenho::tela(const Cairo::RefPtr<Cairo::Context>& cr) {
  Gdk::RGBA fundo = Gdk::RGBA();
  fundo.set_rgba(1.0, 1.0, 1.0, 1.0);
  cr->rectangle(0.0, 0.0, largura, altura);
  Gdk::Cairo::set_source_rgba(cr, fundo);
  cr->fill();
}

int Desenho::getLargura() {
  return largura;
}

int Desenho::getAltura() {
  return altura;
}
