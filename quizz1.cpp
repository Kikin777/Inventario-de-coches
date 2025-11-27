#include <iostream>
using namespace std;


class Circulo {
private:
    float radio;
public:
    circulo(float r) {
        radio = r;
    }
    float get_Radio() {
        return radio;
    }
    void set_Radio(float r) {
        radio = r;
    }
    float area() {
        return 3.1416 * radio * radio;
    }
    float perimetro() {
        return 2 * 3.1416 * radio;
    }
};

class Cilindro {
private:
    float altura;
    Circulo base;
public:
    Cilindro(float r, float h) : base(r) {
        altura = h;
    }
    float get_Altura() {
        return altura;
    }
    void set_Altura(float h) {
        altura = h;
    }
    float volumen() {
        return base.area() * altura;
    }
};

int main() {
    float r, h;

    cout << "Ingresa el radio: ";
    cin >> r;

    cout << "Ingresa la altura: ";
    cin >> h;

    Cilindro c(r, h);

    cout << "Volumen: " << c.volumen();

    return 0;
}
