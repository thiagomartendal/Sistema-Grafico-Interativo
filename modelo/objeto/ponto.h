#ifndef PONTO_H
#define PONTO_H

// Ponto 3D
struct Ponto {
  double X{0.0};
  double Y{0.0};
  double Z{0.0};
  double W{1.0}; // Para operações no sistema de coordenadas homogêneas
};

#endif
