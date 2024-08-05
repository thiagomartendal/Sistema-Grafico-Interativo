#ifndef JANELA_H
#define JANELA_H

#include <gtkmm.h>
#include "menu.h"
#include "desenho.h"
#include "painel_lateral/painelLateral.h"

class Janela : public Gtk::Window {
private:
  // Gtk::Box box;
  PainelLateral* painel;
  Desenho* desenho;
  void propriedades(Gtk::Box& box);
  void barraMenu(Gtk::Box& box);
  void painelCentral(Gtk::Box& box);
  void painelLateral(Gtk::Box& central);
  void areaDesenho(Gtk::Box& central);

public:
  Janela();
  ~Janela();
  void sair();
  void mensagem(std::string mensagem);
  PainelLateral* getPainel();
  Desenho* getDesenho();
};

#endif
