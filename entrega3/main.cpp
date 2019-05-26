#include "../libraries.h"
#include "diferenciacion.cpp"
#include "integracion.cpp"

int main(){
    int size, firstp, lastp, suba, step, dec1, dec2, dec3, dec4, dec5, dec6, decx, degree, pos, index;
    float *x, *fx, inter_point, new_val;
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
        
        for(int i=firstp; i<lastp; i+=step){
        
        	size+=i;
        	xv = Vector(size);
        	fxv = Vector(size);
		}
		
        x = (float*) malloc(size * sizeof(float));
        fx = (float*) malloc(size * sizeof(float));
 