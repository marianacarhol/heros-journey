#include <iostream>
#include <string>
using namespace std;

class HombreLobo: public Enemigo{
public:
string garras;

HombreLobo(string nom, int vida,  int mal, string g) : Enemigo(nom, vida, mal){
 garras = g; 
};

int atacarenemigo()const override{
  cout << "Con movimientos rápidos y precisos, el hombre lobo salta hacia adelante, sus garras cortando el aire mientras se dirige hacia su enemigo." << endl << endl << "Recibiste 20 de daño." << endl;
  return 20;
}

void muerte()const override{
  cout << "Hombre Lobo ha muerto. El silencio de la noche se vuelve abrumador cuando te das cuenta de que ya no hay un aullido que rompa la quietud." << endl;
}

int operator+(const Quimera &quimera){
  int sumar = quimera.maldad + maldad;
  return sumar;
}

~HombreLobo(){};

};