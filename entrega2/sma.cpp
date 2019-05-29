#include "sp.cpp" 
#include "../Vector.h"
void llenar(Vector &xl, Vector &fxl){
    xl.vector[0]=426.690002;
    xl.vector[1]=483.299988;
    xl.vector[2]=497.809998;
    xl.vector[3]=568.919983;
    xl.vector[4]=995.609985;
    xl.vector[5]=1422.300049;
    xl.vector[6]=2133.449951;
    xl.vector[7]=3555.75;
    xl.vector[8]=4266.899902;
    xl.vector[9]=7111.5;
    //xl.vector[10]=9.52;

    fxl.vector[0]=2468;
    fxl.vector[1]=2482;
    fxl.vector[2]=2483;
    fxl.vector[3]=2498;
    fxl.vector[4]=2584;
    fxl.vector[5]=2672;
    fxl.vector[6]=2811;
    fxl.vector[7]=3094;
    fxl.vector[8]=3236;
    fxl.vector[9]=3807;
    //fxl.vector[10]=3.6;





}
int main (){
    int size;
    // para usar llenar() el size siempre debe de ser 11
    // el problema no es de la funcion llenar por que intente llenandolo a mano y tambien me manda lo mismo
    int i=0;
    cout<<"Dime tamaño de tus datos"<<endl;
    cin>>size;
    Vector x = Vector(size);
    Vector fx = Vector(size);
    llenar(x,fx);
    //cout<<"llena tu vector x"<<endl;
    //x.user_poblate(x);
    //cout<<"llena tu vector f(x)"<<endl;
    //fx.user_poblate(fx);
    spline (x,fx,size);

}
