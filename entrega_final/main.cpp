#include "../libraries.h"
#include  "../entrega1/main.cpp"
#include "../entrega2/main.cpp"
#include "../entrega3/main.cpp"


int main(){

    int dec1;

    cout<<"Bienvenido a la entrega final."<<endl;
    system("cls");
	cout<<"Programa por :"<<endl;
	cout<<"Jorge Aurelio Valdez Osorio"<<endl;
	cout<<"Baruc Isaac Osorio Davalos"<<endl;
	cout<<"Ulises Ramirez Calnacasco"<<endl;
	cout<<"Abraham Hernandez Martinez"<<endl<<endl;

    
    cout<<"Bienvenido a la entrega final."<<endl;
    Etiqueta_1:
    cout<<"¿Que deseas hacer?\n\n1.Sistemas de ecuaciones no lineales.\n\n2.Interpolacion y ajuste de curvas.\n\n3.Diferenciacion e Integracion"<<endl;
    int entrega;
    cin>>entrega;
    switch (entrega)
    {
    case 1:{
        entrega1();
        cout << "\n\n¿Quieres hacer otra accion?\n\n1.Si.\t2.No\n"<<endl;
        cin >> dec1;
        if(dec1 == 1)
            goto Etiqueta_1;
        else
            break;

    }
    case 2:{
        entrega2();
        cout << "\n\n¿Quieres hacer otra accion?\n\n1.Si.\t2.No\n"<<endl;
        cin >> dec1;
        if(dec1 == 1)
            goto Etiqueta_1;
        else
            break;

    }
    case 3:{
        entrega3();
        cout << "\n\n¿Quieres hacer otra accion?\n\n1.Si.\t2.No\n"<<endl;
        cin >> dec1;
        if(dec1 == 1)
            goto Etiqueta_1;
        else
            break;
    }   
        /* code */
        break;
    
    default:{
        cout<<"Elige solo entre las 3 opciones."<<endl;
    }
        break;
    }
}