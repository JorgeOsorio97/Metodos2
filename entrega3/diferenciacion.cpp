#include "../libraries.h"
#include "../entrega2/sp.cpp"

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
        
Vector generarVectorIE(float init, float end, float step){
    int size = (end-init)/step+1;
    cout<<"Size: "<<size<<endl;
    Vector res = Vector(size);
     for(int i=0; i<size; i++){
        res.vector[i]=init+(i*step);
    }
    return res;
}

Vector generarVectorIE2(float init, float end, float step){
    int size = (end-init)/step+1;
    cout<<"Size: "<<size<<endl;
    Vector res = Vector(size);
    int i = 0;
    while(init+(i*step)<=end){
        res.vector[i]=init+(i*step);
        i++;
    }
    if(!isEqual((init+((i-1)*step)),end)){
        return NULL;
    }

    return res;
}



main(){
    Vector x = generarVectorIE2(4,4.5,0.1);
    x.print_vector();
    Vector fx = Vector(x.get_size());
    fx.user_poblate(fx);
    float res = diferenciaCentrada(x,fx,1);
    if(res == NULL){
        cout<<"No se puede dividir el rango como se desea";
    }else{
        cout<<"Dif:"<<res<<endl;
    }

}