#include "integracion.cpp"

int main (){
    Vector fxv = NULL;
    float *fx;
    int size = 8;
    fxv = Vector(size);
    fx = (float*) malloc(size * sizeof(float));        
        for(int i=0; i<size; i++){
            //cout<< "Dame el valor de x en la posicion "<<i<<":"<<endl;
            cout<< "Dame el valor de f(x) en la posicion "<<i<<":"<<endl;
            cin>>fxv.vector[i];
        }
    simpson_tercio(.5, fxv);
    //cout <<simpson_octavo(.5, fxv, size)<<endl;
}