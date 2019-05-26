#include "../libraries.h"
#include "../entrega2/sp.cpp"



float simpson_tercio(float paso, Vector fxv, float fx[], int size){
    fx[size] = {};                                    //Vector auxiliar que contendra los valores multiplicados
    float res;
    float mult = 0;
    for (int i = 1; i < (size - 1); i++){     //Iniciamos en 1 para tomar la segunda posicion y terminar en la penultima
        if (i%2 != 0){
            fx[i-1]= fxv.vector[i]*2;         //Se resta 1 para que lo vaya guardando desde la posicion 0 en el vector auxiliar
        }
        else{
            fx[i] = fxv.vector[i]*4;
        }
    mult = mult + fx[i];   //Suma de los valores centrados
    }
    int y = mult + fxv.vector[0]+ fxv.vector[sizeof(fxv.vector)- 1];  //Suma total
    res = y*(paso/3);
    return y;     //Se regresa y solo para hacer pruebas
}
float simpson_octavo(float paso, Vector fxv, float fx[], int size){
    fx[size] = {};                                    //Vector auxiliar que contendra los valores multiplicados
    float res;
    float mult = 0;
    for (int i = 1; i < (size - 1); i++){     //Iniciamos en 1 para tomar la segunda posicion y terminar en la penultima
        if (i%2 != 0){
            fx[i-1]= fxv.vector[i]*2;         //Se resta 1 para que lo vaya guardando desde la posicion 0 en el vector auxiliar
        }
        else{
            fx[i] = fxv.vector[i]*4;
        }
    mult = mult + fx[i];   //Suma de los valores centrados
    }
    int y = mult + fxv.vector[0]+ fxv.vector[sizeof(fxv.vector)- 1];  //Suma total
    res = y*(paso/3);
    return y;     //Se regresa y solo para hacer pruebas
}

float last_value(Vector x) {
  return sizeof(x) -1;
}


