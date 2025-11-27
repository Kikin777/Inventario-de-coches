
/*Este proyecto es un sistema de invnetario de autoss. La idea es trabajar con una clase base 
(Auto) y diferentes tipos de autos como Sedan, SUV y Deportivo. 
Cada tipo comparte características básicas, pero también tiene su propio 
comportamiento (aceleracion, consumo de gasolina, autonomia, entre otros).  
*/


#include <iostream>
using namespace std;

class Auto {
public:
    string marca;
    string modelo;
    string tipo;
    int año;
    float precio;
    int kilometraje;
    bool disponible;
    float capacidadTanque;  // litros
    float consumo;          // litros cada 100 km

    float calcularAutonomia() {
        return (capacidadTanque / consumo) * 100;
    }

    void mostrar() {
        cout << marca << " " << modelo << " - " << tipo << " (" << año << ")" << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Km: " << kilometraje << endl;
        cout << "Tanque: " << capacidadTanque << " L" << endl;
        cout << "Consumo: " << consumo << " L/100km" << endl;
        cout << "Autonomia: " << calcularAutonomia() << " km" << endl;
        cout << "Disponible: " << (disponible ? "Sí" : "No") << endl;
    }
};

class InventarioAutos {
public:
    Auto autos[10];
    int total = 0;

    void agregarAuto(Auto a) {
        autos[total] = a;
        total++;
    }

    void mostrarInventario() {
        cout << "INVENTARIO" << endl;
        for(int i = 0; i < total; i++) {
            autos[i].mostrar();
            
        }
    }
};

int main() {

    InventarioAutos inventario;

    Auto a1;
    a1.marca = "BMW";
    a1.modelo = "M2";
    a1.tipo = "Coupe Deportivo";
    a1.año = 2025;
    a1.precio = 1700000;
    a1.kilometraje = 0;
    a1.disponible = true;
    a1.capacidadTanque = 52; 
    a1.consumo = 9; 

    Auto a2;
    a2.marca = "Toyota";
    a2.modelo = "Corolla";
    a2.tipo = "Sedan";
    a2.año = 2024;
    a2.precio = 700000;
    a2.kilometraje = 10000;
    a2.disponible = true;
    a2.capacidadTanque = 55; 
    a2.consumo = 6.5; 

    inventario.agregarAuto(a1);
    inventario.agregarAuto(a2);

    inventario.mostrarInventario();

    return 0;
}
