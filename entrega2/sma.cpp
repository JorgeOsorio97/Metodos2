#include "sp.cpp" 
void llenar(Vector &xl, Vector &fxl){
    xl.vector[0]=0.62;
    xl.vector[1]=0.74;
    xl.vector[2]=1;
    xl.vector[3]=1.78;
    xl.vector[4]=2.42;
    xl.vector[5]=3.16;
    xl.vector[6]=4.7;
    xl.vector[7]=7;
    xl.vector[8]=9.08;
    xl.vector[9]=10.36;
    xl.vector[10]=9.52;

    fxl.vector[0]=2.14;
    fxl.vector[1]=2.96;
    fxl.vector[2]=2.8;
    fxl.vector[3]=3.6;
    fxl.vector[4]=3.44;
    fxl.vector[5]=3.16;
    fxl.vector[6]=1.04;
    fxl.vector[7]=2;
    fxl.vector[8]=0.54;
    fxl.vector[9]=1.94;
    fxl.vector[10]=3.6;





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
    /*cout<<"llena tu vector x"<<endl;
    x.user_poblate(x);
    cout<<"llena tu vector f(x)"<<endl;
    fx.user_poblate(fx);*/
    spline (x,fx,size);

}
