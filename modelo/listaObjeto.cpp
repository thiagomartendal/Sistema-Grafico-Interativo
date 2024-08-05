#include "listaObjeto.h"

// Insere o objeto gráfico na lista de objetos
void ListaObjeto::inserir(Objeto objeto) {
  objetos.push_back(objeto);
}

// Retorna a lista física de objetos
std::vector<Objeto>& ListaObjeto::getObjetos() {
  return objetos;
}
