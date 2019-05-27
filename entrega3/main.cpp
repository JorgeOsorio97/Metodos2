#include "../libraries.h"
#include "diferenciacion.cpp"
#include "integracion.cpp"

int main(){
    int size, firstp, suba, dec1, dec2, dec3, dec4, dec5, dec6, decx, degree, pos, index;
    float *xp, *fxp, inter_point, new_val, step;
    Vector xv = NULL;
    Vector fxv = NULL;

    system("cls");
	cout<<"Programa por :"<<endl;
	cout<<"Jorge Aurelio Valdez Osorio"<<endl;
	cout<<"Baruc Isaac Osorio Davalos"<<endl;
	cout<<"Ulises Ramirez Calnacasco"<<endl;
	cout<<"Abraham Hernandez Martinez"<<endl<<endl;

        Etiqueta_x:
        cout<<"Dame el punto inicial de tu tabla: "<<endl;
        cin>>firstp;
        cout<<"Dame el tamaño de paso: "<<endl;
        cin>>step;
        cout<<"Dime el numero de datos en la tabla?: "<<endl;
        cin>>size;
        
        
    xv = Vector(size);
    generarVectorIE(firstp,size, step, xv);
     xv.print_vector();
     fxv = Vector(xv.get_size());
    //fxv.user_poblate(fxv);
    for(int i=0; i<xv.get_size();i++){
            cout<<"Dame el valor en la posicion "<<i<<":"<<endl;
            cin>>fxv.vector[i];
            
    }
    
     float res = diferenciaCentrada(xv,fxv,1);
     if(res == NULL){
         cout<<"No se puede dividir el rango como se desea";
     }else{
         cout<<"Dif:"<<res<<endl;
     }
  

    Etiqueta_1:
      do{
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
                        
                        break;
                 }
              
        }while(dec1 == 2);

    Etiqueta_2:
        cout<<"Â¿Que quieres hacer?\n1.Interpolacion.\t2.Ajuste de Curvas.\t"<<endl;
        cin>>dec3;
        switch(dec3){

        case 1:




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
                            cout<< "Bueno, adios"<<endl;
                            xv.~Vector();
                            fxv.~Vector();
                            }
                        }
                    }
        break;

        case 2: 


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
                            cout<< "Bueno, adios"<<endl;
                            xv.~Vector();
                            fxv.~Vector();
                            }
                        }
                    }
        break;

        }





 }
 
   
