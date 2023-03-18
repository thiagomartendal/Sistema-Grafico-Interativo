#ifndef LISTA_OBJETO_H
#define LISTA_OBJETO_H

#include <vector>
#include "objeto2D.h"
#include "reta.h"

class ListaObjeto {
private:
  std::vector<Objeto2D*> objetos;

public:
  ListaObjeto() = default;
  ~ListaObjeto();
  void inserirObjeto(Objeto2D *obj);
  std::vector<Objeto2D*>& getObjetos();
};

#endif
