#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada {
private:
  float X, Y, Z;

public:
  Coordenada() = default;
  Coordenada(float X, float Y, float Z = -1.0);
  void setX(float X);
  void setY(float Y);
  void setZ(float Z);
  float getX();
  float getY();
  float getZ();
};

#endif
