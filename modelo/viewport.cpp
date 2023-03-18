#include "viewport.h"

Viewport::Viewport() : Gtk::DrawingArea() {
  add_events(Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK | Gdk::BUTTON1_MOTION_MASK);
  signal_button_press_event().connect(sigc::mem_fun(*this, &Viewport::clique));
  signal_motion_notify_event().connect(sigc::mem_fun(*this, &Viewport::arraste));
  signal_button_release_event().connect(sigc::mem_fun(*this, &Viewport::soltarClique));
  Viewport::dimensoes(largura, altura);
}

Viewport::~Viewport() {
  delete objeto;
}

void Viewport::dimensoes(int largura, int altura) {
  this->largura = largura;
  this->altura = altura;
  set_size_request(largura, altura);
  queue_draw();
}

void Viewport::setFerramenta(Ferramenta ferramenta) {
  this->ferramenta = ferramenta;
}

ListaObjeto Viewport::getLista() {
  return lista;
}

bool Viewport::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
  Viewport::planoDeFundo(cr);
  for (Objeto2D *obj: lista.getObjetos()) {
    obj->renderizar(cr);
  }
  return true;
}

bool Viewport::clique(GdkEventButton *evt) {
  if ((evt->type == GDK_BUTTON_PRESS) && (evt->button == 1)) {
    if (ferramenta == Ferramenta::LINHA) {
      objeto = new Reta();
      lista.inserirObjeto(objeto);
      lista.getObjetos()[lista.getObjetos().size()-1]->addPonto(evt->x, evt->y);
    }
    queue_draw();
  }
  return false;
}

bool Viewport::arraste(GdkEventMotion *evt) {
  if (ferramenta == Ferramenta::SELECAO) {

  } else {
    lista.getObjetos()[lista.getObjetos().size()-1]->addPonto(evt->x, evt->y);
  }
  queue_draw();
  return false;
}

bool Viewport::soltarClique(GdkEventButton *evt) {
  if (ferramenta == Ferramenta::SELECAO) {

  } else {
    lista.getObjetos()[lista.getObjetos().size()-1]->addPonto(evt->x, evt->y);
  }
  queue_draw();
  return false;
}


void Viewport::planoDeFundo(const Cairo::RefPtr<Cairo::Context>& cr) {
  cr->begin_new_sub_path();
  cr->line_to(0, 0);
  cr->line_to(800, 0);
  cr->line_to(800, 600);
  cr->line_to(0, 600);
  cr->close_path();
  cr->set_line_width(2);
  cr->set_source_rgba(255, 255, 255, 1.0);
  cr->fill_preserve();
  cr->set_source_rgba(0, 0, 0, 1.0);
  cr->stroke();
}
