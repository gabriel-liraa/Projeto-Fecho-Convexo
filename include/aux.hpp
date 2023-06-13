#ifndef AUX
#define AUX

#include <cmath>

#include "lista.hpp"

float getPolarAngle(Ponto* p1, Ponto* p2);

float getDistanciaPontos(Ponto* p1, Ponto* p2);

int getOrientation(Ponto* p1, Ponto* p2, Ponto* p3);

void printaListaPontos(Lista<Ponto*>* l);

#endif
