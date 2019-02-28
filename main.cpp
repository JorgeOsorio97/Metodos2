#include "libraries.h"
#include "jacobiana.cpp"
/*void normaEspectral(Vector &nuevo, Vector &anterior, float x){
	Vector rno=Vector(2);
	nuevo.restByVector(anterior, &rno);
	to=max(abs(rno.vector[0]),abs(rno.vector[1]);
	
	
	
}*/

int main(){
	int ecu,ite;
	int it=0;
	int to=10;
	float tol,x,y,z;
	Vector x2=Vector(2);
	Vector x3=Vector(3);
	Vector s2=Vector(2);
	Vector s3=Vector(3);
	Vector xn2=Vector(2);
	Vector xn3=Vector(3);
	Matrix j2i=Matrix(2);
	Matrix j3i=Matrix(3);
	Vector res2=Vector(2);
	
	Matrix j2=Matrix(2);
	Matrix j3=Matrix(3);
	cout<<"Seleccione el sistema de ecuaciones que desea resolver: (digite el numero que le corresponda)"<<endl<<endl;

	cout<<"1. f_1(x,y)=x^2+xy-10=0 ; f_2(x,y)= y+3xy^2-50=0 "<<endl<<endl;
	cout<<"2. f_1(x,y)=x^2+y^2-9=0 ; f_2(x,y)=-e^x-2y-3=0 "<<endl<<endl;
	cout<<"3. f_1(x,y,z)=2x^2-4x+y^2+3z^2+6z+2=0 ; f_2(x,y,z)=x^2+y^2-2y+2z^2-5=0 ; f_3(x,y,z)=3x^2-12x+y^2-3z^2+8=0"<<endl<<endl;
	cout<<"4. f_1(x,y,z)=x^2-4x+y^2=0 ; f_2(x,y,z)=x^2-x-12y+1=0 ; f_3(x,y,z)=3x^2-12x+y^2-3z^2+8=0"<<endl<<endl;

/*
	cout<<"1. f_1(x,y)=x²+xy-10=0 ; f_2(x,y)= y+3xy²-57=0 "<<endl<<endl;
	cout<<"2. f_1(x,y)=4-x²-y²=0 ; f_2(x,y)=1-e^x-y=0 "<<endl<<endl;
	cout<<"3. f_1(x,y,z)=2x²-4x+y²+3z²+6z+2=0 ; f_2(x,y,z)=x²+y²-2y+2z²-5=0 ; f_3(x,y,z)=3x²-12x+y²+3z²+8=0"<<endl<<endl;
	cout<<"4. f_1(x,y,z)=x²-4x+y²=0 ; f_2(x,y,z)=x²-x-12y+1=0 ; f_3(x,y,z)=3x²-12x-3z²+8=0"<<endl<<endl;
	*/

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
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y)=x^2+xy-10=0 ; f_2(x,y)= y+3xy^2-50=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<")"<<endl;
			while(it<ite && to>tol){
			sistEcu1(x, y,s2); //evaluo la funcion
			jacobiana1(x,y,j2);//mando a hacer la jacobiana
			j2i=j2.invertir_matriz();//invierto la jacobiana
			j2i.print_matrix();//es print de prueba pero no me imprime numeros, desde aqui hay problemas
			j2i.multiplyByVector(s2,&res2);//multiplivco inversa por evaluada
			x2.restByVector(res2,&xn2);//resto punto inicial menos la multiplicacion anterior
			xn2.print_vector();//de prueba
			//to=xn2.normaEspectral(x2);//no esta hecha la funcion de norma espectral pero deberia debolver un escalar float no un vector
			it++;
			
			
			
		}
			
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
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y)=x^2+y^2-9=0 ; f_2(x,y)=-e^x-2y-3=0"
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
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y,z)=2x^2-4x+y^2+3z^2+6z+2=0 ; f_2(x,y,z)=x^2+y^2-2y+2z^2-5=0 ; f_3(x,y,z)=3x^2-12x+y^2-3z^2+8=0"
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
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y,z)=x^2-4x+y^2=0 ; f_2(x,y,z)=x^2-x-12y+1=0 ; f_3(x,y,z)=3x^2-12x+y^2-3z^2+8=0"
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
