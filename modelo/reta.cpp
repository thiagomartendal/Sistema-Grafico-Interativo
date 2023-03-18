#include "reta.h"

void Reta::addPonto(float X, float Y) {
  if (Objeto2D::getPontos().size() == 2) {
    Objeto2D::getPontos()[1] = Ponto{X, Y};
  } else {
    Objeto2D::getPontos().push_back(Ponto{X, Y});
  }
}

void Reta::setTamanhoBorda(unsigned int tamanho) {
  Objeto2D::setTamanhoBorda(tamanho);
}

void Reta::setCorBorda(unsigned int R, unsigned int G, unsigned int B, float A) {
  Objeto2D::setCorBorda(R, G, B, A);
}

void Reta::setCorFundo(unsigned int R, unsigned int G, unsigned int B, float A) {
  Objeto2D::setCorFundo(R, G, B, A);
}

void Reta::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {
  if (Objeto2D::getPontos().size() == 2) {
    Ponto p1 = Objeto2D::getPontos()[0];
    Ponto p2 = Objeto2D::getPontos()[1];
    cr->set_line_width(1.0);
    cr->set_source_rgba(0, 0, 0, 1.0);
    cr->begin_new_sub_path();
    cr->line_to(p1.X, p1.Y);
    cr->line_to(p2.X, p2.Y);
    cr->close_path();
    cr->stroke();
  }
}
