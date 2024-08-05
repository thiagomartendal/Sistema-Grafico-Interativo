#include "novoObjeto2D.h"

NovoObjeto2D::NovoObjeto2D(TipoPainel tipo, Gtk::Window& parente) : Gtk::Dialog("", parente, true) {
  NovoObjeto2D::definir(tipo);
  NovoObjeto2D::painel();
  show();
}

NovoObjeto2D::~NovoObjeto2D() {
  delete painelPontos;
}

void NovoObjeto2D::definir(TipoPainel tipo) {
  std::string titulo;
  switch (tipo) {
    case TipoPainel::PAINEL_LR:
      titulo = "Nova Reta";
      painelPontos = new PainelPontoDuplo();
    break;
    case TipoPainel::PAINEL_CB:
      titulo = "Nova Curva Bézier";
      painelPontos = new PainelPontoQuadruplo();
    break;
    case TipoPainel::PAINEL_Q:
      titulo = "Novo Quadrado";
      painelPontos = new PainelPontoUnico();
    break;
    case TipoPainel::PAINEL_C:
      titulo = "Novo Círculo";
      painelPontos = new PainelPontoDuplo();
    break;
    case TipoPainel::PAINEL_T:
      titulo = "Novo Triângulo";
      painelPontos = new PainelPontoTriplo();
    break;
    case TipoPainel::PAINEL_R:
      titulo = "Novo Retângulo";
      painelPontos = new PainelPontoDuplo();
    break;
    case TipoPainel::PAINEL_P:
      titulo = "Novo Polígono";
      painelPontos = new PainelPoligono();
    break;
  }
  set_title(titulo);
}

void NovoObjeto2D::painel() {
  Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL);

  Gtk::Label tituloNomeObjeto = Gtk::Label("Nome do objeto:");
  tituloNomeObjeto.set_margin_start(10);
  tituloNomeObjeto.set_margin_end(10);

  Gtk::Label tituloEspessura = Gtk::Label("Espessura do contorno:");
  tituloEspessura.set_margin_start(10);
  tituloEspessura.set_margin_end(10);

  Gtk::Label tituloCorContorno = Gtk::Label("Cor do contorno:");
  tituloCorContorno.set_margin_start(10);
  tituloCorContorno.set_margin_end(10);

  Gtk::Label tituloCorPreenchimento = Gtk::Label("Cor do preenchimento:");
  tituloCorPreenchimento.set_margin_start(10);
  tituloCorPreenchimento.set_margin_end(10);

  nomeObjeto = Gtk::Entry();
  espessuraContorno = Gtk::Entry();
  corContorno = Gtk::ColorButton(Gdk::RGBA(0.0, 0.0, 0.0, 1.0));
  corPreenchimento = Gtk::ColorButton(Gdk::RGBA(1.0, 1.0, 1.0, 1.0));
  espessuraContorno.set_placeholder_text("1.0");

  Gtk::Box objeto = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  objeto.append(tituloNomeObjeto);
  objeto.append(nomeObjeto);
  objeto.set_margin_top(10);
  objeto.set_halign(Gtk::Align::CENTER);

  Gtk::Box espessura = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  espessura.append(tituloEspessura);
  espessura.append(espessuraContorno);
  espessura.set_margin_bottom(15);
  espessura.set_halign(Gtk::Align::CENTER);

  Gtk::Box cor = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  cor.append(tituloCorContorno);
  cor.append(corContorno);
  cor.append(tituloCorPreenchimento);
  cor.append(corPreenchimento);
  cor.set_margin_bottom(15);
  cor.set_halign(Gtk::Align::CENTER);

  Gtk::Box botoes = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  botoes.set_halign(Gtk::Align::END);
  botoes.set_margin_end(15);
  botoes.set_margin_bottom(15);
  botoes.set_spacing(5);

  Gtk::Button cancelar = Gtk::Button("Cancelar");
  cancelar.signal_clicked().connect(sigc::mem_fun(*this, &NovoObjeto2D::cancelar));

  ok = Gtk::Button("Ok");

  botoes.append(cancelar);
  botoes.append(ok);

  box.append(objeto);
  box.append(*painelPontos);
  box.append(espessura);
  box.append(cor);
  box.append(botoes);

  set_child(box);
}

void NovoObjeto2D::cancelar() {
  hide();
}

Painel* NovoObjeto2D::getPainelPontos() {
  return painelPontos;
}

std::string NovoObjeto2D::getNomeObjeto() {
  return nomeObjeto.get_text();
}

std::string NovoObjeto2D::getEspessuraContorno() {
  std::string espessura = espessuraContorno.get_text();
  return ((espessura == "") ? "1.0" : espessura);
}

Gdk::RGBA NovoObjeto2D::getCorContorno() {
  return corContorno.get_rgba();
}

Gdk::RGBA NovoObjeto2D::getCorPreenchimento() {
  return corPreenchimento.get_rgba();
}

Gtk::Button& NovoObjeto2D::getOk() {
  return ok;
}
