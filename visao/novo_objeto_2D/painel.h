#ifndef PAINEL_H
#define PAINEL_H

#include <vector>
#include <string>
#include <gtkmm.h>

enum TipoPainel {
  PAINEL_LR,
  PAINEL_CB,
  PAINEL_Q,
  PAINEL_C,
  PAINEL_T,
  PAINEL_R,
  PAINEL_P
};

class Painel : public Gtk::Box {
protected:
  std::vector<std::string> coordenadas;

public:
  Painel();
  virtual void coletarCoordenadas();
  std::vector<std::string> getCoordenadas();
};

#endif
