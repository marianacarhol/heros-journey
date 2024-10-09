#include <iostream>
#include "Personaje.cpp"
#include "Partida.cpp"
using namespace std;

class Heroe : public Personaje {

public:
  int tipo_heroe;

Heroe(string nom, int vida, int tipo_h) : Personaje (nom, vida) {
tipo_heroe = tipo_h;
};

virtual int atacarheroe() const = 0;
 //Atacar al enemigo

 ~Heroe(){};

};
