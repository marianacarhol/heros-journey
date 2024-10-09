#include <iostream>
#include <limits>
#include <ctime>
using namespace std;

class Partida{
private:
  string fecha;
public:
  string username = "";

Partida(string use, string fec){
  username = use;
  fecha = fec;
};

string comenzar(int o, string username){
    cout << "Bienvenid@ a Aventuras de los Héroes Errantes, una aventura de rol en la que deberás enfrentarte a tus enemigos y superar tus miedos. ¡Mucha suerte!" << endl << endl;

  while (true){
    cout << "¿Deseas iniciar la aventura?" << endl << "1. Si" << endl << "2. No" << endl;

    if (cin >> o && o == 1 || o == 2){
      break;
    } 
    else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error. Introduce un número válido." << endl<< endl;
    }
  }

  if (o == 1){
      cout<< endl << "Antes de empezar, ¿Cuál es tu username?"<< endl;
        cin >> username;
      cout << endl << "¡Comencemos, " << username << "!" << endl;
    }
    else {
      cout << endl <<"¡Hasta la proxima viajer@!" << endl;
      exit(0);
    }
  return username;
} 

void finalizar() {
    cout << "Juego ha terminado!" << endl;
    exit(0);
}

void setFecha(string &fech){
    fecha = fech;
}

string getFecha(){
  return fecha;
}


~Partida(){};

};

