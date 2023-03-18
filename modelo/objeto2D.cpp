#include "objeto2D.h"

void Objeto2D::addPonto(float X, float Y) {
  pontos.push_back(Ponto{X, Y});
}

void Objeto2D::setTamanhoBorda(unsigned int tamanho) {
  tamanhoBorda = tamanho;
}

void Objeto2D::setCorBorda(unsigned int R, unsigned int G, unsigned int B, float A) {
  corBorda = Cor{R, G, B, A};
}

void Objeto2D::setCorFundo(unsigned int R, unsigned int G, unsigned int B, float A) {
  corFundo = Cor{R, G, B, A};
}

void Objeto2D::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {

}

std::vector<Ponto>& Objeto2D::getPontos() {
  return pontos;
}
