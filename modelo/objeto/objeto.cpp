#include "objeto.h"

/*
* Construtor
* Define as características padrões do objeto gráfico
*/
Objeto::Objeto() {
  contorno = Gdk::RGBA(0.0, 0.0, 0.0, 1.0);
  preenchimento = Gdk::RGBA(1.0, 1.0, 1.0, 1.0);
  larguraBorda = 1.0;
}

// Define o nome do objeto
void Objeto::setNome(std::string nome) {
  this->nome = nome;
}

// Adiciona um ponto em coordenadas do mundo a lista de pontos do objeto
void Objeto::addPonto(Ponto ponto) {
  pontos.push_back(ponto);
}

// Adiciona um ponto em coordenadas da viewport
void Objeto::addPontoTransformado(Ponto pontoTransformado) {
  pontosTransformados.push_back(pontoTransformado);
}

// Define a largura da borda do objeto
void Objeto::setLarguraBorda(double larguraBorda) {
  this->larguraBorda = larguraBorda;
}

// Define a cor de contorno do objeto
void Objeto::setContorno(Gdk::RGBA cor) {
  contorno = cor;
}

// Define a cor de preenchimento do objeto
void Objeto::setPreenchimento(Gdk::RGBA cor) {
  preenchimento = cor;
}

// Limpa a lista de pontos da viewport
void Objeto::limparPontosTransformados() {
  pontosTransformados.clear();
}

// Método de renderização para a área de desenho, definido nas classes filhas
void Objeto::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {

}

// Retorna o nome do objeto
std::string Objeto::getNome() {
  return nome;
}

// Retorna os pontos do objeto (coordenadas do mundo)
std::vector<Ponto>& Objeto::getPontos() {
  return pontos;
}

// Retorna a largura da borda do objeto
double Objeto::getLarguraBorda() {
  return larguraBorda;
}

// Retorna a cor de contorno do objeto
Gdk::RGBA Objeto::getContorno() {
  return contorno;
}

// Retorna a cor de preenchimento do objeto
Gdk::RGBA Objeto::getPreenchimento() {
  return preenchimento;
}

// Retorna o tipo do objeto
Tipo Objeto::getTipo() {
  return tipo;
}

// Retorna o ponto central do objeto
Ponto Objeto::centro() {
  Ponto centro;
  for (Ponto ponto : pontos) {
    centro.X += ponto.X;
    centro.Y += ponto.Y;
    centro.Z += ponto.Z;
  }
  centro.X /= pontos.size();
  centro.Y /= pontos.size();
  centro.Z /= pontos.size();
  return centro;
}
