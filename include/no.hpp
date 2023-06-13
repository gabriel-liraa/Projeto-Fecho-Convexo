#ifndef NO
#define NO

#include <iostream>

#include "ponto.hpp"

using namespace std;

template <typename TIPO>
class No {
 public:
  No(TIPO key_input) {
    key = key_input;
    prox = nullptr;
  }

  ~No() {}

  TIPO getKey() { return key; }

  void setKey(TIPO key_input) { key = key_input; }

  No* getProx() { return prox; }

  void setProx(No* prox_input) { prox = prox_input; }

 private:
  TIPO key;
  No* prox;
};

#endif
