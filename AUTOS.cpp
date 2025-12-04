/*Este proyecto es un sistema de invnetario de autoss. La idea es trabajar con una clase base 
(Auto) y diferentes tipos de autos como Sedan, SUV y Deportivo. 
Cada tipo comparte características básicas, pero también tiene su propio 
comportamiento (aceleracion, consumo de gasolina, autonomia, entre otros).  
*/

#include <iostream>
#include <string>
using namespace std;

class Motor {
public:
    string tipo;
    int caballos;
    float consumoBase;
};

class Auto {
public:
    string marca;
    string modelo;
    string tipo;
    int año;
    float precio;
    int kilometraje;
    bool disponible;
    float capacidadTanque;
    float consumo;
    Motor motor;

    float calcularAutonomia() {
        return (capacidadTanque / consumo) * 100;
    }

    virtual void mostrar() {
        cout << marca << " " << modelo << " - " << tipo << " (" << año << ")" << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Km: " << kilometraje << endl;
        cout << "Tanque: " << capacidadTanque << " L" << endl;
        cout << "Consumo: " << consumo << " L/100km" << endl;
        cout << "Autonomia: " << calcularAutonomia() << " km" << endl;
        cout << "Motor: " << motor.tipo << ", " << motor.caballos << " hp" << endl;
        cout << "Disponible: " << (disponible ? "Sí" : "No") << endl;
    }
};

class Sedan : public Auto {
public:
    int numeroPuertas;

    void mostrar() {
        Auto::mostrar();
        cout << "Puertas: " << numeroPuertas << endl;
        cout << "------------------------" << endl;
    }
};

class SUV : public Auto {
public:
    bool traccion4x4;

    void mostrar() {
        Auto::mostrar();
        cout << "Tracción 4x4: " << (traccion4x4 ? "Sí" : "No") << endl;
        cout << "------------------------" << endl;
    }
};

class Deportivo : public Auto {
public:
    float ceroACien;

    void mostrar() {
        Auto::mostrar();
        cout << "0-100 km/h: " << ceroACien << " s" << endl;
        cout << "------------------------" << endl;
    }
};

class InventarioAutos {
public:
    Auto* autos[10];
    int total;

    InventarioAutos() {
        total = 0;
    }

    void agregarAuto(Auto* a) {
        if (total < 10) {
            autos[total] = a;
            total++;
        }
    }

    void mostrarInventario() {
        cout << "INVENTARIO" << endl;
        for (int i = 0; i < total; i++) {
            autos[i]->mostrar();
        }
    }
};

int main() {
    InventarioAutos inventario;

    Deportivo a1;
    a1.marca = "BMW";
    a1.modelo = "M2";
    a1.tipo = "Coupe Deportivo";
    a1.año = 2025;
    a1.precio = 1700000;
    a1.kilometraje = 0;
    a1.disponible = true;
    a1.capacidadTanque = 52;
    a1.consumo = 9;
    a1.motor.tipo = "Gasolina";
    a1.motor.caballos = 460;
    a1.motor.consumoBase = 9;
    a1.ceroACien = 4.2;

    Sedan a2;
    a2.marca = "Toyota";
    a2.modelo = "Corolla";
    a2.tipo = "Sedan";
    a2.año = 2024;
    a2.precio = 700000;
    a2.kilometraje = 10000;
    a2.disponible = true;
    a2.capacidadTanque = 55;
    a2.consumo = 6.5;
    a2.motor.tipo = "Gasolina";
    a2.motor.caballos = 140;
    a2.motor.consumoBase = 6.5;
    a2.numeroPuertas = 4;

    SUV a3;
    a3.marca = "Toyota";
    a3.modelo = "RAV4";
    a3.tipo = "SUV";
    a3.año = 2023;
    a3.precio = 850000;
    a3.kilometraje = 5000;
    a3.disponible = false;
    a3.capacidadTanque = 55;
    a3.consumo = 7.8;
    a3.motor.tipo = "Gasolina";
    a3.motor.caballos = 200;
    a3.motor.consumoBase = 7.8;
    a3.traccion4x4 = true;

    inventario.agregarAuto(&a1);
    inventario.agregarAuto(&a2);
    inventario.agregarAuto(&a3);

    inventario.mostrarInventario();

    return 0;
}
