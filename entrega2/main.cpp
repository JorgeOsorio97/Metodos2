#include "../libraries.h"
#include "interpolacion.cpp"
#include "sp.cpp"

int main(){
    int size, dec1, dec2, dec3, dec4, dec5, degree, pos;
    float *x, *fx, inter_point, new_val;
    Vector xv = Vector(size);
    Vector fxv = Vector(size);

        cout<<"Dame la cantidad de datos de tu tabla: "<<endl;
        cin>>size;
        x = (float*) malloc(size * sizeof(float));
        fx = (float*) malloc(size * sizeof(float));
        for(int i=0; i<size; i++){
            cout<< "Dame el valor de x en la posicion "<<i<<":"<<endl;
            cin>>x[i];
            cout<< "Dame el valor de f(x) en la posicion "<<i<<":"<<endl;
            cin>>fx[i];
        }
        NewtonInterpolation vec1 = NewtonInterpolation(x, fx, size);
        vec1.print_values();
        
        do{
            cout<< "¿Tus datos son correctos?\n1.Si.\t2.No"<<endl;
            cin>>dec1;
            if  (dec1 == 2){
                cout<< "¿Que vector quieres cambiar?\n1.x\t2.f(x)"<<endl;
                cin >> dec2;
                switch (dec2){
                    case 1:
                        cout<< "¿Que posicion quieres cambiar?"<<endl;
                        cin>> pos;
                        do{
                            if(pos >= size){
                                cout<<"Esa posicion no existe\nIngresa una posicion valida: "<<endl;
                                cin>> pos;
                            }
                        }while(pos>size);
                        cout<< "Dame el nuevo valor de la posicion "<<pos<<":"<<endl;
                        cin>> new_val;
                        vec1.set_x_val(pos, new_val);
                        vec1.print_values();
                        break;
                    
                    case 2:
                        cout<< "¿Que posicion quieres cambiar?"<<endl;
                        cin>> pos;
                        do{
                            if(pos >= size){
                                cout<<"Esa posicion no existe\nIngresa una posicion valida: "<<endl;
                                cin>> pos;
                            }
                            }while(pos>size);
                         cout<< "Dame el nuevo valor de la posicion "<<pos<<":"<<endl;
                        cin>> new_val;
                        vec1.set_fx_val(pos, new_val);
                        vec1.print_values();
                        break;
                }
            }    
        }while(dec1 == 2);

        xv.conversar(xv,x);
        fxv.conversar(fxv, fx);
        cout<<"¿Que quieres hacer?\n1.Interpolacion.\t2.Ajuste de Curvas.\3.Salir del programa."<<endl;
        cin>>dec3;
        switch (dec3){
            case 1:
                    cout<< "Dame el punto a interpolar: "<<endl;
                    cin>> inter_point;
                    cout<< "Dame el grado del polinomio: "<<endl;
                    cin>> degree;
                    if(degree >= size){
                        cout<< "Grado no valido";
                        break;
                    }
                    vec1.print_values();
                    vec1.test_value(inter_point, degree);
                
                break;
        
            case 2:
                
                    spline(xv, fxv, size);
                break;

            case 3:
                break;

        }
        

}

