#include "../libraries.h"
#include "../entrega2/sp.cpp"
#include "integracion.cpp"

int main (){
    Vector fxv = NULL;
    float *fx;
    int size = 2;
    fxv = Vector(size);
    fx = (float*) malloc(size * sizeof(float));        
        for(int i=0; i<size; i++){
            //cout<< "Dame el valor de x en la posicion "<<i<<":"<<endl;
            cout<< "Dame el valor de f(x) en la posicion "<<i<<":"<<endl;
            cin>>fxv.vector[i];
        }
    //cout<<simpson_tercio(.3, fxv, fx, size)<<endl;
    int x[] = {1, 2, 3, 4};
    cout << last_value(fxv.vector[size]);
}