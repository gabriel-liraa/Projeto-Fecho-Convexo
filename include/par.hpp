#ifndef PAR
#define PAR

template <typename TIPO>
class Par {
 public:
  Par(TIPO v1_input, TIPO v2_input) {
    v1 = v1_input;
    v2 = v2_input;
  }

  ~Par() {}

  TIPO getPrimeiro() { return v1; }

  TIPO getSegundo() { return v2; }

  void setPar(TIPO v1_input, TIPO v2_input) {
    v1 = v1_input;
    v2 = v2_input;
  }

  void setPrimeiro(TIPO v1_input) { v1 = v1_input; }

  void setSegundo(TIPO v2_input) { v2 = v2_input; }

 private:
  TIPO v1, v2;
};

#endif
