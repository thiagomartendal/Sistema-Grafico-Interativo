#include "triangulo.h"

// Construtor
Triangulo::Triangulo() {
  tipo = Tipo::TRIANGULO;
}

// Renderiza o triângulo com as coordenadas da viewport
void Triangulo::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {
  // Formação
  cr->move_to(pontosTransformados[0].X, pontosTransformados[0].Y);
  cr->line_to(pontosTransformados[1].X, pontosTransformados[1].Y);
  cr->line_to(pontosTransformados[2].X, pontosTransformados[2].Y);
  cr->close_path();

  // Preenchimento
  Gdk::Cairo::set_source_rgba(cr, preenchimento);
  cr->fill_preserve();

  // Contorno
  Gdk::Cairo::set_source_rgba(cr, contorno);
  cr->set_line_width(larguraBorda);
  cr->stroke();
}
