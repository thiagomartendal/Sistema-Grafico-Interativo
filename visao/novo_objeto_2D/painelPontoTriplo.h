#ifndef PAINEL_PONTO_TRIPLO_H
#define PAINEL_PONTO_TRIPLO_H

#include "entrada.h"
#include "painel.h"

class PainelPontoTriplo : public Painel {
private:
  Entrada entrada1, entrada2, entrada3;
  void propriedades();
  void definicao();

public:
  PainelPontoTriplo();
  void coletarCoordenadas() override;
};

#endif
