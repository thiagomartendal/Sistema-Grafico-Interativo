#include "painelLateral.h"

PainelLateral::PainelLateral() {
  zoom = Zoom();
  rotacaoWindow = RotacaoWindow();
  translacao = TranslacaoEscalonamento();
  escalonamento = TranslacaoEscalonamento(false);
  rotacao = Rotacao();
  Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL);
  PainelLateral::acoesRotacao();
  PainelLateral::painelObjetos(box);
  PainelLateral::painelTransformacoes(box);
  PainelLateral::viewport(box);
  set_size_request(215);
}

void PainelLateral::viewport(Gtk::Box& box) {
  std::unique_ptr<Gtk::Viewport> vwp = std::unique_ptr<Gtk::Viewport>(new Gtk::Viewport(NULL, NULL));
  vwp->set_child(box);
  set_child(*vwp.release());
}

void PainelLateral::painelObjetos(Gtk::Box& box) {
  Gtk::Frame painel = Gtk::Frame();
  Glib::RefPtr<Gtk::TreeView> objetos = Glib::make_refptr_for_instance<Gtk::TreeView>(new Gtk::TreeView());
  Gtk::TreeModel::ColumnRecord mdl;
  mdl.add(modelo.nome);
  mdl.add(modelo.tipo);
  modelo.listaObjetos = Gtk::ListStore::create(mdl);
  objetos->set_model(modelo.listaObjetos);
  std::unique_ptr<Gtk::TreeViewColumn> colNome = std::unique_ptr<Gtk::TreeViewColumn>(new Gtk::TreeViewColumn("Nome", modelo.nome));
  std::unique_ptr<Gtk::TreeViewColumn> colTipo = std::unique_ptr<Gtk::TreeViewColumn>(new Gtk::TreeViewColumn("Tipo", modelo.tipo));
  colNome->set_expand();
  colTipo->set_expand();
  objetos->append_column(*colNome.release());
  objetos->append_column(*colTipo.release());
  painel.set_child(*objetos);
  box.append(painel);

  objetos->get_selection()->signal_changed().connect([&, objetos](){
    Gtk::TreeIter<Gtk::TreeRow> iter = objetos->get_selection()->get_selected();
    if(iter) {
      Gtk::TreeRow linha = *iter;
      int i = 0;
      for (auto iter2 = objetos->get_model()->children().begin(); iter2 != iter; ++iter2) i++;
      objetoSelecionado = i;
    }
  });

}

void PainelLateral::painelTransformacoes(Gtk::Box& box) {
  Gtk::Frame painel = Gtk::Frame();
  Gtk::Box boxPainel = Gtk::Box(Gtk::Orientation::VERTICAL);
  boxPainel.set_margin_top(5);
  boxPainel.append(zoom);
  boxPainel.append(rotacaoWindow);
  boxPainel.append(movimento);
  boxPainel.append(translacao);
  boxPainel.append(escalonamento);
  boxPainel.append(rotacao);
  painel.set_child(boxPainel);
  painel.set_vexpand();
  box.append(painel);
}

void PainelLateral::acoesRotacao() {
  rotacao.getComponente().centroObjeto.property_active().signal_changed().connect([&](){
    rotacao.getComponente().tipoRotacao = "objeto";
    rotacao.getComponente().boxPontoArbitrario.set_visible(false);
  });

  rotacao.getComponente().centroMundo.signal_toggled().connect([&](){
    rotacao.getComponente().tipoRotacao = "mundo";
    rotacao.getComponente().boxPontoArbitrario.set_visible(false);
  });

  rotacao.getComponente().pontoQualquer.property_active().signal_changed().connect([&](){
    rotacao.getComponente().tipoRotacao = "ponto";
    rotacao.getComponente().boxPontoArbitrario.set_visible(true);
  });
}

void PainelLateral::inserirObjeto(std::string nome, std::string tipo) {
  auto linha = *(modelo.listaObjetos->append());
  linha[modelo.nome] = nome;
  linha[modelo.tipo] = tipo;
}

Zoom& PainelLateral::getZoom() {
  return zoom;
}

RotacaoWindow& PainelLateral::getRotacaoWindow() {
  return rotacaoWindow;
}

Movimento& PainelLateral::getMovimento() {
  return movimento;
}

TranslacaoEscalonamento& PainelLateral::getTranslacao() {
  return translacao;
}

TranslacaoEscalonamento& PainelLateral::getEscalonamento() {
  return escalonamento;
}

Rotacao& PainelLateral::getRotacao() {
  return rotacao;
}

int PainelLateral::getObjetoSelecionado() {
  return objetoSelecionado;
}
