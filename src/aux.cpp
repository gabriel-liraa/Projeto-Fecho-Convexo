#include "../include/aux.hpp"

float getPolarAngle(Ponto* p1, Ponto* p2) {
  int x1 = p1->getX(), x2 = p2->getX();
  int y1 = p1->getY(), y2 = p2->getY();

  int dy = y2 - y1, dx = x2 - x1;

  return atan2(dy, dx);
}

float getDistanciaPontos(Ponto* p1, Ponto* p2) {
  int x1 = p1->getX(), x2 = p2->getX();
  int y1 = p1->getY(), y2 = p2->getY();

  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int getOrientation(Ponto* p1, Ponto* p2, Ponto* p3) {
  int x1 = p1->getX(), x2 = p2->getX(), x3 = p3->getX();
  int y1 = p1->getY(), y2 = p2->getY(), y3 = p3->getY();

  int d = (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);

  if (d > 0)
    return 1;
  else if (d < 0)
    return -1;
  else
    return 0;
}

void printaListaPontos(Lista<Ponto*>* l) {
  No<Ponto*>* temp = l->getPrimeiro();
  while (temp != nullptr) {
    temp->getKey()->printPonto();
    temp = temp->getProx();
  }
}
