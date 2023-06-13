#ifndef GRAHAM_SCAN
#define GRAHAM_SCAN

#include "aux.hpp"
#include "fecho.hpp"
#include "graham_insertionsort.hpp"
#include "graham_mergesort.hpp"
#include "graham_radixsort.hpp"

Ponto* getBottomMost(Lista<Ponto*>* lista);

void grahamScan(Fecho* fecho, Lista<Ponto*>* lista, int option);

#endif
