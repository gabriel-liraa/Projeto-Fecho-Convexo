#include "../include/graham_mergesort.hpp"

#include <cmath>

void merge(Lista<Ponto*>* lista, int l, int m, int r, Ponto* p0) {
  int n1 = m - l + 1;
  int n2 = r - m;

  Lista<Ponto*>* temp1 = new Lista<Ponto*>();
  Lista<Ponto*>* temp2 = new Lista<Ponto*>();

  auto p1 = lista->getNoByIndex(l);
  auto mid = lista->getNoByIndex(m);

  while (p1 != mid->getProx()) {
    temp1->addUltimo(p1->getKey());
    p1 = p1->getProx();
  }
  while (p1 != nullptr) {
    temp2->addUltimo(p1->getKey());
    p1 = p1->getProx();
  }

  int index_n1 = 0, index_n2 = 0;
  int index_merged = l;

  while (index_n1 < n1 && index_n2 < n2) {
    if (getPolarAngle(p0, temp1->getNoByIndex(index_n1)->getKey()) <
        getPolarAngle(p0, temp2->getNoByIndex(index_n2)->getKey())) {
      lista->getNoByIndex(index_merged)
          ->setKey(temp1->getNoByIndex(index_n1)->getKey());
      index_n1++;

    }

    else if (getPolarAngle(p0, temp1->getNoByIndex(index_n1)->getKey()) ==
             getPolarAngle(p0, temp2->getNoByIndex(index_n2)->getKey())) {
      if (getDistanciaPontos(p0, temp1->getNoByIndex(index_n1)->getKey()) <
          getDistanciaPontos(p0, temp2->getNoByIndex(index_n2)->getKey())) {
        lista->getNoByIndex(index_merged)
            ->setKey(temp1->getNoByIndex(index_n1)->getKey());
        index_n1++;
      }

      else {
        lista->getNoByIndex(index_merged)
            ->setKey(temp2->getNoByIndex(index_n2)->getKey());
        index_n2++;
      }
    }

    else {
      lista->getNoByIndex(index_merged)
          ->setKey(temp2->getNoByIndex(index_n2)->getKey());
      index_n2++;
    }

    index_merged++;
  }

  while (index_n1 < n1) {
    lista->getNoByIndex(index_merged)
        ->setKey(temp1->getNoByIndex(index_n1)->getKey());
    index_n1++;
    index_merged++;
  }

  while (index_n2 < n2) {
    lista->getNoByIndex(index_merged)
        ->setKey(temp2->getNoByIndex(index_n2)->getKey());
    index_n2++;
    index_merged++;
  }

  delete temp1;
  delete temp2;
}

void grahamMergeSort(Lista<Ponto*>* lista, int l, int r, Ponto* p0) {
  if (l < r) {
    int m = l + (r - l) / 2;

    grahamMergeSort(lista, l, m, p0);
    grahamMergeSort(lista, m + 1, r, p0);

    merge(lista, l, m, r, p0);
  }
}
