#ifndef PAINEL_PONTO_UNICO_H
#define PAINEL_PONTO_UNICO_H

#include "entrada.h"
#include "painel.h"

class PainelPontoUnico : public Painel {
private:
  Entrada entrada;
  Gtk::Entry lado;
  void propriedades();
  void definicao();

public:
  PainelPontoUnico();
  void coletarCoordenadas() override;
};

#endif
