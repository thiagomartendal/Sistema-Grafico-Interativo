#include "translacaoEscalonamento.h"

TranslacaoEscalonamento::TranslacaoEscalonamento(bool translacao) : Gtk::Frame() {
  TranslacaoEscalonamento::definirComponente(translacao);
  TranslacaoEscalonamento::painel(translacao);
}

void TranslacaoEscalonamento::definirComponente(bool translacao) {
  set_label(translacao ? "Translação de Objeto" : "Escalonamento de Objeto");
  if (translacao) {
    componenteT.transladar = Gtk::Button("Transladar");
    componenteT.transladar.set_margin_bottom(5);
    componenteT.Dx.set_placeholder_text("0.0");
    componenteT.Dy.set_placeholder_text("0.0");
    componenteT.Dz.set_placeholder_text("0.0");
  } else {
    componenteE.escalar = Gtk::Button("Escalar");
    componenteE.escalar.set_margin_bottom(5);
    componenteE.Sx.set_placeholder_text("0.0");
    componenteE.Sy.set_placeholder_text("0.0");
    componenteE.Sz.set_placeholder_text("0.0");
  }
}

void TranslacaoEscalonamento::painel(bool translacao) {
  Gtk::Label tituloX;
  Gtk::Label tituloY;
  Gtk::Label tituloZ;
  Gtk::Box painel = Gtk::Box(Gtk::Orientation::VERTICAL);
  Gtk::Box botao = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  Gtk::Grid grade = Gtk::Grid();

  if (translacao) {
    tituloX = Gtk::Label("Dx: ");
    tituloY = Gtk::Label("Dy: ");
    tituloZ = Gtk::Label("Dz: ");
  } else {
    tituloX = Gtk::Label("Sx: ");
    tituloY = Gtk::Label("Sy: ");
    tituloZ = Gtk::Label("Sz: ");
  }

  grade.set_margin_top(5);
  grade.set_margin_start(5);
  grade.set_margin_end(5);
  grade.set_margin_bottom(5);
  grade.set_row_spacing(5);
  grade.set_column_spacing(5);

  grade.attach(tituloX, 0, 0);
  grade.attach(tituloY, 0, 1);
  grade.attach(tituloZ, 0, 2);

  grade.attach(((translacao) ? componenteT.Dx : componenteE.Sx), 1, 0);
  grade.attach(((translacao) ? componenteT.Dy : componenteE.Sy), 1, 1);
  grade.attach(((translacao) ? componenteT.Dz : componenteE.Sz), 1, 2);

  botao.append(((translacao) ? componenteT.transladar : componenteE.escalar));
  botao.set_halign(Gtk::Align::CENTER);

  painel.append(grade);
  painel.append(botao);

  set_child(painel);
  set_margin_top(5);
  set_margin_start(7);
  set_margin_end(7);
}

ComponenteTranslacao& TranslacaoEscalonamento::getComponenteTranslacao() {
  return componenteT;
}

ComponenteEscalonamento& TranslacaoEscalonamento::getComponenteEscalonamento() {
  return componenteE;
}
