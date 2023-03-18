#include "acaoViewport.h"

AcaoViewport::AcaoViewport(Viewport *viewport, std::vector<Objeto2D*> &objetos) {
  this->objetos = objetos;
  this->viewport = viewport;
  // this->viewport->signal_draw().connect(sigc::mem_fun(*this, &AcaoViewport::desenhar));
  // this->viewport->signal_button_press_event().connect(sigc::mem_fun(*this, &AcaoViewport::clique));
  // this->viewport->signal_motion_notify_event().connect(sigc::mem_fun(*this, &AcaoViewport::arraste));
  // this->viewport->signal_button_release_event().connect(sigc::mem_fun(*this, &AcaoViewport::soltarClique));
  reta = new Reta();
}

AcaoViewport::~AcaoViewport() {

}

bool AcaoViewport::desenhar(const Cairo::RefPtr<Cairo::Context>& cr) {
  // cr->set_source_rgba(planoFundo.corObjeto[0], planoFundo.corObjeto[1], planoFundo.corObjeto[2], planoFundo.corObjeto[3]);
  // cr->set_source_rgba(255, 255, 255, 1.0);
  // cr->rectangle(0, 0, 800, 600);
  // cr->fill_preserve();
  // cr->set_source_rgba(0, 0, 0, 1.0);
  // cr->set_line_width(1);
  // cr->stroke();
  viewport->planoDeFundo(cr);
  return true;
}

bool AcaoViewport::clique(GdkEventButton *evt) {
  if ((evt->type == GDK_BUTTON_PRESS) && (evt->button == 1)) {
    std::cout << "C: " << "X: " << evt->x << " Y: " << evt->y << std::endl;
    // reta->addPonto(evt->x, evt->y);
    // p.push_back(evt->x);
    x = evt->x;
    viewport->queue_draw();
  }
  return false;
}

bool AcaoViewport::arraste(GdkEventMotion *evt) {
  std::cout << "A: " << "X: " << evt->x << " Y: " << evt->y << std::endl;
  return false;
}

bool AcaoViewport::soltarClique(GdkEventButton *evt) {
  std::cout << "S: " << "X: " << evt->x << " Y: " << evt->y << std::endl;
  // reta->addPonto(evt->x, evt->y);
  // objetos.push_back(reta);
  return false;
}
