#include <iostream>
using namespace std;

class Hechicero: public Heroe{
public:
int varita;

Hechicero(string nom, int vida, int tipo_h, int v) : Heroe(nom, vida, tipo_h){
  varita = v;
};

int atacarheroe() const override{
  cout << endl << "El hechicero extiende su mano y murmura palabras arcanas, una bola de fuego incandescente se forma y se lanza hacia sus enemigos, explotando en una tormenta de llamas." << endl << endl << "Hiciste 30 de daño." << endl;
  return 30;
}

~Hechicero(){};

};