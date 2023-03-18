#ifndef JANELA_H
#define JANELA_H

#include <gtkmm.h>
#include "menu.h"

class Janela : public Gtk::Window {
private:
  Gtk::Alignment alinhamento;
  void propriedades();
  void painelCentral(std::unique_ptr<Gtk::VBox> &layout);
  void painelDeObjetos(std::unique_ptr<Gtk::HBox> &layoutPainel);
  void areaViewport(std::unique_ptr<Gtk::HBox> &layoutPainel);

public:
  Janela();
  ~Janela();
  void layoutPrincipal(Menu *menu);
  Gtk::Alignment& getAlinhamento();
};

#endif
