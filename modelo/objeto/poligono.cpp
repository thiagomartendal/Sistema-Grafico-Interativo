#include "poligono.h"

// Construtor
Poligono::Poligono() {
  tipo = Tipo::POLIGONO;
}

// Renderiza o polígono com as coordenadas da viewport
void Poligono::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {
  // Formação
  cr->move_to(pontosTransformados[0].X, pontosTransformados[0].Y);
  for (int i = 1; i < pontosTransformados.size(); i++) {
    cr->line_to(pontosTransformados[i].X, pontosTransformados[i].Y);
  }
  cr->close_path();

  // Preenchimento
  Gdk::Cairo::set_source_rgba(cr, preenchimento);
  cr->fill_preserve();

  // Contorno
  Gdk::Cairo::set_source_rgba(cr, contorno);
  cr->set_line_width(larguraBorda);
  cr->stroke();
}
