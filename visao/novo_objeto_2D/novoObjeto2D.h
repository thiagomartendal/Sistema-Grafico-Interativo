#ifndef NOVO_OBJETO_2D_H
#define NOVO_OBJETO_2D_H

#include <gtkmm.h>
#include "painelPontoUnico.h"
#include "painelPontoDuplo.h"
#include "painelPontoTriplo.h"
#include "painelPontoQuadruplo.h"

#include "painelPoligono.h"

class NovoObjeto2D : public Gtk::Dialog {
private:
  Painel* painelPontos;
  Gtk::Entry nomeObjeto;
  Gtk::Entry espessuraContorno;
  Gtk::ColorButton corContorno;
  Gtk::ColorButton corPreenchimento;
  Gtk::Button ok;
  void definir(TipoPainel tipo);
  void painel();
  void cancelar();

public:
  NovoObjeto2D() = default;
  NovoObjeto2D(TipoPainel tipo, Gtk::Window& parente);
  ~NovoObjeto2D();
  Painel* getPainelPontos();
  std::string getNomeObjeto();
  std::string getEspessuraContorno();
  Gdk::RGBA getCorContorno();
  Gdk::RGBA getCorPreenchimento();
  Gtk::Button& getOk();
};

#endif
