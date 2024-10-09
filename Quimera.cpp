#include <iostream>
using namespace std;

class Quimera: public Enemigo{
public:
string colmillos;

Quimera(string nom, int vida,  int mal, string col) : Enemigo(nom, vida, mal) {
  colmillos = col;
}

int atacarenemigo()const override{
  cout << "La cabeza de león de la quimera abre sus fauces y se lanza hacia su presa, intentando hundir sus colmillos en la carne de su víctima." << endl << endl << "Recibiste 30 de daño." << endl;
  return 30;
}

void muerte()const override{
  cout << "La quimera se desploma con un último suspiro, su colosal forma yaciendo inmóvil mientras la sangre empapa el suelo." << endl;
}

~Quimera(){};

};