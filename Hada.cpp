#include <iostream>
using namespace std;

class Hada: public Heroe{
public:
int alas;

Hada(string nom, int vida, int tipo_h, int a) : Heroe(nom, vida, tipo_h){
  alas = a;
};

int atacarheroe() const override{
  cout << endl << "Con una sonrisa radiante, el hada invoca la magia de los elementos, convocando raíces retorcidas que se alzan desde el suelo para enredar a sus enemigos y restringir su movimiento." << endl << endl << "Hiciste 20 de daño." << endl;
  return 20;
}

~Hada(){};

};