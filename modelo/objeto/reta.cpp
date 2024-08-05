#include "reta.h"

// Construtor
Reta::Reta() {
  tipo = Tipo::RETA;
}

// Renderiza a reta com as coordenadas da viewport
void Reta::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {
  // Formação
  cr->move_to(pontosTransformados[0].X, pontosTransformados[0].Y);
  cr->line_to(pontosTransformados[1].X, pontosTransformados[1].Y);

  // Contorno
  Gdk::Cairo::set_source_rgba(cr, contorno);
  cr->set_line_width(larguraBorda);
  cr->stroke();
}
