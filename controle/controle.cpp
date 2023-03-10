#include "controle.h"

Controle::Controle() {
  jnl = new Janela();
}

Controle::~Controle() {
  delete jnl;
}

Janela* Controle::janela() {
  return jnl;
}
