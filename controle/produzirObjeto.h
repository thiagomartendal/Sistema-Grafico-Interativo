#ifndef PRODUZIR_OBJETO_H
#define PRODUZIR_OBJETO_H

#include "../visao/janela.h"
#include "../visao/novo_objeto_2D/novoObjeto2D.h"
#include "../modelo/estruturaDimensao.h"
#include "../modelo/objeto/objeto.h"
#include "../modelo/objeto/reta.h"
#include "../modelo/objeto/curvaBezier.h"
#include "../modelo/objeto/quadrado.h"
#include "../modelo/objeto/circulo.h"
#include "../modelo/objeto/triangulo.h"
#include "../modelo/objeto/retangulo.h"
#include "../modelo/objeto/poligono.h"
#include "../modelo/transformacao.h"

class ProduzirObjeto {
private:
  std::string tipo;
  Objeto objeto;
  Glib::RefPtr<NovoObjeto2D> novoObjeto2D;
  void definirPontos();
  void definirPontosQuadradoRetangulo(Tipo tipoObjeto);

public:
  ProduzirObjeto(Glib::RefPtr<NovoObjeto2D> novoObjeto2D);
  void definirObjeto(Tipo tipoObjeto);
  Objeto getObjeto();
  std::string getTipo();
};

#endif
