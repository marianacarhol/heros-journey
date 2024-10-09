#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <list>
#include <ctime>
#include <iomanip>
#include <vector>
#include "Heroe.cpp"
#include "Enemigo.cpp"
#include "Hada.cpp"
#include "Hechicero.cpp"
#include "Elfo.cpp"
#include "Quimera.cpp"
#include "HombreLobo.cpp"
using namespace std;

Heroe* crearPersonaje(string nom, int tipo_h){
cout << endl << "¿Qué personaje mágico te gustaria ser?" << endl << "1. Hada" << endl << "2. Hechicero" << endl << "3. Elfo" << endl;
  while (true){
    if (cin >> tipo_h && tipo_h < 0 || tipo_h < 4){
      break;
    } 
    else{
      cin.clear(); 
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
      cout << endl << "Error. Introduce un número válido." << endl<< endl;
    }
  }

  cout << endl <<"¿Qué nombre te gustaria darle?" << endl;
  cin >> nom;
  cout << endl <<"¡Genial, " << nom <<"! Tienes una vida de 100." << endl;
  
   if (tipo_h == 1){
     return new Hada(nom, 100, tipo_h, 0);
   }
   else if (tipo_h == 2){
     return new Hechicero(nom, 100, tipo_h, 0);
   }
   else if(tipo_h == 3){
     return new Elfo(nom, 100, tipo_h, 0);
   }
};


int main(){
  int accion;
  int dmg_h;
  int dmg_e;
  
  Partida partida("", "11 de junio");
  partida.username = partida.comenzar(0,"");

  
  time_t now = time(nullptr);
  tm* local_time = localtime(&now);
  ostringstream fecha_stream;
  fecha_stream << put_time(local_time, "%Y-%m-%d %H:%M:%S");
  string fecha = fecha_stream.str();

  partida.setFecha(fecha);

  Heroe* heroe = crearPersonaje("h",1);
  Quimera quimera("", 100, 1,"");
  HombreLobo hombrelobo("", 95, 1,"");

  int suma = hombrelobo + quimera;
  
//NIVEL 1
  
  cout << endl << "NIVEL 1. Caminas por el Bosque Prohibido, rodeado de tranquilidad. De repente, una densa niebla envuelve el bosque y todo queda en silencio. Sientes una presencia inquietante y ves una figura oscura emerger de la niebla. Sus ojos brillan con intensidad, observándote amenazadoramente. El aire se vuelve frío mientras preparas tus armas. El misterioso enemigo avanza con movimientos etéreos. El combate ha comenzado." << endl << endl << "¿Qué deseas hacer?" << endl << "1. Atacar" << endl << "2. Huir" << endl;
  while (hombrelobo.hp > 0){
    while (!(cin >> accion) || (accion != 1 && accion != 2)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error. Introduce 1 para Atacar o 2 para Huir." << endl;
      }
    if (accion == 1){
      dmg_h = heroe -> atacarheroe();
      hombrelobo.hp = hombrelobo.hp - dmg_h;
      cout << "La vida del enemigo ha bajado a " << hombrelobo.hp << endl << endl;
      if (hombrelobo.hp <= 0){
        hombrelobo.muerte();
        cout << endl << "¡Has ganado!" << endl << "NIVEL 1 TERMINADO" << endl << endl;
        break;
      }
      dmg_e = hombrelobo.atacarenemigo();
      heroe -> hp = heroe -> hp - dmg_e;
      cout << "Tu vida ha bajado a " << heroe -> hp << endl << endl;
      if (heroe -> hp <= 0){
        cout << "¡Has perdido!" << endl;
        break;
      }
      cout << "¿Qué deseas hacer ahora?" << endl << "1. Atacar" << endl << "2. Huir" << endl;
      }
    

    else if (accion == 2){
      cout << endl << "¡Huiste, cobarde!" << endl;
      partida.finalizar();
    };
  };
    

// NIVEL 2
    heroe -> hp = heroe -> hp + 100;
    cout << endl << "NIVEL 2. Caminas por las ruinas de una antigua ciudad, rodeado de una inquietante quietud. De repente, una densa niebla cubre las calles y el silencio se vuelve abrumador. Sientes una presencia amenazante y ves una figura aterradora emerger de la neblina. Una quimera, con partes de diferentes criaturas fusionadas grotescamente, avanza hacia ti. Sus ojos múltiples brillan con una intensidad siniestra, observándote con malicia. El aire se vuelve gélido mientras preparas tus armas. La quimera se mueve con pasos pesados y etéreos. El combate ha comenzado." << endl << endl << "Tu vida es de "<< heroe -> hp << endl << endl << "¿Qué deseas hacer?" << endl << "1. Atacar" << endl << "2. Huir" << endl;
  while (quimera.hp > 0){
    while (!(cin >> accion) || (accion != 1 && accion != 2)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Error. Introduce 1 para Atacar o 2 para Huir." << endl;
      }
    if (accion == 1){
      dmg_h = heroe -> atacarheroe();
      quimera.hp = quimera.hp - dmg_h;
      cout << "La vida del enemigo ha bajado a " << quimera.hp << endl << endl;
      if (quimera.hp <= 0){
        quimera.muerte();
        cout << endl << "¡Has ganado!" << endl << "NIVEL 2 TERMINADO" << endl << endl;
        break;
      }
      dmg_e = quimera.atacarenemigo();
      heroe -> hp = heroe -> hp - dmg_e;
      cout << "Tu vida ha bajado a " << heroe -> hp << endl << endl;
      if (heroe -> hp <= 0){
        cout << "¡Has perdido!" << endl;
        break;
      }
      cout << "¿Qué deseas hacer ahora?" << endl << "1. Atacar" << endl << "2. Huir" << endl;
      }
    

    if (accion == 2){
      cout << endl << "¡Huiste, cobarde!" << endl;
      partida.finalizar();
    };
  };

  /////// TEXT ///////
  
  string x;
  x = partida.username;

  list <string> lista;
  lista.push_back(x);
  lista.push_back(partida.getFecha());
  lista.push_back(heroe -> nombre);
  lista.push_back(to_string(suma));

  vector <string> vec(lista.begin(), lista.end());

  try {
    ofstream file;
    file.open("stats" + x + ".txt");
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    file << "Username: " << vec[0] << endl
         << "Fecha de comienzo: " << vec[1] << endl
         << "Nombre del heroe: " << vec[2] << endl
         << "Enemigos enfrentados: " << vec[3] << endl;
      file.close();
  } catch (const exception& e) {
      cerr << "Error: " << e.what() << endl;
  }

  return 0;

  partida.finalizar();
};
