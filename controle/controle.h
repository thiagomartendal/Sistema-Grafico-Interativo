#ifndef CONTROLE_H
#define CONTROLE_H

#include <iostream>
#include <vector>
#include "../modelo/ferramenta.h"
#include "../modelo/viewport.h"
#include "../modelo/objeto2D.h"
#include "../modelo/reta.h"
#include "../visao/janela.h"

class Controle {
private:
  // std::vector<Objeto2D*> objetos;
  Menu *menu;
  Viewport *viewport;
  Janela *jnl;
  void acoesMenu();
  void selecao();
  void linha();

public:
  Controle();
  ~Controle();
  Janela* janela();
};

#endif
