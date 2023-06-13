#include "../include/graham_insertionsort.hpp"

void grahamInsertionSort(Lista<Ponto*>* lista, Ponto* p0) {
  No<Ponto*>* key = lista->getPrimeiro()->getProx();
  int j, i = 1;
  while (key != nullptr) {
    Ponto* key_backup = key->getKey();
    j = i - 1;

    while (j >= 0 && getPolarAngle(p0, lista->getNoByIndex(j)->getKey()) >=
                         getPolarAngle(p0, key_backup)) {
      if (getPolarAngle(p0, lista->getNoByIndex(j)->getKey()) ==
          getPolarAngle(p0, key_backup)) {
        if (getDistanciaPontos(p0, lista->getNoByIndex(j)->getKey()) >
            getDistanciaPontos(p0, key_backup)) {
          lista->getNoByIndex(j + 1)->setKey(lista->getNoByIndex(j)->getKey());
          j = j - 1;
        }
      } else {
        lista->getNoByIndex(j + 1)->setKey(lista->getNoByIndex(j)->getKey());
        j = j - 1;
      }
    }

    lista->getNoByIndex(j + 1)->setKey(key_backup);
    key = key->getProx();
    i++;
  }
}
