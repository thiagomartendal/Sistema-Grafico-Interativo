#include "retangulo.h"

// Construtor
Retangulo::Retangulo() {
  tipo = Tipo::RETANGULO;
}

// Renderiza o retângulo com as coordenadas da viewport
void Retangulo::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {
  // Formação
  cr->move_to(pontosTransformados[0].X, pontosTransformados[0].Y);
  cr->line_to(pontosTransformados[1].X, pontosTransformados[1].Y);
  cr->line_to(pontosTransformados[2].X, pontosTransformados[2].Y);
  cr->line_to(pontosTransformados[3].X, pontosTransformados[3].Y);
  cr->close_path();


  // Preenchimento
  Gdk::Cairo::set_source_rgba(cr, preenchimento);
  cr->fill_preserve();

  // Contorno
  Gdk::Cairo::set_source_rgba(cr, contorno);
  cr->set_line_width(larguraBorda);
  cr->stroke();
}
