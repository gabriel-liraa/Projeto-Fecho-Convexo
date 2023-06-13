#ifndef JARVIS
#define JARVIS

#include "aux.hpp"
#include "fecho.hpp"

Ponto* getLeftMost(Lista<Ponto*>* lista);

int getOrientation(Ponto* p1, Ponto* p2, Ponto* p3);

void jarvisMarch(Fecho* fecho, Lista<Ponto*>* lista);

#endif
