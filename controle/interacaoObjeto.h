#ifndef INSERIR_OBJETO_H
#define INSERIR_OBJETO_H

#include "produzirObjeto.h"
#include "../visao/janela.h"
#include "../visao/novo_objeto_2D/novoObjeto2D.h"
#include "../modelo/listaObjeto.h"
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

class InteracaoObjeto {
private:
  ListaObjeto lista;
  EstruturaDimensao dimensao;
  Transformacao transformacao;
  Janela* janela;
  void definirDimensoes();
  void confirmarObjeto(Tipo tipoObjeto, ProduzirObjeto produzir);
  void executarTransformadaViewport(double angulo = 0.0);

public:
  InteracaoObjeto() = default;
  InteracaoObjeto(Janela* janela);
  void inserir(TipoPainel painel, Tipo objeto);
  void zoom(char tipoZoom);
  void moverWindow(Direcao direcao);
  void transladar();
  void escalonar();
  void rotacionar();
  void rotacionarWindow();
  ListaObjeto getLista();
};

#endif
