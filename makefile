compilar:
	g++ main.cpp controle/controle.cpp visao/menu.cpp visao/janela.cpp visao/itemMenu.cpp visao/viewport.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Main
