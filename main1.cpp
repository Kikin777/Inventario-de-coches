#include <iostream>
using namespace std;
#include "reloj.cpp"


int main(){

    //Creacion de objeto
    Reloj miReloj;
    Reloj rolex;

    //Modificacion de atributos
    miReloj.segundos = 1000;
    miReloj.fecha = "14/11/2025";

    rolex.segundos = 200;
    rolex.fecha = "10/11/2024";

    //Invocar metodos
    miReloj.muestraReloj();
    cout << "---------------------"<< endl;
    rolex.muestraReloj();



    return 0;
};