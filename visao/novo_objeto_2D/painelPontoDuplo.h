#ifndef PAINEL_PONTO_DUPLO_H
#define PAINEL_PONTO_DUPLO_H

#include "entrada.h"
#include "painel.h"

class PainelPontoDuplo : public Painel {
private:
  Entrada entrada1, entrada2;
  void propriedades();
  void definicao();

public:
  PainelPontoDuplo();
  void coletarCoordenadas() override;
};

#endif
