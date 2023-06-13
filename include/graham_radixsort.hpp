#ifndef GRAHAM_RADIX
#define GRAHAM_RADIX

#include "aux.hpp"
#include "graham_mergesort.hpp"
#include "lista.hpp"
#include "ponto.hpp"

int maxPolarAngle(Lista<Ponto*>* lista, Ponto* p0);

void countSortPolar(Lista<Ponto*>* lista, int n, int exp, Ponto* p0);

void countSortDist(Lista<Ponto*>* lista, int n, int exp, Ponto* p0);

void radixSort(Lista<Ponto*>* lista, int n, Ponto* p0);

#endif
