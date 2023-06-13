#include "../include/ponto.hpp"

Ponto::Ponto(int x_input, int y_input) {
  Par<int>* values = new Par<int>(x_input, y_input);
  coordenadas = values;
}

Ponto::~Ponto() { delete coordenadas; }

int Ponto::getX() { return coordenadas->getPrimeiro(); }

int Ponto::getY() { return coordenadas->getSegundo(); }

void Ponto::setX(int x_input) { coordenadas->setPrimeiro(x_input); }

void Ponto::setY(int y_input) { coordenadas->setSegundo(y_input); }

void Ponto::setXY(int x_input, int y_input) {
  coordenadas->setPar(x_input, y_input);
}

void Ponto::printPonto() {
  cout << coordenadas->getPrimeiro() << " " << coordenadas->getSegundo()
       << endl;
}
