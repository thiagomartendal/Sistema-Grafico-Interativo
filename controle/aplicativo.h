#ifndef APLICATIVO_H
#define APLICATIVO_H

#include <gtkmm.h>
#include "interacaoObjeto.h"
#include "../visao/janela.h"

class Aplicativo : public Gtk::Application {
private:
  Janela* janela;
  InteracaoObjeto interacaoObjeto;
  void acoesMenu();
  void acoesPainelLateral();
  void atualizarDesenho(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);

protected:
  void on_startup() override;
  void on_activate() override;

public:
  Aplicativo();
  ~Aplicativo();
  static Glib::RefPtr<Aplicativo> create();
};

#endif
