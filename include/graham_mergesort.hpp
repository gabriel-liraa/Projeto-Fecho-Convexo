#ifndef GRAHAM_MERGE
#define GRAHAM_MERGE

#include <cmath>

#include "aux.hpp"
#include "lista.hpp"
#include "reta.hpp"

void merge(Lista<Ponto*>* lista, int l, int m, int r, Ponto* p0);

void grahamMergeSort(Lista<Ponto*>* lista, int l, int r, Ponto* p0);

#endif
