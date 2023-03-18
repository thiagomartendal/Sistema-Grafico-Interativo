compilar:
	g++ main.cpp controle/controle.cpp  \
	modelo/viewport.cpp modelo/listaObjeto.cpp modelo/objeto2D.cpp modelo/reta.cpp \
	visao/menu.cpp visao/janela.cpp visao/itemMenu.cpp \
	`pkg-config gtkmm-3.0 --cflags --libs` `pkg-config cairomm-1.0 --cflags --libs` -o Main
