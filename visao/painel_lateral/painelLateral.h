#ifndef PAINEL_LATERAL_H
#define PAINEL_LATERAL_H

#include <gtkmm.h>
#include "zoom.h"
#include "rotacaoWindow.h"
#include "movimento.h"
#include "translacaoEscalonamento.h"
#include "rotacao.h"

struct ModeloTreeView {
  Glib::RefPtr<Gtk::ListStore> listaObjetos;
  Gtk::TreeModelColumn<std::string> nome;
  Gtk::TreeModelColumn<std::string> tipo;
};

class PainelLateral : public Gtk::ScrolledWindow {
private:
  int objetoSelecionado{-1};
  ModeloTreeView modelo;
  Zoom zoom;
  RotacaoWindow rotacaoWindow;
  Movimento movimento;
  TranslacaoEscalonamento translacao;
  TranslacaoEscalonamento escalonamento;
  Rotacao rotacao;
  void viewport(Gtk::Box& box);
  void painelObjetos(Gtk::Box& box);
  void painelTransformacoes(Gtk::Box& box);
  void acoesRotacao();

public:
  PainelLateral();
  void inserirObjeto(std::string nome, std::string tipo);
  Zoom& getZoom();
  RotacaoWindow& getRotacaoWindow();
  Movimento& getMovimento();
  TranslacaoEscalonamento& getTranslacao();
  TranslacaoEscalonamento& getEscalonamento();
  Rotacao& getRotacao();
  int getObjetoSelecionado();
};

#endif
