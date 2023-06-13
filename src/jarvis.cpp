#include "../include/jarvis.hpp"

#include <iostream>

Ponto* getLeftMost(Lista<Ponto*>* lista) {
  No<Ponto*>* temp = lista->getPrimeiro();
  Ponto* min = temp->getKey();
  while (temp != nullptr) {
    if (temp->getKey()->getX() < min->getX() ||
        ((temp->getKey()->getX() == min->getX()) &&
         (temp->getKey()->getY() > min->getY())))
      min = temp->getKey();
    temp = temp->getProx();
  }
  return min;
}

void jarvisMarch(Fecho* fecho, Lista<Ponto*>* lista_input) {
  Ponto* on_hull = getLeftMost(lista_input);
  Ponto* next_point = nullptr;
  Reta* r_1 = new Reta();
  Reta* r_2 = new Reta();
  Lista<Ponto*>* lista_fecho = new Lista<Ponto*>;

  int orientation = 0, condition_1 = 0, condition_2 = 0;

  while (1) {
    No<Ponto*>* temp = lista_input->getPrimeiro();
    next_point = lista_input->getPrimeiro()->getKey();
    lista_fecho->addUltimo(on_hull);
    while (temp != nullptr) {
      orientation = getOrientation(on_hull, next_point, temp->getKey());
      r_1->setPontos(on_hull, temp->getKey());
      r_2->setPontos(on_hull, next_point);

      condition_1 = (next_point == on_hull) || orientation == 1;
      condition_2 =
          orientation == 0 && (r_1->getDistancia() > r_2->getDistancia());

      if (condition_1 || condition_2) next_point = temp->getKey();

      temp = temp->getProx();
    }

    on_hull = next_point;
    if (on_hull == lista_fecho->getPrimeiro()->getKey()) break;
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

  delete r_1;
  delete r_2;
}
