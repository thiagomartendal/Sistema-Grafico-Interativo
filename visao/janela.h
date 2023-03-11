#ifndef JANELA_H
#define JANELA_H

#include <gtkmm.h>
#include "menu.h"
#include "viewport.h"

class Janela : public Gtk::Window {
private:
  Viewport viewport;
  void propriedades();
  void layout();
  void menu(std::unique_ptr<Gtk::VBox> &layout);
  void acoesMenu();
  void sair();
  void painelCentral(std::unique_ptr<Gtk::VBox> &layout);
  void painelDeObjetos(std::unique_ptr<Gtk::HBox> &layoutPainel);
  void areaViewport(std::unique_ptr<Gtk::HBox> &layoutPainel);

public:
  Janela();
  ~Janela();
};

#endif
