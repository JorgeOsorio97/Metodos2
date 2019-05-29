#include "../libraries.h"
#include "interpolacion.cpp"
#include "sp.cpp"

void entrega2(){
    int size, dec1, dec2, dec3, dec4, dec5, dec6, decx, degree, pos, index;
    float *x, *fx, inter_point, new_val;
     Vector xv = NULL;
    Vector fxv = NULL;

    system("cls");
        Etiqueta_1:
        cout<<"Dame la cantidad de datos de tu tabla: "<<endl;
        cin>>size;
        xv = Vector(size);
        fxv = Vector(size);
        x = (float*) malloc(size * sizeof(float));
        fx = (float*) malloc(size * sizeof(float));
        Etiqueta_table:
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
                        xv.modify_element(pos, new_val);
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
                        fxv.modify_element(pos, new_val);
                        vec1.print_values();
                        break;
                }
            }    
        }while(dec1 == 2);

        

        Etiqueta_2:
        cout<<"¿Que quieres hacer?\n1.Interpolacion.\t2.Ajuste de Curvas.\t"<<endl;
        cin>>dec3;
        switch (dec3){
            case 1:{
                    Etiqueta_3: 
                    if(!vec1.check_equally_spaced()){
                            cout<<"Tus valores no estan igualmente espaciados"<<endl;
                            cout<<"¿Quieres volver a llenar tu tabla?\nRecuerda que el método de Newton requiere que los valores esten igualmente espaciados.\n\n1.Si.\t2.No.";
                            cin>> decx;
                            if(decx = 1){
                                goto Etiqueta_table;
                            }
                    }
                    cout<<"Vector igualmente espaciado"<<endl;
                    cout<< "Dame el punto a interpolar: "<<endl;
                    cin>> inter_point;
                    index = vec1.get_idx_value(inter_point, 0, size-1);
                    if(index == -1){
                        cout<< "Tu punto esta fuera de la tabla, por favor ingresa un punto valido: "<<endl;
                       goto Etiqueta_3;
                    }
                    cout<<"index = "<<index<<endl;
                    cout<< "Dame el grado del polinomio: "<<endl;
                    Etiqueta_z:
                    cin>> degree;
                    NewtonInterpolation::Type type = vec1.check_possible_polynomial_degree(degree, index);
                    if(type == NewtonInterpolation::ERROR){
                        cout << "El grado que quieres es mayor al tamaño de tu tabla y no hay suficientes puntos.\nPor favor ingresa un grado menor: "<<endl;
                        goto Etiqueta_z;
                    }
                    float result = vec1.test_value(inter_point, degree);
                    cout<<"El valor de fx("<<inter_point<<") = "<<result<<endl;
                    //vec1.print_values();

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
                            cout<< "¿Quieres volver al principio y llenar una nueva tabla?\n1.Si.\t2.No."<<endl;
                            cin>> dec6;
                            if(dec6==1){
                                vec1.~NewtonInterpolation();
                                goto Etiqueta_1;
                            }
                            
                        }

                    }

                
                break;
            }

            case 2:{
                    if (size < 3){
                        cout<< "Tienes muy pocos puntos, no es valido para este metodo.\tLlena otra vez tu tabla."<<endl;
                        goto Etiqueta_1;
                    }
                    spline(xv, fxv, size);
                    cout<< "¿Quieres hacer otro metodo con la misma tabla de valores?\n1.Si.\t2.No."<<endl;
                    cin>> dec4;
                    if(dec4==1){
                            goto Etiqueta_2;
                    }
                    else{ 
                        cout<< "¿Quieres volver al principio y llenar una nueva tabla?\n1.Si.\t2.No."<<endl;
                        cin>> dec6;
                        if(dec6==1){
                            xv.~Vector();
                            fxv.~Vector();
                            goto Etiqueta_1;
                        }
                    }

                break;
            }
        }
        
}

