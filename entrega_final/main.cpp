#include "../libraries.h"
#include  "../entrega1/main.cpp"
#include "../entrega2/main.cpp"
#include "../entrega3/main.cpp"


int main(){
    int size, degree, pos, index;
    float *x, *fx, inter_point, new_val;

    cout<<"Bienvenido a la entrega final."<<endl;
    system("clear");
	cout<<"Programa por :"<<endl;
	cout<<"Jorge Aurelio Valdez Osorio"<<endl;
	cout<<"Baruc Isaac Osorio Davalos"<<endl;
	cout<<"Ulises Ramirez Calnacasco"<<endl;
	cout<<"Abraham Hernandez Martinez"<<endl<<endl;

    Etiqueta_1:
    cout<<"Bienvenido a la entrega final."<<endl;
    cout<<"¿Que deseas hacer?\n\n1.Sistemas de ecuaciones no lineales.\n\n2.Interpolacion y ajuste de curvas.\n\n3.Diferenciacion e Integracion"<<endl;
    int entrega;
    cin>>entrega;
    switch (entrega)
    {
    case 1:{
        entrega1();

    }
    case 2:{
        entrega2();

    }
    case 3:{
        entrega3();
    }   
        /* code */
        break;
    
    default:{
        cout<<"Elige solo entre las 3 opciones."<<endl;
    }
        break;
    }
}