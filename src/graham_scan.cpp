#include "../include/graham_scan.hpp"

Ponto* getBottomMost(Lista<Ponto*>* lista) {
  auto temp = lista->getPrimeiro();
  Ponto* min = temp->getKey();

  while (temp != nullptr) {
    if (temp->getKey()->getY() < min->getY()) {
      min = temp->getKey();
    }

    else if (temp->getKey()->getY() == min->getY()) {
      if (temp->getKey()->getX() < min->getX()) {
        min = temp->getKey();
      }
    }
    temp = temp->getProx();
  }

  return min;
}

void grahamScan(Fecho* fecho, Lista<Ponto*>* lista, int option) {
  auto p0 = getBottomMost(lista);

  switch (option) {
    case 0:
      grahamMergeSort(lista, 0, lista->getTamanho() - 1, p0);
      break;

    case 1:
      grahamInsertionSort(lista, p0);
      break;

    case 2:
      radixSort(lista, lista->getTamanho(), p0);
      grahamInsertionSort(lista, p0);
      break;
  }

  Lista<Ponto*>* lista_fecho = new Lista<Ponto*>();

  auto loop = lista->getPrimeiro();
  while (loop != nullptr) {
    while (lista_fecho->getTamanho() >= 2 &&
           getOrientation(lista_fecho->getNoByIndex(1)->getKey(),
                          lista_fecho->getNoByIndex(0)->getKey(),
                          loop->getKey()) != 1) {
      lista_fecho->removePrimeiro();
    }
    lista_fecho->addPrimeiro(loop->getKey());

    loop = loop->getProx();
  }

  No<Ponto*>* temp = lista_fecho->getPrimeiro();

  while (temp->getProx() != nullptr) {
    Reta* reta_fecho = new Reta();
    reta_fecho->setPontos(temp->getKey(), temp->getProx()->getKey());
    fecho->addReta(reta_fecho);
    temp = temp->getProx();
  }

  Reta* reta_fecho = new Reta();
  reta_fecho->setPontos(temp->getKey(), lista_fecho->getPrimeiro()->getKey());
  fecho->addReta(reta_fecho);
}
