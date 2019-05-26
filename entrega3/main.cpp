#include "../libraries.h"
#include "diferenciacion.cpp"
#include "integracion.cpp"

int main(){
    int size, firstp, lastp, suba, step, dec1, dec2, dec3, dec4, dec5, dec6, decx, degree, pos, index;
    float *xp, *fxp, inter_point, new_val;
    Vector xv = NULL;
    Vector fxv = NULL;

    system("cls");
	cout<<"Programa por :"<<endl;
	cout<<"Jorge Aurelio Valdez Osorio"<<endl;
	cout<<"Baruc Isaac Osorio Davalos"<<endl;
	cout<<"Ulises Ramirez Calnacasco"<<endl;
	cout<<"Abraham Hernandez Martinez"<<endl<<endl;

        Etiqueta_1:
        cout<<"Dame el punto inicial de tu tabla: "<<endl;
        cin>>firstp;
        cout<<"Dame el punto final de tu tabla: "<<endl;
        cin>>lastp;
        cout<<"Cuantas sub areas tendra la tabla?: "<<endl;
        cin>>suba;
        
        step=(lastp-firstp)/suba;
        
        
      
     xv = generarVectorIE(firstp,lastp, step);
     xv.print_vector();
     fxv = Vector(xv.get_size());
    //fxv.user_poblate(fxv);
    for(int i=0; i=x.get_size;i++){
            fxv.vector[i]=5;
    }
    
     float res = diferenciaCentrada(xv,fxv,1);
     if(res == NULL){
         cout<<"No se puede dividir el rango como se desea";
     }else{
         cout<<"Dif:"<<res<<endl;
     }

 }
 


 /*do{
            cout<< "Â¿Tus datos son correctos?\n1.Si.\t2.No"<<endl;
            cin>>dec1;
            if  (dec1 == 2){
                
                        cout<< "Â¿Que posicion quieres cambiar?"<<endl;
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
              
        }while(dec1 == 2);*/

