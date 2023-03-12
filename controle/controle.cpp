#include "controle.h"

Controle::Controle() {
  menu = new Menu();
  jnl = new Janela();
  jnl->layoutPrincipal(menu);
  jnl->show_all_children();
  Controle::aplicarAcoesMenu();
}

Controle::~Controle() {
  delete menu;
  delete jnl;
}

Janela* Controle::janela() {
  return jnl;
}

void Controle::aplicarAcoesMenu() {
  menu->getItemMenu()->getSair()->signal_activate().connect(sigc::mem_fun(jnl, &Janela::close));
}
