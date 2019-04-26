#include "../libraries.h"
#include "interpolacion.cpp"
#include "sp.cpp"

int main(){
    int size, dec1, dec2, dec3, dec4, dec5, dec6, degree, pos;
    float *x, *fx, inter_point, new_val;
    Vector xv = Vector(size);
    Vector fxv = Vector(size);

    system("cls");
	cout<<"Programa por :"<<endl;
	cout<<"Jorge Aurelio Valdez Osorio"<<endl;
	cout<<"Baruc Isaac Osorio Davalos"<<endl;
	cout<<"Ulises Ramirez Calnacasco"<<endl;
	cout<<"Abraham Hernandez Martinez"<<endl<<endl;

        Etiqueta_1:
        cout<<"Dame la cantidad de datos de tu tabla: "<<endl;
        cin>>size;
        x = (float*) malloc(size * sizeof(float));
        fx = (float*) malloc(size * sizeof(float));
        for(int i=0; i<size; i++){
            cout<< "Dame el valor de x en la posicion "<<i<<":"<<endl;
            cin>>x[i], xv.vector[i];
            cout<< "Dame el valor de f(x) en la posicion "<<i<<":"<<endl;
            cin>>fx[i], fxv.vector[i];
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
                        Etiqueta_x:
                        cin>> pos;
                        do{
                            if(pos >= size){
                                cout<<"Esa posicion no existe\nIngresa una posicion valida: "<<endl;
                                goto Etiqueta_x;
                            }
                        }while(pos>size);
                        cout<< "Dame el nuevo valor de la posicion "<<pos<<":"<<endl;
                        cin>> new_val;
                        vec1.set_x_val(pos, new_val);
                        vec1.print_values();
                        break;
                    
                    case 2:
                        cout<< "¿Que posicion quieres cambiar?"<<endl;
                        Etiqueta_y:
                        cin>> pos;
                        do{
                            if(pos >= size){
                                cout<<"Esa posicion no existe\nIngresa una posicion valida: "<<endl;
                                goto Etiqueta_y;
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

        Etiqueta_2:
        cout<<"¿Que quieres hacer?\n1.Interpolacion.\t2.Ajuste de Curvas.\t3.Salir del programa."<<endl;
        cin>>dec3;
        switch (dec3){
            case 1:
                    Etiqueta_3: 
                    cout<< "Dame el punto a interpolar: "<<endl;
                    cin>> inter_point;
                    cout<< "Dame el grado del polinomio: "<<endl;
                    Etiqueta_z:
                    cin>> degree;
                    if(degree >= size){
                        cout<< "No se puede generar un polinomio de ese grado.\n\nDame un grado valido: ";
                        goto Etiqueta_z;
                    }
                    vec1.test_value(inter_point, degree);
                    vec1.print_values();
                    cout<< "¿Quieres interpolar otro punto?\n1.Si.\t2.No."<<endl;
                    cin>> dec4;
                    if(dec4==1){
                        goto Etiqueta_3;
                    }
                    else{
                        cout<< "¿Quieres hacer otro metodo con la misma tabla de valores?\n1.Si.\t2.No."<<endl;
                        cin>> dec5;
                        if(dec5==1){
                            goto Etiqueta_2;
                        }
                        else{ 
                            cout<< "¿Quieres volver al principio y llenar una nueva tabla?\n1.Si.\t2.No.";
                            cin>> dec6;
                            if(dec6==1){
                                vec1.~NewtonInterpolation();
                                goto Etiqueta_1;
                            }
                            else{
                                cout<< "Bueno, adios";
                            }
                        }

                    }

                
                break;
        
            case 2:
                    if (size < 3){
                        cout<< "Tienes muy pocos puntos, no es valido para este metodo.\tLlena otra vez tu tabla.";
                        goto Etiqueta_1;
                    }
                    spline(xv, fxv, size);
                    cout<< "¿Quieres hacer otro metodo con la misma tabla de valores?\n1.Si.\t2.No."<<endl;
                    cin>> dec4;
                    if(dec4==1){
                            goto Etiqueta_2;
                    }
                    else{ 
                        cout<< "¿Quieres volver al principio y llenar una nueva tabla?\n1.Si.\t2.No.";
                        cin>> dec6;
                        if(dec6==1){
                            goto Etiqueta_1;
                        }
                        else{
                            cout<< "Bueno, adios";
                        }
                    }

                break;
            case 3:
                break;

        }
        

}

