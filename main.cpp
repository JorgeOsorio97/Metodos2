#include "libraries.h"
#include "jacobiana.cpp"

int main(){
	int ecu,ite, p, c,t, r;
	
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
	Vector res3=Vector(3);
	
	Matrix j2=Matrix(2);
	Matrix j3=Matrix(3);
	t=1;
	while(t==1){
	int it=0;
	float to=-1555;
	int k=0;
	system("cls");
	cout<<"Programa por :"<<endl;
	cout<<"Jorge Aurelio Valdez Osorio"<<endl;
	cout<<"Baruc Isaac Osorio Davalos"<<endl;
	cout<<"Ulises Ramirez Calnacasco"<<endl;
	cout<<"Abraham Hernandez Martinez"<<endl;
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
	cout<<"Tolerancia de error: (en caso de no tener, pon 0)"<<endl;
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
			c=1;
			while(c==1){
			
				cout<<"�Es correcto tu punto inicial?"<<endl<<"1. Si     2. No"<<endl;
				cin>>p;
				switch(p){
					case 1:{
						c=0;
						break;
					}
					case 2:{
						cout<<"Vuelve a escribrir tu punto inical(x,y)"<<endl;
						cout<<"x=";
						cin>>x;
						cout<<"y=";
						cin>>y;
						x2.vector[0]=x;
						x2.vector[1]=y;
						
						break;
					}
					default:{
						cout<<"Elige entre las opciones 1 o 2"<<endl;
						break;
					}
				}
			
			}
			system("cls");
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y)=x^2+xy-10=0 ; f_2(x,y)= y+3xy^2-50=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<")"<<endl;
			bool a = it<ite;
			//cout<<"result ites: "<<a<<endl;
			cout<<to<<endl;
			while (a && (to>tol || to == -1555)){
				cout<<"Iteracion #"<<k<<endl;
				sistEcu1(x, y,s2); //evaluo la funcion
				s2.print_vector();
				jacobiana1(x,y,j2);//mando a hacer la jacobiana
				cout<<"jacobiana"<<endl;
				j2.print_matrix();    //imprime jacobiana
				j2.get_determinant();//llamo a determinante
				cout<<"determinante"<<endl<<j2.get_determinant()<<endl;//imprimo determinante
				j2i=j2.invertir_matriz();//invierto la jacobiana
				cout<<"inversa"<<endl;
				j2i.print_matrix();   //imprimo inversa
				j2i.multiplyByVector(s2,&res2);//multiplivco inversa por evaluada
				cout<<"multiplicacion matriz con vector"<<endl; //hago la multiplicacion
				res2.print_vector();   //imprimo la multiplicacion
				x2.restByVector(res2,&xn2);//resto punto inicial menos la multiplicacion anterior
				cout<<"punto anterior"<<endl; //punto anterior
				x2.print_vector();
				cout<<"nuevo punto"<<endl;
				xn2.print_vector();//de prueba
				Vector::normaEspectral(xn2,x2, &to);
				cout<<"norma: "<<to<<endl;
				x2.vector[0]=xn2.vector[0];
				x2.vector[1]=xn2.vector[1];
				x=x2.vector[0];
				y=x2.vector[1];
				k++;
				it++;
				a = it<ite;
			}
			cout<<"La raiz del sistema esta en:"<<endl;
			x2.print_vector();
			cout<<"�Desea resolver otro sistema?"<<endl<<"1. Si      2. No"<<endl;
			cin>>p;
			switch(p){
				case 1:{
					break;
				}
				case 2:{
					t=0;
					break;
				}
				default:{
					cout<<"Elige entre las opciones 1 o 2"<<endl;
					break;
				}
			}
			
			break;
		}
				
		case 2:{
			cout<<"Dame el punto inical (x,y)"<<endl;
			cout<<"x=";
			cin>>x;
			cout<<"y=";
			cin>>y;
			x2.vector[0]=x;
			x2.vector[1]=y;
			c=1;
			while(c==1){
				cout<<"�Es correcto tu punto inicial?"<<endl<<"1. Si     2. No"<<endl;
				cin>>p;
				switch(p){
					case 1:{
						c=0;
						break;
					}
					case 2:{
						cout<<"Vuelve a escribrir tu punto inical(x,y)"<<endl;
						cout<<"x=";
						cin>>x;
						cout<<"y=";
						cin>>y;
						x2.vector[0]=x;
						x2.vector[1]=y;
						
						break;
					}
					default:{
						cout<<"Elige entre las opciones 1 o 2"<<endl;
						break;
					}
				}
			
		}
			system("cls");
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y)=x^2+y^2-9=0 ; f_2(x,y)=-e^x-2y-3=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<")"<<endl;
			bool a = it<ite;
			while (a &&  (to>tol || to == -1555)){
				cout<<"Iteracion #"<<k<<endl;
				sistEcu2(x, y,s2); //evaluo la funcion
				cout<<"Evaluacion"<<endl;
				s2.print_vector();
				jacobiana2(x,y,j2);//mando a hacer la jacobiana
				cout<<"jacobiana"<<endl;
				j2.print_matrix();    //imprime jacobiana
				j2.get_determinant();//llamo a determinante
				cout<<"determinante"<<endl<<j2.get_determinant()<<endl;//imprimo determinante
				j2i=j2.invertir_matriz();//invierto la jacobiana
				cout<<"inversa"<<endl;
				j2i.print_matrix();   //imprimo inversa
				j2i.multiplyByVector(s2,&res2);//multiplivco inversa por evaluada
				cout<<"multiplicacion matriz con vector"<<endl; //hago la multiplicacion
				res2.print_vector();   //imprimo la multiplicacion
				x2.restByVector(res2,&xn2);//resto punto inicial menos la multiplicacion anterior
				cout<<"punto anterior"<<endl; //punto anterior
				x2.print_vector();
				cout<<"nuevo punto"<<endl;
				xn2.print_vector();//de prueba
				Vector::normaEspectral(xn2,x2, &to);
				cout<<"norma: "<<to<<endl;
				x2.vector[0]=xn2.vector[0];
				x2.vector[1]=xn2.vector[1];
				x=x2.vector[0];
				y=x2.vector[1];
				k++;
				it++;
				a = it<ite;
			}
			cout<<"La raiz del sistema esta en:"<<endl;
			x2.print_vector();
			cout<<"�Desea resolver otro sistema?"<<endl<<"1. Si      2. No"<<endl;
			cin>>p;
			switch(p){
				case 1:{
					break;
				}
				case 2:{
					t=0;
					break;
				}
				default:{
					cout<<"Elige entre las opciones 1 o 2"<<endl;
					break;
				}
			}
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
			c=1;
			while(c==1){
			
				cout<<"�Es correcto tu punto inicial?"<<endl<<"1. Si     2. No"<<endl;
				cin>>p;
				switch(p){
					case 1:{
						c=0;
						break;
					}
					case 2:{
						cout<<"Vuelve a escribrir tu punto inical(x,y,z)"<<endl;
						cout<<"x=";
						cin>>x;
						cout<<"y=";
						cin>>y;
						cout<<"z=";
						cin>>z;
						x3.vector[0]=x;
						x3.vector[1]=y;
						x3.vector[2]=z;
						
						break;
					}
					default:{
						cout<<"Elige entre las opciones 1 o 2"<<endl;
						break;
					}
				}
			
		}
			system("cls");
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y,z)=2x^2-4x+y^2+3z^2+6z+2=0 ; f_2(x,y,z)=x^2+y^2-2y+2z^2-5=0 ; f_3(x,y,z)=3x^2-12x+y^2-3z^2+8=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<","<<z<<")"<<endl;
					while (it<ite && (to>tol || to == -1555)){
				cout<<"Iteracion #"<<k<<endl;
				sistEcu3(x,y,z, s3); //evaluo la funcion
				s3.print_vector();
				jacobiana3(x,y,z, j3);//mando a hacer la jacobiana
				j3.print_matrix();
				j3.get_determinant();
				cout<<"determinante"<<endl<<j3.get_determinant()<<endl;
				j3i=j3.invertir_matriz();//invierto la jacobiana
				cout<<"inversa"<<endl;
				j3i.print_matrix();//es print de prueba pero no me imprime numeros, desde aqui hay problemas
				j3i.multiplyByVector(s3,&res3);//multiplivco inversa por evaluada
				cout<<"resta de matriz con vector"<<endl;
				res3.print_vector();
				x3.restByVector(res3,&xn3);//resto punto inicial menos la multiplicacion anterior
				cout<<"punto anterior"<<endl;
				x3.print_vector();
				cout<<"nuevo punto"<<endl;
				xn3.print_vector();//de prueba
				Vector::normaEspectral(xn3,x3, &to);
				cout<<"norma: "<<to<<endl;
				x3.vector[0]=xn3.vector[0];
				x3.vector[1]=xn3.vector[1];
				x3.vector[2]=xn3.vector[2];
				x=x3.vector[0];
				y=x3.vector[1];
				z=x3.vector[2];
				k++;
				it++;
				}
			cout<<"La raiz del sistema esta en:"<<endl;
			x3.print_vector();
			cout<<"�Desea resolver otro sistema?"<<endl<<"1. Si      2. No"<<endl;
			cin>>p;
			switch(p){
				case 1:{
					break;
				}
				case 2:{
					t=0;
					break;
				}
				default:{
					cout<<"Elige entre las opciones 1 o 2"<<endl;
					break;
				}
			}
			
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
			c=1;
				while(c==1){
				
				cout<<"�Es correcto tu punto inicial?"<<endl<<"1. Si     2. No"<<endl;
				cin>>p;
				switch(p){
					case 1:{
						c=0;
						break;
					}
					case 2:{
						cout<<"Vuelve a escribrir tu punto inical(x,y,z)"<<endl;
						cout<<"x=";
						cin>>x;
						cout<<"y=";
						cin>>y;
						cout<<"z=";
						cin>>z;
						x3.vector[0]=x;
						x3.vector[1]=y;
						x3.vector[2]=z;
						
						break;
					}
					default:{
						cout<<"Elige entre las opciones 1 o 2"<<endl;
						break;
					}
				}
				
		}
			system("cls");
			cout<<"Resolveremos el sistema de ecuaciones:"<<endl<<endl<<"f_1(x,y,z)=x^2-4x+y^2=0 ; f_2(x,y,z)=x^2-x-12y+1=0 ; f_3(x,y,z)=3x^2-12x+y^2-3z^2+8=0"
			<<endl<<endl<<"Con una tolerancia de: "<<tol<<",  "<<ite<<" Iteraciones como maximo, "<<"Empezando en el punto inicial ("<<x<<","<<y<<","<<z<<")"<<endl;
				bool a = it<ite; 
				while (a &&  (to>tol || to == -1555)){
					cout<<"Iteracion #"<<k<<endl;
					sistEcu4(x,y,z, s3); //evaluo la funcion
					s3.print_vector();
					jacobiana4(x,y,z, j3);//mando a hacer la jacobiana
					j3.print_matrix();
					j3.get_determinant();
					cout<<"determinante"<<endl<<j3.get_determinant()<<endl;
					j3i=j3.invertir_matriz();//invierto la jacobiana
					cout<<"inversa"<<endl;
					j3i.print_matrix();//es print de prueba pero no me imprime numeros, desde aqui hay problemas
					j3i.multiplyByVector(s3,&res3);//multiplivco inversa por evaluada
					cout<<"resta de matriz con vector"<<endl;
					res3.print_vector();
					x3.restByVector(res3,&xn3);//resto punto inicial menos la multiplicacion anterior
					cout<<"punto anterior"<<endl;
					x3.print_vector();
					cout<<"nuevo punto"<<endl;
					xn3.print_vector();//de prueba
					Vector::normaEspectral(xn3,x3, &to);
					cout<<"norma: "<<to<<endl;
					x3.vector[0]=xn3.vector[0];
					x3.vector[1]=xn3.vector[1];
					x3.vector[2]=xn3.vector[2];
					x=x3.vector[0];
					y=x3.vector[1];
					z=x3.vector[2];
					k++;
					it++;
					a = it<ite;
			}
			cout<<"La raiz del sistema esta en:"<<endl;
			x3.print_vector();
			cout<<"�Desea resolver otro sistema?"<<endl<<"1. Si      2. No"<<endl;
			cin>>p;
			switch(p){
				case 1:{
					break;
				}
				case 2:{
					t=0;
					break;
				}
				default:{
					cout<<"Elige entre las opciones 1 o 2"<<endl;
					break;
				}
			}
			
			break;
		}
		
		default: {system("cls");
			cout<<"No escogio una opcion valida";
			break;
		}
		
		
	}
}
	
	
	return 0;
}
