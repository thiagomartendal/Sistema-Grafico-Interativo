#include "transformacao.h"

// Transformada de viewport
Ponto Transformacao::viewport(Ponto ponto, Dimensao vieport, Dimensao window) {
  return Transformacao::viewportNormal(ponto, vieport, window);
}

// Transformada de viewport 2D tradicional
Ponto Transformacao::viewportTradicional(Ponto ponto, Dimensao vieport, Dimensao window) {
  Ponto transformado;
  transformado.X = ((ponto.X - window.P1.X) / (window.P3.X - window.P1.X)) * (vieport.P3.X - vieport.P1.X);
  transformado.Y = (1.0 - ((ponto.Y - window.P3.Y) / (window.P3.Y - window.P1.Y))) * (vieport.P3.Y - vieport.P1.Y);
  return transformado;
}

// Transformada de viewport por escalonamento dos pontos normalizados
Ponto Transformacao::viewportPorEscalonamento(Ponto ponto, Dimensao vieport, Dimensao window) {
  std::vector<std::vector<double>> escalonamento =
  {
    {vieport.P3.X, 0.0, 0.0},
    {0.0, vieport.P3.Y, 0.0},
    {0.0, 0.0, 1.0}
  };
  std::vector<std::vector<double>> matriz = {{ponto.X, -1.0 * ponto.Y, ponto.W}};
  std::vector<std::vector<double>> res = Transformacao::multiplicarMatriz(matriz, escalonamento);
  return Ponto{res[0][0] + vieport.P3.X, res[0][1] + vieport.P3.Y};
}

// Transformada de viewport dos pontos normalizados
Ponto Transformacao::viewportNormal(Ponto ponto, Dimensao vieport, Dimensao window) {
  Ponto transformado;
  transformado.X = ((ponto.X / 2.0) + 0.5) * vieport.largura;
  transformado.Y = ((-1.0 * ponto.Y / 2.0) + 0.5) * vieport.altura;
  return transformado;
}

// Normalização de coordenadas através das transformações 2D
Ponto Transformacao::normalizar(double angulo, Dimensao window, Ponto ponto) {
  double anguloRadiano = angulo * (M_PI / 180.0);
  std::vector<std::vector<double>> translacao =
  {
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {-1.0 * window.centro.X, -1.0 * window.centro.Y, 1.0}
  };
  std::vector<std::vector<double>> rotacao =
  {
    {cos(anguloRadiano), -1.0 * sin(anguloRadiano), 0.0},
    {sin(anguloRadiano), cos(anguloRadiano), 0.0},
    {0.0, 0.0, 1.0}
  };
  double escalaX = window.P3.X - window.centro.X, escalaY = window.P3.Y - window.centro.Y;
  std::vector<std::vector<double>> escalonamento =
  {
    {1.0 / escalaX, 0.0, 0.0},
    {0.0, 1.0 / escalaY, 0.0},
    {0.0, 0.0, 1.0}
  };
  std::vector<std::vector<double>> m1 = Transformacao::multiplicarMatriz(translacao, rotacao);
  std::vector<std::vector<double>> m2 = Transformacao::multiplicarMatriz(m1, escalonamento);
  std::vector<std::vector<double>> matriz = {{ponto.X, ponto.Y, ponto.W}};
  std::vector<std::vector<double>> res = Transformacao::multiplicarMatriz(matriz, m2);
  return Ponto{res[0][0], res[0][1]};
}

// Define o ângulo geral da window, atualizado na rotação da window

void Transformacao::addAnguloWindow(double angulo) {
  anguloWindow += angulo;
}

// Transformação de zoom através do escalonamento da window
void Transformacao::zoom(EstruturaDimensao& dimensao, char tipoZoom) {
  /*
  * O zoom deve ter um limite superior e inferior para não deformar os objetos
  * quando o tamanho mínimo da window fica próximo de zero, ou o tamanho máximo
  * da window se estede muito.
  */
  std::vector<Ponto> pontos = {
    dimensao.getWindow().P1,
    dimensao.getWindow().P2,
    dimensao.getWindow().centro,
    dimensao.getWindow().P3,
    dimensao.getWindow().P4
  };
  if (tipoZoom == '+') {
    if (fatorZoom < 340) {
      fatorZoom += 5;
      Transformacao::escala2D(0.95, 0.95, dimensao.getWindow().centro, pontos);
    }
  } else if (tipoZoom == '-') {
    if (fatorZoom > 5) {
      fatorZoom -= 5;
      Transformacao::escala2D(1.05, 1.05, dimensao.getWindow().centro, pontos);
    }
  } else {
    double escala = 0.0;
    if (fatorZoom > 100) {
      escala = pow(1.05, ((fatorZoom - 100) / 5));
    } else {
      escala = pow(0.95, ((100 - fatorZoom) / 5));
    }
    Transformacao::escala2D(escala, escala, dimensao.getWindow().centro, pontos);
    fatorZoom = 100;
  }
  dimensao.getWindow().P1 = pontos[0];
  dimensao.getWindow().P2 = pontos[1];
  dimensao.getWindow().centro = pontos[2];
  dimensao.getWindow().P3 = pontos[3];
  dimensao.getWindow().P4 = pontos[4];
  dimensao.getWindow().largura = (pontos[3].X - pontos[0].X);
  dimensao.getWindow().altura = (pontos[3].Y - pontos[0].Y);
}

// Transformação de movimento através da translação da window
void Transformacao::moverWindow(EstruturaDimensao& dimensao, double fator, Direcao direcao) {
  double fatorX = 0.0, fatorY = 0.0;
  if (direcao == Direcao::CIMA) { // Para Cima
    fatorY = -1.0 * fator;
  } else if (direcao == Direcao::ESQUERDA) { // Para a Esquerda
    fatorX = fator;
  } else if (direcao == Direcao::DIREITA) { // Para a Direita
    fatorX = -1.0 * fator;
  } else if (direcao == Direcao::BAIXO) { // Para Baixo
    fatorY = fator;
  } else if (direcao == Direcao::CIMA_ESQUERDA) { // Para Cima e a Esquerda
    fatorX = fator;
    fatorY = -1.0 * fator;
  } else if (direcao == Direcao::CIMA_DIREITA) { // Para Cima e a Direita
    fatorX = -1.0 * fator;
    fatorY = -1.0 * fator;
  } else if (direcao == Direcao::BAIXO_ESQUERDA) { // Para Baixo e a Esquerda
    fatorX = fator;
    fatorY = fator;
  } else if (direcao == Direcao::BAIXO_DIREITA) { // Para Baixo e a Direita
    fatorX = -1.0 * fator;
    fatorY = fator;
  } else { // Centralizar
    // Centraliza a window usando as dimensões da viewport
    dimensao.getWindow().P1 = dimensao.getVieport().P1;
    dimensao.getWindow().P2 = dimensao.getVieport().P2;
    dimensao.getWindow().centro = dimensao.getVieport().centro;
    dimensao.getWindow().P3 = dimensao.getVieport().P3;
    dimensao.getWindow().P4 = dimensao.getVieport().P4;
    fatorX = 0.0;
    fatorY = 0.0;
  }
  std::vector<Ponto> pontos = {
    dimensao.getWindow().P1,
    dimensao.getWindow().P2,
    dimensao.getWindow().centro,
    dimensao.getWindow().P3,
    dimensao.getWindow().P4
  };
  Transformacao::translacao2D(fatorX, fatorY, pontos);
  if (direcao == Direcao::CENTRO) {
    // Atribui para a window suas dimensões anteriores para preservar o zoom
    double escala = 0.0;
    if (fatorZoom > 100) {
      escala = pow(0.95, ((fatorZoom - 100) / 5));
    } else {
      escala = pow(1.05, ((100 - fatorZoom) / 5));
    }
    Transformacao::escala2D(escala, escala, dimensao.getWindow().centro, pontos);
  }
  dimensao.getWindow().P1 = pontos[0];
  dimensao.getWindow().P2 = pontos[1];
  dimensao.getWindow().centro = pontos[2];
  dimensao.getWindow().P3 = pontos[3];
  dimensao.getWindow().P4 = pontos[4];
}

// Transformação de translação 2D
void Transformacao::translacao2D(double distanciaX, double distanciaY, std::vector<Ponto>& pontos) {
  std::vector<std::vector<double>> translacao =
  {
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {distanciaX, distanciaY, 1.0}
  };
  for (Ponto& ponto: pontos) {
    std::vector<std::vector<double>> matriz = {{ponto.X, ponto.Y, ponto.W}};
    std::vector<std::vector<double>> res = Transformacao::multiplicarMatriz(matriz, translacao);
    ponto.X = res[0][0];
    ponto.Y = res[0][1];
  }
}

// Transformação de escalonamento 2D
void Transformacao::escala2D(double escalaX, double escalaY, Ponto pontoEscala, std::vector<Ponto>& pontos) {
  std::vector<std::vector<double>> base =
  {
    {escalaX, 0.0, 0.0},
    {0.0, escalaY, 0.0},
    {0.0, 0.0, 1.0}
  };
  std::vector<std::vector<double>> escala = Transformacao::matrizAuxiliar(pontoEscala.X, pontoEscala.Y, base);
  for (Ponto& ponto: pontos) {
    std::vector<std::vector<double>> matriz = {{ponto.X, ponto.Y, ponto.W}};
    std::vector<std::vector<double>> res = Transformacao::multiplicarMatriz(matriz, escala);
    ponto.X = res[0][0];
    ponto.Y = res[0][1];
  }
}

// Transformação de rotacao 2D
void Transformacao::rotacao2D(double angulo, Ponto pontoRotacao, std::vector<Ponto>& pontos) {
  double anguloRadiano = angulo * (M_PI / 180.0);
  std::vector<std::vector<double>> base =
  {
    {cos(anguloRadiano), -1.0 * sin(anguloRadiano), 0.0},
    {sin(anguloRadiano), cos(anguloRadiano), 0.0},
    {0.0, 0.0, 1.0}
  };
  std::vector<std::vector<double>> rotacao = Transformacao::matrizAuxiliar(pontoRotacao.X, pontoRotacao.Y, base);
  for (Ponto& ponto: pontos) {
    std::vector<std::vector<double>> matriz = {{ponto.X, ponto.Y, ponto.W}};
    std::vector<std::vector<double>> res = Transformacao::multiplicarMatriz(matriz, rotacao);
    ponto.X = res[0][0];
    ponto.Y = res[0][1];
  }
}

// Matriz auxiliar das transformações de rotação e escala
std::vector<std::vector<double>> Transformacao::matrizAuxiliar(double distanciaX, double distanciaY, std::vector<std::vector<double>> auxiliar) {
  std::vector<std::vector<double>> translacao1 =
  {
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {-1.0 * distanciaX, -1.0 * distanciaY, 1.0}
  };
  std::vector<std::vector<double>> translacao2 =
  {
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {distanciaX, distanciaY, 1.0}
  };
  std::vector<std::vector<double>> mul = Transformacao::multiplicarMatriz(translacao1, auxiliar);
  return Transformacao::multiplicarMatriz(mul, translacao2);
}

// Algoritmo de multiplicação de matrizes
std::vector<std::vector<double>> Transformacao::multiplicarMatriz(std::vector<std::vector<double>> m1, std::vector<std::vector<double>> m2) {
  std::vector<std::vector<double>> res = std::vector<std::vector<double>>(m1.size());
  for (int i = 0; i < m1.size(); i++) {
    res[i] = std::vector<double>(m2[0].size());
    for (int j = 0; j < m2[0].size(); j++) {
      res[i][j] = 0.0;
      for (int k = 0; k < m2.size(); k++) {
        res[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  return res;
}

// Retorna o fator de zoom atual da window
int Transformacao::getFatorZoom() {
  return fatorZoom;
}

// Retorna o angulo atual da window
double Transformacao::getAnguloWindow() {
  return anguloWindow;
}
