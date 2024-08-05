#ifndef TRANSLACAO_ESCALONAMENTO_H
#define TRANSLACAO_ESCALONAMENTO_H

#include <gtkmm.h>

struct ComponenteTranslacao {
  Gtk::Entry Dx;
  Gtk::Entry Dy;
  Gtk::Entry Dz;
  Gtk::Button transladar;
};

struct ComponenteEscalonamento {
  Gtk::Entry Sx;
  Gtk::Entry Sy;
  Gtk::Entry Sz;
  Gtk::Button escalar;
};

class TranslacaoEscalonamento : public Gtk::Frame {
private:
  ComponenteTranslacao componenteT;
  ComponenteEscalonamento componenteE;
  void definirComponente(bool translacao);
  void painel(bool translacao);

public:
  TranslacaoEscalonamento(bool translacao = true);
  ComponenteTranslacao& getComponenteTranslacao();
  ComponenteEscalonamento& getComponenteEscalonamento();
};

#endif
