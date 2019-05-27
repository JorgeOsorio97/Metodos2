#include "../libraries.h"
#include "../Vector.h"

void simpson_octavo(float h, Vector fxv){
    int size = fxv.get_size();  
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
    cout << "Complementando con regla de 3/8: "<<res<<endl;   //Se regresa y solo para hacer pruebas
}
void simpson_tercio(float h, Vector fxv){    
    int size = fxv.get_size();                                  //Vector auxiliar que contendra los valores multiplicados
    double res, sum = 0;
    float a = fxv.vector[0];
    float b = fxv.vector[fxv.get_size()-1];
    if((fxv.get_size() - 1 )%2 == 0){
        for (int i = 1; i < size - 1; i += 2){
        sum = sum+(4*fxv.vector[i]);
        }
        for (int i = 2; i < size - 2; i += 2){
            sum = sum+(2*fxv.vector[i]);
        }
        res = (h/3)*(a+b+sum);
        cout << "Resultado de la integral con regla de 1/3: "<<res <<endl;
    }else{
        for(int i = 0; i < size - 4; i++){
            for (int j = 1; j < size - 1; j += 2){
            sum = sum+(4*fxv.vector[j]);
            }
            for (int j = 2; j < size - 2; j += 2){
                sum = sum+(2*fxv.vector[j]);
            }
            res = (h/3)*(a+b+sum);    
        }
        simpson_octavo(h, fxv.vector[fxv.get_size() - 4]);
        
    }

    
}








