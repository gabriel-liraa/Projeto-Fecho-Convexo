#ifndef PONTO
#define PONTO

#include <iostream>

#include "par.hpp"

using namespace std;

class Ponto {
 public:
  Ponto(int x_input, int y_input);
  ~Ponto();
  int getX();
  int getY();
  void setX(int x_input);
  void setY(int y_input);
  void setXY(int x_input, int y_input);
  void printPonto();

 private:
  Par<int>* coordenadas;
};

#endif
