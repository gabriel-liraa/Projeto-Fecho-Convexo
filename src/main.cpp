#include <chrono>
#include <fstream>
#include <iostream>

#include "../include/aux.hpp"
#include "../include/fecho.hpp"
#include "../include/graham_radixsort.hpp"
#include "../include/graham_scan.hpp"
#include "../include/jarvis.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Arquivo de entrada não fornecido." << endl;
    return 0;
  }

  string filename = argv[1];
  ifstream file(filename);

  if (!file.is_open()) {
    cout << "Arquivo não encontrado." << endl;
    return 0;
  }

  int x, y;
  Lista<Ponto *> *lista_jarvis = new Lista<Ponto *>();
  Lista<Ponto *> *lista_merge = new Lista<Ponto *>();
  Lista<Ponto *> *lista_insertion = new Lista<Ponto *>();
  Lista<Ponto *> *lista_radix = new Lista<Ponto *>();
  while (file >> x >> y) {
    Ponto *p = new Ponto(x, y);
    lista_jarvis->addUltimo(p);
    lista_merge->addUltimo(p);
    lista_insertion->addUltimo(p);
    lista_radix->addUltimo(p);
  }

  file.close();

  Fecho *f = new Fecho();
  Fecho *f2 = new Fecho();
  Fecho *f3 = new Fecho();
  Fecho *f4 = new Fecho();

  auto start1 = chrono::high_resolution_clock::now();
  jarvisMarch(f, lista_jarvis);
  auto end1 = chrono::high_resolution_clock::now();
  double duration_jarvis =
      chrono::duration_cast<chrono::duration<double>>(end1 - start1).count();

  auto start2 = chrono::high_resolution_clock::now();
  grahamScan(f2, lista_merge, 0);
  auto end2 = chrono::high_resolution_clock::now();
  double duration_merge =
      chrono::duration_cast<chrono::duration<double>>(end2 - start2).count();

  auto start3 = chrono::high_resolution_clock::now();
  grahamScan(f3, lista_insertion, 1);
  auto end3 = chrono::high_resolution_clock::now();
  double duration_insertion =
      chrono::duration_cast<chrono::duration<double>>(end3 - start3).count();

  auto start4 = chrono::high_resolution_clock::now();
  grahamScan(f4, lista_radix, 2);
  auto end4 = chrono::high_resolution_clock::now();
  double duration_radix =
      chrono::duration_cast<chrono::duration<double>>(end4 - start4).count();

  f->printaFecho();

  cout.precision(3);
  cout << '\n';
  cout << "GRAHAM+MERGESORT: " << fixed << duration_merge << "s" << '\n';
  cout << "GRAHAM+INSERTIONSORT: " << fixed << duration_insertion << "s"
       << '\n';
  cout << "GRAHAM+LINEAR: " << fixed << duration_radix << "s" << '\n';
  cout << "JARVIS: " << fixed << duration_jarvis << "s" << '\n';
}
