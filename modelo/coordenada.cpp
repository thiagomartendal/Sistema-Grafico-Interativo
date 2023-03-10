#include "coordenada.h"

Coordenada::Coordenada(float X, float Y, float Z) {
  this.X = X;
  this.Y = Y;
  this.Z = Z;
}

void Coordenada::setX(float X) {
  this.X = X;
}

void Coordenada::setY(float Y) {
  this.Y = Y;
}

void Coordenada::setZ(float Z) {
  this.Z = Z;
}

float Coordenada::getX() {
  return X;
}

float Coordenada::getY() {
  return Y;
}

float Coordenada::getZ() {
  return Z;
}
