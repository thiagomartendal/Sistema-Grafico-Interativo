#include "controle.h"

Controle::Controle() {
  menu = new Menu();
  viewport = new Viewport();
  jnl = new Janela();
  jnl->layoutPrincipal(menu);
  jnl->getAlinhamento().add(*viewport);
  jnl->show_all_children();
  Controle::acoesMenu();
  // Reta *reta = new Reta();
  // reta->addPonto(1.0, 2.0);
  // objetos.push_back(reta);
}

Controle::~Controle() {
  delete menu;
  delete viewport;
  delete jnl;
  // for (Objeto2D *obj: objetos) {
  //   delete obj;
  // }
  // objetos.clear();
}

Janela* Controle::janela() {
  return jnl;
}

void Controle::acoesMenu() {
  // Arquivo
  menu->getItemMenu()->getSair()->signal_activate().connect(sigc::mem_fun(*jnl, &Janela::close));
  // Ferramenta
  menu->getItemMenu()->getSelecao()->signal_activate().connect(sigc::mem_fun(*this, &Controle::selecao));
  menu->getItemMenu()->getLinha()->signal_activate().connect(sigc::mem_fun(*this, &Controle::linha));
}

void Controle::selecao() {
  viewport->setFerramenta(Ferramenta::SELECAO);
}

void Controle::linha() {
  viewport->setFerramenta(Ferramenta::LINHA);
}
