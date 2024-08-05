compilar:
	g++ main.cpp controle/aplicativo.cpp controle/interacaoObjeto.cpp\
		controle/produzirObjeto.cpp visao/janela.cpp visao/menu.cpp\
		visao/desenho.cpp visao/painel_lateral/painelLateral.cpp\
		visao/painel_lateral/zoom.cpp visao/painel_lateral/rotacaoWindow.cpp\
		visao/painel_lateral/movimento.cpp\
		visao/painel_lateral/translacaoEscalonamento.cpp\
		visao/painel_lateral/rotacao.cpp visao/novo_objeto_2D/novoObjeto2D.cpp\
		visao/novo_objeto_2D/entrada.cpp visao/novo_objeto_2D/painel.cpp\
		visao/novo_objeto_2D/painelPontoUnico.cpp\
		visao/novo_objeto_2D/painelPontoDuplo.cpp\
		visao/novo_objeto_2D/painelPontoTriplo.cpp\
		visao/novo_objeto_2D/painelPontoQuadruplo.cpp\
		visao/novo_objeto_2D/painelPoligono.cpp modelo/objeto/objeto.cpp\
		modelo/objeto/reta.cpp modelo/objeto/curvaBezier.cpp\
		modelo/objeto/quadrado.cpp modelo/objeto/circulo.cpp\
		modelo/objeto/triangulo.cpp modelo/objeto/retangulo.cpp\
		modelo/objeto/poligono.cpp modelo/listaObjeto.cpp\
		modelo/estruturaDimensao.cpp modelo/transformacao.cpp\
		`pkg-config gtkmm-4.0 --cflags --libs` -o Main

debugar:
	g++ main.cpp controle/aplicativo.cpp controle/interacaoObjeto.cpp\
		controle/produzirObjeto.cpp visao/janela.cpp visao/menu.cpp\
		visao/desenho.cpp visao/painel_lateral/painelLateral.cpp\
		visao/painel_lateral/zoom.cpp visao/painel_lateral/rotacaoWindow.cpp\
		visao/painel_lateral/movimento.cpp\
		visao/painel_lateral/translacaoEscalonamento.cpp\
		visao/painel_lateral/rotacao.cpp visao/novo_objeto_2D/novoObjeto2D.cpp\
		visao/novo_objeto_2D/entrada.cpp visao/novo_objeto_2D/painel.cpp\
		visao/novo_objeto_2D/painelPontoUnico.cpp\
		visao/novo_objeto_2D/painelPontoDuplo.cpp\
		visao/novo_objeto_2D/painelPontoTriplo.cpp\
		visao/novo_objeto_2D/painelPontoQuadruplo.cpp\
		visao/novo_objeto_2D/painelPoligono.cpp modelo/objeto/objeto.cpp\
		modelo/objeto/reta.cpp modelo/objeto/curvaBezier.cpp\
		modelo/objeto/quadrado.cpp modelo/objeto/circulo.cpp\
		modelo/objeto/triangulo.cpp modelo/objeto/retangulo.cpp\
		modelo/objeto/poligono.cpp modelo/listaObjeto.cpp\
		modelo/estruturaDimensao.cpp modelo/transformacao.cpp\
		`pkg-config gtkmm-4.0 --cflags --libs` -g -o Main
