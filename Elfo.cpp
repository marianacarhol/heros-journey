#include <iostream>
using namespace std;

class Elfo: public Heroe{
public:
int flechas;

Elfo(string nom, int vida, int tipo_h, int f) : Heroe(nom, vida, tipo_h){
  flechas = f;
};

int atacarheroe() const override{
  cout << endl << "Con una destreza sin igual, el elfo tensa su arco y dispara una flecha que vuela a través del aire con un zumbido silencioso, encontrando su marca con exactitud." << endl << endl << "Hiciste 25 de daño." << endl;
  return 25;
}

~Elfo(){};

};