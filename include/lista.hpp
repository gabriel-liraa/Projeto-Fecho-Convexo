#ifndef LISTA
#define LISTA

#include "no.hpp"

template <typename TIPO>
class Lista {
 public:
  Lista() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
  }

  ~Lista() {
    No<TIPO>* temp = primeiro;
    while (temp != nullptr) {
      No<TIPO>* proximo = temp->getProx();
      delete temp;
      temp = proximo;
    }
  }

  No<TIPO>* getPrimeiro() { return primeiro; }

  void addPrimeiro(TIPO input) {
    No<TIPO>* no_input = new No<TIPO>(input);
    no_input->setProx(primeiro);
    primeiro = no_input;
    if (tamanho == 0) {
      ultimo = no_input;
    }
    tamanho++;
  }

  void addUltimo(TIPO input) {
    No<TIPO>* no_input = new No<TIPO>(input);
    if (tamanho == 0) {
      primeiro = no_input;
    } else {
      ultimo->setProx(no_input);
    }
    ultimo = no_input;
    tamanho++;
  }

  void removePrimeiro() {
    No<TIPO>* temp = primeiro->getProx();
    delete primeiro;
    primeiro = temp;
    tamanho--;
  }

  int getTamanho() { return tamanho; }

  void printaLista() {
    No<TIPO>* temp = primeiro;
    while (temp != nullptr) {
      cout << temp->getKey() << endl;
      temp = temp->getProx();
    }
  }

  No<TIPO>* getNoByIndex(int i) {
    No<TIPO>* output = primeiro;
    int c = 0;
    while (c < i) {
      output = output->getProx();
      c++;
    }

    return output;
  }

 private:
  No<TIPO>* primeiro;
  No<TIPO>* ultimo;
  int tamanho;
};

#endif
