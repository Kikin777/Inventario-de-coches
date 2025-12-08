/*
Sistema de inventario de autos 
Enrique Rios Rosas
A01710460
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// clase motor representa el motor de un auto
class Motor {
private:
    int caballos;   // potencia del motor
    float litros;   // tamaño del motor

public:
    // constructor por defecto
    Motor() : caballos(0), litros(0.0f) {}

    // constructor con parámetros
    Motor(int caballos, float litros) : caballos(caballos), litros(litros) {}

    // regresa caballos del motor
    int getCaballos() const { return caballos; }

    // regresa litros del motor
    float getLitros() const { return litros; }

    // asigna caballos del motor
    void setCaballos(int c) { caballos = c; }

    // asigna litros del motor
    void setLitros(float l) { litros = l; }
};

// clase base auto con atributos generales
class Auto {
private:
    string marca;
    string modelo;
    string tipo;
    int anio;
    float precio;
    int kilometraje;
    bool disponible;
    float capacidadTanque;
    float consumo;
    Motor motor;

public:
    // constructor por defecto
    Auto()
        : marca(""), modelo(""), tipo(""), anio(0), precio(0.0f), kilometraje(0),
          disponible(true), capacidadTanque(0.0f), consumo(1.0f), motor() {}

    // constructor con parámetros
    Auto(string marca, string modelo, string tipo, int anio,
         float precio, int kilometraje, bool disponible,
         float capacidadTanque, float consumo, const Motor& motor)
        : marca(marca), modelo(modelo), tipo(tipo), anio(anio), precio(precio),
          kilometraje(kilometraje), disponible(disponible),
          capacidadTanque(capacidadTanque), consumo(consumo), motor(motor) {}

    // getters principales
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    string getTipo() const { return tipo; }
    int getAnio() const { return anio; }
    float getPrecio() const { return precio; }
    int getKilometraje() const { return kilometraje; }
    bool getDisponible() const { return disponible; }
    float getCapacidadTanque() const { return capacidadTanque; }
    float getConsumo() const { return consumo; }
    Motor getMotor() const { return motor; }

    // setters principales
    void setMarca(const string& m) { marca = m; }
    void setModelo(const string& m) { modelo = m; }
    void setTipo(const string& t) { tipo = t; }
    void setAnio(int a) { anio = a; }
    void setPrecio(float p) { precio = p; }
    void setKilometraje(int k) { kilometraje = k; }
    void setDisponible(bool d) { disponible = d; }
    void setCapacidadTanque(float c) { capacidadTanque = c; }
    void setConsumo(float c) { consumo = c; }
    void setMotor(const Motor& m) { motor = m; }

    // calcula autonomía aproximada del auto
    float calcularAutonomia() const {
        return (capacidadTanque / consumo) * 100.0f;
    }

    // muestra información general del auto
    virtual void mostrarInfo() const {
        cout << marca << " " << modelo << " - " << tipo << " (" << anio << ")" << endl;
        cout << "precio: $" << precio << endl;
        cout << "kilometraje: " << kilometraje << " km" << endl;
        cout << "disponible: " << (disponible ? "si" : "no") << endl;
        cout << "capacidad del tanque: " << capacidadTanque << " L" << endl;
        cout << "consumo: " << consumo << " L/100km" << endl;
        cout << "autonomia: " << calcularAutonomia() << " km" << endl;
        cout << "motor: " << motor.getCaballos() << " hp, " << motor.getLitros() << " L" << endl;
    }

    virtual ~Auto() {}
};

// clase sedan con atributo propio
class Sedan : public Auto {
private:
    int numeroPuertas;

public:
    // constructor por defecto
    Sedan() : Auto(), numeroPuertas(4) {}

    // constructor con parámetros
    Sedan(string marca, string modelo, int anio, float precio,
          int kilometraje, bool disponible, float capacidadTanque,
          float consumo, const Motor& motor, int numeroPuertas)
        : Auto(marca, modelo, "sedan", anio, precio, kilometraje,
               disponible, capacidadTanque, consumo, motor),
          numeroPuertas(numeroPuertas) {}

    // regresa número de puertas
    int getNumeroPuertas() const { return numeroPuertas; }

    // asigna número de puertas
    void setNumeroPuertas(int n) { numeroPuertas = n; }

    // muestra info con atributo propio
    void mostrarInfo() const override {
        Auto::mostrarInfo();
        cout << "puertas: " << numeroPuertas << endl;
        cout << "-----------------------------" << endl;
    }
};

// clase SUV con atributo extra
class SUV : public Auto {
private:
    bool traccion4x4;

public:
    // constructor por defecto
    SUV() : Auto(), traccion4x4(false) {}

    // constructor con parámetros
    SUV(string marca, string modelo, int anio, float precio,
        int kilometraje, bool disponible, float capacidadTanque,
        float consumo, const Motor& motor, bool traccion4x4)
        : Auto(marca, modelo, "suv", anio, precio, kilometraje,
               disponible, capacidadTanque, consumo, motor),
          traccion4x4(traccion4x4) {}

    // regresa si tiene tracción 4x4
    bool getTraccion4x4() const { return traccion4x4; }

    // asigna tracción 4x4
    void setTraccion4x4(bool t) { traccion4x4 = t; }

    // muestra info con atributo propio
    void mostrarInfo() const override {
        Auto::mostrarInfo();
        cout << "Traccion 4x4: " << (traccion4x4 ? "si" : "no") << endl;
        cout << "-----------------------------" << endl;
    }
};

// clase deportivo con aceleración 0–100
class Deportivo : public Auto {
private:
    float ceroACien;

public:
    // constructor por defecto
    Deportivo() : Auto(), ceroACien(0.0f) {}

    // constructor con parámetros
    Deportivo(string marca, string modelo, int anio, float precio,
              int kilometraje, bool disponible, float capacidadTanque,
              float consumo, const Motor& motor, float ceroACien)
        : Auto(marca, modelo, "deportivo", anio, precio, kilometraje,
               disponible, capacidadTanque, consumo, motor),
          ceroACien(ceroACien) {}

    // regresa tiempo 0–100
    float getCeroACien() const { return ceroACien; }

    // asigna tiempo 0–100
    void setCeroACien(float c) { ceroACien = c; }

    // muestra info con atributo propio
    void mostrarInfo() const override {
        Auto::mostrarInfo();
        cout << "aceleracion 0-100: " << ceroACien << " s" << endl;
        cout << "-----------------------------" << endl;
    }
};

// clase agencia maneja lista de autos
class Agencia {
private:
    string nombre;
    vector<Auto*> inventario;

public:
    // constructor con nombre
    Agencia(const string& nombre) : nombre(nombre) {}

    // agrega auto al inventario
    void agregarAuto(Auto* autoPtr) {
        inventario.push_back(autoPtr);
    }

    // muestra todos los autos
    void mostrarInventario() const {
        cout << "Inventario de la agencia: " << nombre << endl;
        cout << "=============================" << endl;
        for (auto autoPtr : inventario) {
            autoPtr->mostrarInfo();
        }
    }
};

int main() {
    Motor motorSedan(140, 1.8f);
    Motor motorSUV(200, 2.5f);
    Motor motorDeportivo(450, 3.8f);

    Sedan sedan1("Toyota", "Corolla", 2025, 350000, 15000, true,
                 50, 6.5, motorSedan, 4);

    SUV suv1("Nissan", "X-Trail", 2023, 520000, 22000, true,
             60, 8.0, motorSUV, true);

    Deportivo deportivo1("BMW", "M2", 2024, 1500000, 5000, true,
                         59, 10.5, motorDeportivo, 3.9);

    Agencia agencia("Agencia Matatena");
    agencia.agregarAuto(&sedan1);
    agencia.agregarAuto(&suv1);
    agencia.agregarAuto(&deportivo1);

    agencia.mostrarInventario();

    return 0;
}
