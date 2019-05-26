#include <stdio.h>

int main(){
    int size = 10;
    int fx[size];
    for (int i = 0; i < size - 1; i++){
        if (i%2 != 0){
            fx[i] = 2;      //Se resta 1 para que lo vaya guardando desde la posicion 0 en el vector auxiliar
        }
        else{
            fx[i] = 4;
        }
       printf("%d\n", fx);
        
    }
    return 0;
}