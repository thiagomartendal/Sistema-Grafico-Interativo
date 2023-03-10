Cor::Cor(float R, float G, float B, float A = 1.0) {
  this.R = R;
  this.G = G;
  this.B = B;
  this.A = A;
}

void Cor::setR(float R) {
  this.R = R;
}

void Cor::setG(float G) {
  this.G = G;
}

void Cor::setB(float B) {
  this.B = B;
}

void Cor::setA(float A) {
  this.A = A;
}

float Cor::getR() {
  return R;
}

float Cor::getG() {
  return G;
}

float Cor::getB() {
  return B;
}

float Cor::getA() {
  return A;
}
