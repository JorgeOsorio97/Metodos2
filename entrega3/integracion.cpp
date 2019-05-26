#include "../libraries.h"
#include "../Vector.h"

float simpson_tercio(float h, Vector fxv, int size){                                      //Vector auxiliar que contendra los valores multiplicados
    double res, sum = 0;
    float a = fxv.vector[0];
    float b = fxv.vector[fxv.get_size()-1];
    for (int i = 1; i < size - 1; i += 2){
        sum = sum+(4*fxv.vector[i]);
    }
    for (int i = 2; i < size - 2; i += 2){
        sum = sum+(2*fxv.vector[i]);
    }
    res = (h/3)*(a+b+sum);
    return res;
}

float simpson_octavo(float h, Vector fxv, int size){
    double res, sum = 0;
    float a = fxv.vector[0];
    float b = fxv.vector[fxv.get_size()-1];
    for (int i = 1; i < size - 1; i++){
        if(i%3 == 0){
            sum = sum + (2*fxv.vector[i]);
        }
        else{
            sum = sum+(3*fxv.vector[i]);
        }
    }
 
    res = 3*h/8*(a+b+sum);
    return res;   //Se regresa y solo para hacer pruebas
}



