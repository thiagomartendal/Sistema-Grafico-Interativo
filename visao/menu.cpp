#include "menu.h"

/*
* Construtor
* Inicia o menu gráfico
*/
Menu::Menu() {
  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
  builder->add_from_string(Menu::definicao());
  Glib::RefPtr<Gio::Menu> menu = builder->get_object<Gio::Menu>("menubar");
  barraMenu = Gtk::make_managed<Gtk::PopoverMenuBar>(menu);
}

// Destrutor
Menu::~Menu() {
  delete barraMenu;
}

// Define a estrutura do menu
std::string Menu::definicao() {
  return "<interface>"
  "  <menu id='menubar'>"
  "    <submenu>"
  "      <attribute name='label' translatable='yes'>_Arquivo</attribute>"
  "      <section>"
  "        <submenu>"
  "          <attribute name='label' translatable='yes'>_Novo</attribute>"
  "          <section>"
  "            <submenu>"
  "              <attribute name='label' translatable='yes'>Objeto 2D</attribute>"
  "              <section>"
  "                <submenu>"
  "                  <attribute name='label' translatable='yes'>Linha</attribute>"
  "                  <section>"
  "                    <item>"
  "                      <attribute name='label' translatable='yes'>Reta</attribute>"
  "                      <attribute name='action'>janela.reta</attribute>"
  "                    </item>"
  "                    <item>"
  "                      <attribute name='label' translatable='yes'>Curva Bezier</attribute>"
  "                      <attribute name='action'>janela.curva_bezier</attribute>"
  "                    </item>"
  "                  </section>"
  "                </submenu>"
  "                <item>"
  "                  <attribute name='label' translatable='yes'>Quadrado</attribute>"
  "                  <attribute name='action'>janela.quadrado</attribute>"
  "                </item>"
  "                <item>"
  "                  <attribute name='label' translatable='yes'>Círculo</attribute>"
  "                  <attribute name='action'>janela.circulo</attribute>"
  "                </item>"
  "                <item>"
  "                  <attribute name='label' translatable='yes'>Triângulo</attribute>"
  "                  <attribute name='action'>janela.triangulo</attribute>"
  "                </item>"
  "                <item>"
  "                  <attribute name='label' translatable='yes'>Retângulo</attribute>"
  "                  <attribute name='action'>janela.retangulo</attribute>"
  "                </item>"
  "                <item>"
  "                  <attribute name='label' translatable='yes'>Polígono</attribute>"
  "                  <attribute name='action'>janela.poligono</attribute>"
  "                </item>"
  "              </section>"
  "            </submenu>"
  "            <item>"
  "              <attribute name='label' translatable='yes'>Objeto 3D</attribute>"
  "            </item>"
  "          </section>"
  "        </submenu>"
  "      </section>"
  "      <section>"
  "        <item>"
  "          <attribute name='label' translatable='yes'>_Sair</attribute>"
  "          <attribute name='action'>janela.sair</attribute>" // A chamada de cada ação é feita por nome do gurpo.rótulo, como janela.sair
  "        </item>"
  "      </section>"
  "    </submenu>"
  "  </menu>"
  "</interface>";
}

// Retorna o menu gráfico
Gtk::PopoverMenuBar* Menu::get() {
  return barraMenu;
}
