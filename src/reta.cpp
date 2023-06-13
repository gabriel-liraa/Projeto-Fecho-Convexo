#include "../include/reta.hpp"

#include <cmath>
#include <iostream>

using namespace std;

Reta::Reta() {
  Par<Ponto*>* values = new Par<Ponto*>(nullptr, nullptr);
  pontos = values;
}

Reta::~Reta() { delete pontos; }

Ponto* Reta::getPrimeiroPonto() {
  if (pontos->getPrimeiro() == nullptr) {
    throw 1;
  }
  return pontos->getPrimeiro();
}

Ponto* Reta::getSegundoPonto() {
  if (pontos->getSegundo() == nullptr) {
    throw 1;
  }
  return pontos->getSegundo();
}

void Reta::setPrimeiroPonto(Ponto* p_1) { pontos->setPrimeiro(p_1); }

void Reta::setSegundoPonto(Ponto* p_2) { pontos->setSegundo(p_2); }

void Reta::setPontos(Ponto* p_1, Ponto* p_2) {
  pontos->setPrimeiro(p_1);
  pontos->setSegundo(p_2);
}

float Reta::getDistancia() {
  int x1 = pontos->getPrimeiro()->getX(), x2 = pontos->getSegundo()->getX();
  int y1 = pontos->getPrimeiro()->getY(), y2 = pontos->getSegundo()->getY();
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
