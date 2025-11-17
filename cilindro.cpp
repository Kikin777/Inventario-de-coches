
//Hacer comentarios




#include <iostream>
#include <cmath>
using namespace std;

int main(){

    //Declarar variables y constante 
    float radio;
    float altura;
    const float PI=3.1415;

    //Pedir al usuario radio y altura
    cout << "Escribe el radio:";
    cin >> radio;
    cout << "Escribe la altura:";
    cin >> altura;

    //Calcular el volumen del cilindro
    float volumen = PI * pow (radio,2) * altura; //Exponencial: pow (variable, N)
    float resultado = volumen / 2;

    //Mostrar resultado
    cout << "El volumen del medio cilindro con radio" <<radio<< "y altura"  //C++ sigue leyendo mientras no haya ";"
    <<altura<< "es: " <<resultado<< endl;




    return 0;
}