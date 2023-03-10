#ifndef COR_H
#define COR_H

class Cor {
private:
  float R, G, B, A;

public:
  Cor() = default;
  Cor(float R, float G, float B, float A = 1.0);
  void setR(float R);
  void setG(float G);
  void setB(float B);
  void setA(float A);
  float getR();
  float getG();
  float getB();
  float getA();
};

#endif
