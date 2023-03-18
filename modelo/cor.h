#ifndef COR_H
#define COR_H

typedef struct Cor {
  unsigned int R{0}; // 0 - 255
  unsigned int G{0}; // 0 - 255
  unsigned int B{0}; // 0 - 255
  float A{1.0}; // 0.0 - 1.0
} Cor;

#endif
