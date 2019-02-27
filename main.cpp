#include "libraries.h"
#include "matrix.cpp"
#include "jacobiana.cpp"
#include "libraries.h"

int main(){
	int ecu, ite;
	float tol,x,y,z,sx;
	Vector x2=Vector(2);
	Vector x3=Vector(3);
	Vector s1=Vector(2);
	cout<<"Seleccione el sistema de ecuaciones que desea resolver: (digite el numero que le corresponda)"<<endl<<endl;
	cout<<"1. f_1(x,y)=x^2+xy-10=0 ; f_2(x,y)= y+3xy^2-57=0 "<<endl<<endl;
	cout<<"2. f_1(x,y)=4-x^2-y^2=0 ; f_2(x,y)=1-e^x-y=0 "<<endl<<endl;
	cout<<"3. f_1(x,y,z)=2x^2-4x+y^2+3z^2+6z+2=0 ; f_2(x,y,z)=x^2+y^2-2y+2z^2-5=0 ; f_3(x,y,z)=3x^2-12x+y^2+3z^2+8=0"<<endl<<endl;
	cout<<"4. f_1(x,y,z)=x^2-4x+y^2=0 ; f_2(x,y,z)=x^2-x-12y+1=0 ; f_3(x,y,z)=3x^2-12x-3z^2+8=0"<<endl<<endl;
	cin>>ecu;
	cout<<"Tolerancia de eror: (en caso de no tener, pon 0)"<<endl;
	cin>>tol;
	cout<<"Maximo de iteraciones: (si no lo tienes definido, pon 100)"<<endl;
	cin>>ite;
	
	switch(ecu){
		case 1:{
			cout<<"Dame el punto inical (x,y)"<<endl;
			cout<<"x=";
			cin>>x;
			cout<<"y=";
			cin>>y;
			x2.vector[0]=x;
			x2.vector[1]=y;
			system("cls");
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y)=x^2+xy-10=0 ; f_2(x,y)= y+3xy^2-57=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<")"<<endl;
			s1=sistEcu1(x,y);
			jacobiana1(x, y);
			sx=s1.vector[0];
			cout<<sx;
			break;
		}
				
		case 2:{cout<<"Dame el punto inical (x,y)"<<endl;
			cout<<"x=";
			cin>>x;
			cout<<"y=";
			cin>>y;
			x2.vector[0]=x;
			x2.vector[1]=y;
			system("cls");
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y)=4-x^2-y^2=0 ; f_2(x,y)=1-e^x-y=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<")"<<endl;
			
			
			break;
		}
		
		case 3:{cout<<"Dame el punto inical (x,y,z)"<<endl;
			cout<<"x=";
			cin>>x;
			cout<<"y=";
			cin>>y;
			cout<<"z=";
			cin>>z;
			x3.vector[0]=x;
			x3.vector[1]=y;
			x3.vector[2]=z;
			system("cls");
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y,z)=2x^2-4x+y^2+3z^2+6z+2=0 ; f_2(x,y,z)=x^2+y^2-2y+2z^2-5=0 ; f_3(x,y,z)=3x^2-12x+y^2+3z^2+8=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<","<<z<<")"<<endl;
			
			
			break;
		}
			
		case 4:	{
			cout<<"Dame el punto inical (x,y,z)"<<endl;
			cout<<"x=";
			cin>>x;
			cout<<"y=";
			cin>>y;
			cout<<"z=";
			cin>>z;
			x3.vector[0]=x;
			x3.vector[1]=y;
			x3.vector[2]=z;
			system("cls");
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y,z)=x^2-4x+y^2=0 ; f_2(x,y,z)=x^2-x-12y+1=0 ; f_3(x,y,z)=3x^2-12x-3z^2+8=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<","<<z<<")"<<endl;
			
			
			break;
		}
		
		default: {system("cls");
			cout<<"No escogio una opcion valida";
			break;
		}
		
		
	}
	
	
	return 0;
}
