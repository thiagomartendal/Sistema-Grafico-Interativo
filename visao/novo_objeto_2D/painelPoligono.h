#ifndef PAINEL_POLIGONO_H
#define PAINEL_POLIGONO_H

#include "painel.h"

class PainelPoligono : public Painel {
private:
  Gtk::TextView entrada;
  void propriedades();
  void definicao();

public:
  PainelPoligono();
  void coletarCoordenadas() override;
};

#endif
