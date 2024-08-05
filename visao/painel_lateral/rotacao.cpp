#include "rotacao.h"

Rotacao::Rotacao() : Gtk::Frame("Rotação de Objeto") {
  Rotacao::definirComponente();
  Rotacao::painel();
}

void Rotacao::definirComponente() {
  componente.boxPontoArbitrario = Gtk::Box(Gtk::Orientation::VERTICAL);
  componente.rotacionar = Gtk::Button("Rotacionar");
  componente.rotacionar.set_margin_end(5);
  componente.centroObjeto = Gtk::CheckButton("Centro do Objeto");
  componente.centroMundo = Gtk::CheckButton("Centro do Mundo");
  componente.pontoQualquer = Gtk::CheckButton("Ponto Arbitrário");
  componente.centroObjeto.set_active();
  componente.centroMundo.set_group(componente.centroObjeto);
  componente.pontoQualquer.set_group(componente.centroObjeto);
  componente.centroMundo.set_margin_top(5);
  componente.centroObjeto.set_margin_top(5);
  componente.pontoQualquer.set_margin_top(5);
  componente.angulo.set_placeholder_text("Em graus");
  componente.X.set_placeholder_text("0.0");
  componente.Y.set_placeholder_text("0.0");
  componente.Z.set_placeholder_text("0.0");
}

void Rotacao::painel() {
  Gtk::Label tituloAngulo = Gtk::Label("Ângulo: ");
  Gtk::Label tituloCentroRotacao = Gtk::Label("Centro de Rotação: ");
  Gtk::Label tituloPontoArbitrario = Gtk::Label("Ponto Arbitrário de Rotação: ");
  Gtk::Label tituloX = Gtk::Label("X: ");
  Gtk::Label tituloY = Gtk::Label("Y: ");
  Gtk::Label tituloZ = Gtk::Label("Z: ");
  Gtk::Box painel = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box boxAngulo = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Box boxCentroRotacao = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box boxRotacionar = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Grid gradePontoArbitrario = Gtk::Grid();

  gradePontoArbitrario.set_margin_top(5);
  gradePontoArbitrario.set_margin_start(5);
  gradePontoArbitrario.set_margin_end(5);
  gradePontoArbitrario.set_margin_bottom(5);
  gradePontoArbitrario.set_row_spacing(5);
  gradePontoArbitrario.set_column_spacing(5);

  gradePontoArbitrario.attach(tituloX, 0, 0);
  gradePontoArbitrario.attach(tituloY, 0, 1);
  gradePontoArbitrario.attach(tituloZ, 0, 2);

  gradePontoArbitrario.attach(componente.X, 1, 0);
  gradePontoArbitrario.attach(componente.Y, 1, 1);
  gradePontoArbitrario.attach(componente.Z, 1, 2);

  boxAngulo.append(tituloAngulo);
  boxAngulo.append(componente.angulo);
  boxAngulo.set_halign(Gtk::Align::CENTER);
  boxAngulo.set_margin_start(5);
  boxAngulo.set_margin_end(5);

  boxCentroRotacao.append(tituloCentroRotacao);
  boxCentroRotacao.append(componente.centroObjeto);
  boxCentroRotacao.append(componente.centroMundo);
  boxCentroRotacao.append(componente.pontoQualquer);
  boxCentroRotacao.set_halign(Gtk::Align::CENTER);
  boxCentroRotacao.set_margin_top(5);
  boxCentroRotacao.set_margin_bottom(5);

  componente.boxPontoArbitrario.append(tituloPontoArbitrario);
  componente.boxPontoArbitrario.append(gradePontoArbitrario);
  componente.boxPontoArbitrario.set_visible(false);

  boxRotacionar.append(componente.rotacionar);
  boxRotacionar.set_halign(Gtk::Align::CENTER);

  painel.append(boxAngulo);
  painel.append(boxCentroRotacao);
  painel.append(componente.boxPontoArbitrario);
  painel.append(boxRotacionar);
  painel.set_margin_top(5);
  painel.set_margin_bottom(5);

  set_child(painel);
  set_margin_top(5);
  set_margin_start(7);
  set_margin_end(7);
  set_margin_bottom(5);
}

ComponenteRotacao& Rotacao::getComponente() {
  return componente;
}
