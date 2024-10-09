#include <iostream>
using namespace std;

class Enemigo : public Personaje{
public:
  int maldad;

public:
Enemigo(string nom, int vida,  int mal) : Personaje(nom, vida){
  maldad = mal;
  };

virtual void muerte() const = 0;
  //Pasa al siguiente nivel
  //Destructor de enemigo

virtual int atacarenemigo() const = 0;
 //Atacar al héroe


~Enemigo(){};

};