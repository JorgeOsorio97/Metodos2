#include "../libraries.h"
#include "integracion.cpp"
#include "../Vector.h"

void entrega3 (){
    int size, firstp, suba, dec1, dec2, dec3, dec4, dec5, dec6, decx, degree, pos, indexin, indexfin;
    float *xp, *fxp, inter_point, new_val, step;

    system("clear");
        Etiqueta_x:
        cout<<"Dame el punto inicial de tu tabla: "<<endl;
        cin>>firstp;
        cout<<"Dame el tamaño de paso: "<<endl;
        cin>>step;
        cout<<"Dime el numero de datos en la tabla: "<<endl;
        cin>>size;
        
        
    Vector xv = Vector(size);
    generarVectorIE(firstp,size, step, xv);
    xv.print_vector();
    Vector fxv = Vector(size);
    
    //fxv.user_poblate(fxv);
    for(int i=0; i<size;i++){
            cout<<"Dame el valor en la posicion "<<i<<" de fx:"<<endl;
            cin>>fxv.vector[i];
            
    }
    //fxv.print_vector();
    
    Etiqueta_1:
      do{
            Etiqueta_p:
            cout<<"El valor del vector x es: "<<endl;
            xv.print_vector();
            cout<<"El valor del vector fx es: "<<endl;
            fxv.print_vector();
            cout<< "Â¿Tus datos son correctos?\n1.Si.\t2.No"<<endl;
            cin>>dec1;
            if  (dec1 == 2){

                
                        cout<< "Â¿Que posicion quieres cambiar?"<<endl;
                        Etiqueta_y:
                        cin>> pos;
                        do{
                            if(pos >= xv.get_size()){
                                cout<<"Esa posicion no existe\nIngresa una posicion valida: "<<endl;
                                goto Etiqueta_y;
                            }
                            }while(pos>size);
                        cout<< "Dame el nuevo valor de la posicion "<<pos<<":"<<endl;
                        cin>> new_val;
                        fxv.modify_element(pos, new_val);
                        goto Etiqueta_p;
                        
                        break;
                 }
              
        }while(dec1 == 2);

    Etiqueta_2:
        cout<<"Â¿Que quieres hacer?\n1.Integracion.\t2.Diferenciacion.\t"<<endl;
        cin>>dec3;
        switch(dec3){

        case 1:

            simpson_tercio(step, fxv);


         cout<< "Â¿Quieres hacer otro metodo con la misma tabla de valores?\n1.Si.\t2.No."<<endl;
                    cin>> dec4;
                    if(dec4==1){
                            goto Etiqueta_2;
                    }
                    else{ 
                        cout<<"¿Quieres modificar la tabla ya existente?\n1.Si.\t2.No."<<endl;
                        cin >> dec5;
                        if (dec5==1){
                            goto Etiqueta_1;
                        }else{
                        cout<< "Â¿Quieres volver al principio y llenar una nueva tabla?\n1.Si.\t2.No."<<endl;
                        cin>> dec6;
                        if(dec6==1){
                            xv.~Vector();
                            fxv.~Vector();
                            goto Etiqueta_x;
                        }
                        else{
                            cout<< "Bueno, adios"<<endl;
                            xv.~Vector();
                            fxv.~Vector();
                            }
                        }
                    }
        break;

        case 2: 
            cout<<"Para este metodo indique el intervalo que quiere integrar"<<endl;
            cout<<"Indice Inicial"<<endl;
            cin>> indexin;
            cout<<"Indice Final"<<endl;
            cin>> indexfin;

            diferenciaCentrada(xv,fxv,indexin,indexfin);

            cout<< "Â¿Quieres hacer otro metodo con la misma tabla de valores?\n1.Si.\t2.No."<<endl;
                    cin>> dec4;
                    if(dec4==1){
                            goto Etiqueta_2;
                    }
                    else{ 
                        cout<<"¿Quieres modificar la tabla ya existente?\n1.Si.\t2.No."<<endl;
                        if (dec5==1){
                            goto Etiqueta_1;
                        }else{
                        cout<< "Â¿Quieres volver al principio y llenar una nueva tabla?\n1.Si.\t2.No."<<endl;
                        cin>> dec6;
                        if(dec6==1){
                            xv.~Vector();
                            fxv.~Vector();
                            goto Etiqueta_x;
                        }
                        else{
                            xv.~Vector();
                            fxv.~Vector();
                            }
                        }
                    }
        break;

        }




//return 0;
 }
 
   
   
