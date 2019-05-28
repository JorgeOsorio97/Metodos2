#include "../libraries.h"
#include "../Vector.h"

float diferenciaCentrada(Vector &x, Vector &fx, int idx){
    if(idx < x.get_size()-1 && idx > 0){
        return (fx.vector[idx+1] - fx.vector[idx-1])/(2*(x.vector[1]-x.vector[0]));
    }
    return 0;
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



main(){
    Vector x = Vector(6);
    generarVectorIE(4,6,0.1,x);
    x.print_vector();
    Vector fx = Vector(x.get_size());
    fx.user_poblate(fx);
    float res = diferenciaCentrada(x,fx,1,3);
    if(res == NULL){
        cout<<"No se puede dividir el rango como se desea";
    }else{
        cout<<"Dif:"<<res<<endl;
    }

}