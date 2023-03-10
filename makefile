compilar:
	g++ main.cpp controle/controle.cpp visao/janela.cpp visao/menu.cpp visao/itemMenu.cpp visao/desenho.cpp `pkg-config gtkmm-3.0 --cflags --libs` -o Main
