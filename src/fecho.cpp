#include "../include/fecho.hpp"

Fecho::Fecho() { lista = new Lista<Reta*>(); }

Fecho::~Fecho() { delete lista; }

void Fecho::addReta(Reta* r) { lista->addUltimo(r); }

void Fecho::printaFecho() {
  No<Reta*>* temp = lista->getPrimeiro();
  while (temp != nullptr) {
    temp->getKey()->getPrimeiroPonto()->printPonto();
    temp = temp->getProx();
  }
}

Lista<Reta*> Fecho::getLista() { return *lista; }
