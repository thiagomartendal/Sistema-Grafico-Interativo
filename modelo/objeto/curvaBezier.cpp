#include "curvaBezier.h"

// Construtor
CurvaBezier::CurvaBezier() {
  tipo = Tipo::CURVA_BEZIER;
}

// Renderiza a curva bézier com as coordenadas da viewport
void CurvaBezier::renderizar(const Cairo::RefPtr<Cairo::Context>& cr) {
  // Formação
  cr->move_to(pontosTransformados[0].X, pontosTransformados[0].Y);
  for (double t = 0.00; t <= 1.0; t += 0.01) {
    double X = (pow(1.0 - t, 3.0) * pontosTransformados[0].X) +
    ((3 * t) * (pow(1.0 - t, 2.0) * pontosTransformados[2].X)) +
    ((3 * pow(t, 2.0)) * (1.0 - t) * pontosTransformados[3].X) +
    (pow(t, 3.0) * pontosTransformados[1].X);
    double Y = (pow(1.0 - t, 3.0) * pontosTransformados[0].Y) +
    ((3 * t) * (pow(1.0 - t, 2.0) * pontosTransformados[2].Y)) +
    ((3 * pow(t, 2.0)) * (1.0 - t) * pontosTransformados[3].Y) +
    (pow(t, 3.0) * pontosTransformados[1].Y);
    cr->line_to(X, Y);
  }
  cr->line_to(pontosTransformados[1].X, pontosTransformados[1].Y);

  // Contorno
  Gdk::Cairo::set_source_rgba(cr, contorno);
  cr->set_line_width(larguraBorda);
  cr->stroke();
}
