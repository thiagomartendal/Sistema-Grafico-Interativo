#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <gtkmm.h>

struct ComponenteMovimento {
  Gtk::Button cima;
  Gtk::Button cimaEsquerda;
  Gtk::Button esquerda;
  Gtk::Button baixoEsquerda;
  Gtk::Button centro;
  Gtk::Button cimaDireita;
  Gtk::Button direita;
  Gtk::Button baixoDireita;
  Gtk::Button baixo;
  Gtk::Entry fatorMovimento;
};

class Movimento : public Gtk::Frame {
private:
  ComponenteMovimento componente;
  void definirComponente();
  void painel();

public:
  Movimento();
  ComponenteMovimento& getComponente();
};

#endif
