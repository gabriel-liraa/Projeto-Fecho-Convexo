#include "../include/graham_radixsort.hpp"

int maxPolarAngle(Lista<Ponto *> *lista, Ponto *p0) {
  int max;

  max = getPolarAngle(p0, lista->getPrimeiro()->getKey());

  auto temp = lista->getPrimeiro()->getProx();
  while (temp != nullptr) {
    if (getPolarAngle(p0, temp->getKey()) > max) {
      max = getPolarAngle(p0, temp->getKey());
    }
    temp = temp->getProx();
  }

  return max;
}

void countSortPolar(Lista<Ponto *> *lista, int n, int exp, Ponto *p0) {
  Lista<Ponto *> *output = new Lista<Ponto *>();
  Lista<int> *count = new Lista<int>();

  int i;

  for (int c = 0; c < 10; c++) {
    count->addPrimeiro(0);
  }

  for (int c = 0; c < n; c++) {
    Ponto *p = new Ponto(0, 0);
    output->addPrimeiro(p);
  }

  int backup, backup_prev;

  for (i = 0; i < n; i++) {
    backup =
        count
            ->getNoByIndex(
                int(getPolarAngle(p0, lista->getNoByIndex(i)->getKey()) / exp) %
                10)
            ->getKey();

    count
        ->getNoByIndex(
            int(getPolarAngle(p0, lista->getNoByIndex(i)->getKey()) / exp) % 10)
        ->setKey(backup + 1);
  }

  for (i = 1; i < 10; i++) {
    backup = count->getNoByIndex(i)->getKey();
    backup_prev = count->getNoByIndex(i - 1)->getKey();
    count->getNoByIndex(i)->setKey(backup + backup_prev);
  }

  int pa;

  for (i = n - 1; i >= 0; i--) {
    pa = int(getPolarAngle(p0, lista->getNoByIndex(i)->getKey()));
    output->getNoByIndex(count->getNoByIndex((pa / exp) % 10)->getKey() - 1)
        ->setKey(lista->getNoByIndex(i)->getKey());

    backup =
        count
            ->getNoByIndex(
                int(getPolarAngle(p0, lista->getNoByIndex(i)->getKey()) / exp) %
                10)
            ->getKey();

    count
        ->getNoByIndex(
            int(getPolarAngle(p0, lista->getNoByIndex(i)->getKey()) / exp) % 10)
        ->setKey(backup - 1);
  }

  for (i = 0; i < n; i++) {
    lista->getNoByIndex(i)->setKey(output->getNoByIndex(i)->getKey());
  }
}

void radixSort(Lista<Ponto *> *lista, int n, Ponto *p0) {
  int max = maxPolarAngle(lista, p0);

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countSortPolar(lista, n, exp, p0);
  }
}
