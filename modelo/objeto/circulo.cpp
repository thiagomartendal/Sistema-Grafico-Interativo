#include "circulo.h"

// Construtor
Circulo::Circulo() {
  tipo = Tipo::CIRCULO;
}

// Renderiza o círculo com as coordenadas da viewport
void Circulo::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {
  // Formação
  double distancia = sqrt(pow(pontosTransformados[1].X - pontosTransformados[0].X, 2.0) + pow(pontosTransformados[1].Y - pontosTransformados[0].Y, 2.0));
  cr->arc(
    (pontosTransformados[0].X + pontosTransformados[1].X) / 2.0, // X
    (pontosTransformados[0].Y + pontosTransformados[1].Y) / 2.0, // Y
    distancia / 2.0, // Raio
    0.0, // Angulo 1
    M_PI * 2.0 // Angulo 2
  );
  cr->close_path();

  // Preenchimento
  Gdk::Cairo::set_source_rgba(cr, preenchimento);
  cr->fill_preserve();

  // Contorno
  Gdk::Cairo::set_source_rgba(cr, contorno);
  cr->set_line_width(larguraBorda);
  cr->stroke();
}
