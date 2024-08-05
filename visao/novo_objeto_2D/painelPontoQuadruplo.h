#ifndef PAINEL_PONTO_QUADRUPLO_H
#define PAINEL_PONTO_QUADRUPLO_H

#include "entrada.h"
#include "painel.h"

class PainelPontoQuadruplo : public Painel {
private:
  Entrada entrada1, entrada2, entrada3, entrada4;
  void propriedades();
  void definicao();

public:
  PainelPontoQuadruplo();
  void coletarCoordenadas() override;
};

#endif
