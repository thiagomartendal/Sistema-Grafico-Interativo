#include "listaObjeto.h"

ListaObjeto::~ListaObjeto() {
  for (Objeto2D *obj: objetos) {
    delete obj;
  }
  objetos.clear();
}

void ListaObjeto::inserirObjeto(Objeto2D *obj) {
  objetos.push_back(obj);
}

std::vector<Objeto2D*>& ListaObjeto::getObjetos() {
  return objetos;
}
