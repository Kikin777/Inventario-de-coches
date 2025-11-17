
/*Este proyecto es un sistema de invnetario de autoss. La idea es trabajar con una clase base 
(Auto) y diferentes tipos de autos como Sedan, SUV y Deportivo. 
Cada tipo comparte características básicas, pero también tiene su propio 
comportamiento (aceleracion, consumo de gasolina, autonomia, entre otros).  
*/


//Primeras lineas del codigo
#include <iostream>
using namespace std;

class Auto {
public:
    string marca;
    string modelo;
    string tipo;
    int año;

    void mostrar() {
        cout << marca << " " << modelo <<" " << tipo <<" (" << año << ")" << endl;
    }
};

int main() {

    // primer objeto de prueba
    Auto a1;
    a1.marca = "Toyota";
    a1.modelo = "Corolla";
    a1.tipo = "Sedan";
    a1.año = 2025;

    a1.mostrar();

    return 0;
}




   
