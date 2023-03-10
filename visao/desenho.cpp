#include "desenho.h"

Desenho::Desenho() : Gtk::DrawingArea() {
  add_events(Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK | Gdk::BUTTON1_MOTION_MASK);
  // signal_button_press_event().connect(sigc::mem_fun(*this, &Desenho::clique));
  // signal_motion_notify_event().connect(sigc::mem_fun(*this, &Desenho::arraste));
  // signal_button_release_event().connect(sigc::mem_fun(*this, &Desenho::soltarClique));
  // ItemMenu::instancia()->getSelecao()->signal_activate().connect(sigc::mem_fun(this, &Desenho::selecao));
  // ItemMenu::instancia()->getRetangulo()->signal_activate().connect(sigc::mem_fun(this, &Desenho::retangulo));
  Desenho::dimensoes(largura, altura);
}

bool Desenho::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
  Desenho::planoDeFundo(cr);
  return true;
}

void Desenho::planoDeFundo(const Cairo::RefPtr<Cairo::Context>& cr) {
  // cr->set_source_rgba(planoFundo.corObjeto[0], planoFundo.corObjeto[1], planoFundo.corObjeto[2], planoFundo.corObjeto[3]);
  cr->set_source_rgba(1.0, 1.0, 1.0, 1.0);
  cr->rectangle(0, 0, largura, altura);
  cr->fill_preserve();
  cr->set_source_rgba(0.0, 0.0, 0.0, 1.0);
  cr->set_line_width(1);
  cr->stroke();
}

void Desenho::dimensoes(int largura, int altura) {
  this->largura = largura;
  this->altura = altura;
  set_size_request(largura, altura);
  queue_draw();
}
