#ifndef CONTROLE_H
#define CONTROLE_H

#include "../visao/janela.h"

class Controle {
private:
  Janela *jnl;

public:
  Controle();
  ~Controle();
  Janela* janela();
};

#endif
