#ifndef FECHO
#define FECHO

#include "lista.hpp"
#include "reta.hpp"

class Fecho {
 public:
  Fecho();
  ~Fecho();
  void addReta(Reta* r);
  void printaFecho();
  Lista<Reta*> getLista();

 private:
  Lista<Reta*>* lista;
};

#endif
