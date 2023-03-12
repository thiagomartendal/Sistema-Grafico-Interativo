#ifndef CONTROLE_H
#define CONTROLE_H

#include <vector>
#include "../visao/janela.h"

class Controle {
private:
  // std::vector<Objeto2D> objetos;
  Menu *menu;
  Janela *jnl;
  void aplicarAcoesMenu();

public:
  Controle();
  ~Controle();
  Janela* janela();
};

#endif
