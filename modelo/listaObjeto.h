#ifndef LISTA_OBJETO_H
#define LISTA_OBJETO_H

#include <vector>
#include "objeto/objeto.h"

class ListaObjeto {
private:
  std::vector<Objeto> objetos;

public:
  ListaObjeto() = default;
  void inserir(Objeto objeto);
  std::vector<Objeto>& getObjetos();
};

#endif
