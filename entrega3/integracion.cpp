#include "../libraries.h"
#include "../Vector.h"


float simpson_octavo(float h, Vector fxv){
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
    return res;
}
void simpson_tercio(float h, Vector fxv){    
    int size = fxv.get_size();                                  //Vector auxiliar que contendra los valores multiplicados
    double res, sum = 0;
    float a = fxv.vector[0];
    float b = fxv.vector[fxv.get_size()-1];
    if((fxv.get_size() - 1 )%2 == 0){
        cout << "Numero de paneles par, se aplica regla de 1/3 normal: "<<endl;
        for (int i = 1; i < size - 1; i += 2){
        sum = sum+(4*fxv.vector[i]);
        }
        for (int i = 2; i < size - 2; i += 2){
            sum = sum+(2*fxv.vector[i]);
        }
        res = (h/3)*(a+b+sum);
        cout << "Resultado de la integral con regla de 1/3: "<<res <<endl;
    }else{
            cout << "El numero de paneles es impar, se complementa con regla de 3/8."<<endl;
            for (int j = 1; j < size - 4; j += 2){
            sum = sum+(4*fxv.vector[j]);
            }
            for (int j = 2; j < size - 4; j += 2){
                sum = sum+(2*fxv.vector[j]);
            }
            res = (h/3)*(a+b+sum);  
            Vector temp = Vector(fxv.get_size()-4);
            for(int i=0; i<4; i++){
                temp.vector[i] = fxv.vector[fxv.get_size() - 4+1];
            }
            cout << "Resultado de regla 1/3: "<< res <<endl;
            float res_final = simpson_octavo(h, temp) + res;  
            cout << "Aproximacion aplicando las dos reglas: "<<res_final<<endl;
        }
        
        
    }





float diferenciaCentrada(Vector x, Vector fx, int idx){
    if(idx < x.get_size()-1 && idx > 0){
        return (fx.vector[idx+1] - fx.vector[idx-1])/(2*(x.vector[1]-x.vector[0]));
    }
    return 0;
}

inline bool isEqual(double x, double y){
            const double epsilon = 1e-5;
            return abs(x - y) <= epsilon * abs(x);
        }
        
Vector generarVectorIE2(float init, float end, float step){
    int size = (end-init)/step+1;
    cout<<"Size: "<<size<<endl;
    Vector res = Vector(size);
     for(int i=0; i<size; i++){
        res.vector[i]=init+(i*step);
    }
    return res;
}

void generarVectorIE(float init, int size, float step, Vector &res){
    for(int i=0; i<size; i++){
        res.vector[i]=init+(i*step);
    }
    //res.print_vector();
}



float diferenciaCentrada(Vector &x, Vector &fx, int idxi, int idxf){
    int size = idxf-idxi+1;
    cout<<"Las derivadas solicitadas son"<<endl;
    cout<<"x \t f(x) \t f'(x)"<<endl;
    for(int i=0; i<size; i++){
        int pos = idxi+i;
        float der = diferenciaCentrada(x,fx,idxi+i);
        cout<<x.vector[idxi+i]<<" \t "<<fx.vector[idxi+i]<<" \t "<<der<<endl;
    }
}