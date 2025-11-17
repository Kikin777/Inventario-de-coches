#include <iostream>
using namespace std;

float millas_kilometros(float millas){
    float  kilometros = millas * 1.69;

    

    return kilometros;
}

float libras_kilos(float libras){
    float kilos = libras* 0.45;
    return kilos;
}

float going_to_mexico(float millas, float libras){
    float kilometros = millas_kilometros(millas);
    float kilos = libras_kilos(libras);
    cout << millas<< "millas son " << kilometros << "kilometros";
    cout << libras << "libras son " << kilos << "kilos"
    return going_to_mexico
    
}