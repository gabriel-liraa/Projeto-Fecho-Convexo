#ifndef RETA
#define RETA

#include <cmath>

#include "ponto.hpp"
class Reta {
 public:
  Reta();
  ~Reta();
  Ponto* getPrimeiroPonto();
  Ponto* getSegundoPonto();
  void setPrimeiroPonto(Ponto* p_1);
  void setSegundoPonto(Ponto* p_2);
  void setPontos(Ponto* p_1, Ponto* p_2);
  float getDistancia();

 private:
  Par<Ponto*>* pontos;
};

#endif
