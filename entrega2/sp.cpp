#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>


using namespace std;

class Vector{
    private:
        int size;

    public: 
        float *vector;

        Vector(int oSize){
            size = oSize;
            vector =(float *) malloc(size * sizeof(float));
        }

        ~Vector(){
            free(vector);
        }

        int get_size(){
            return size;
        }

        void print_vector(){
            for(int i=0; i<this->size; i++){
                cout<<this->vector[i]<<endl;
            }
        }

        void user_poblate(){
            for(int i=0; i<size; i++){
                    cin>>vector[i];
            }
        }

        void modify_element(int idx, float newVal){
            this->vector[idx] = newVal;
        }

        void dif_h(Vector &vec, Vector &h){
            for(int i=0; i<this->size; i++){
                h.vector[i]=vec.vector[i+1]-vec.vector[i];
            }
            
        }

        void dif_div(Vector &v1, Vector &v2, Vector &vres){ 
            for (int i=0; i<this->size; i++){
                vres.vector[i]=(v1.vector[i+1]-v1.vector[i])/v2.vector[i];
            }
        }
        
         void dif_s(Vector &vec, Vector &s){
            for(int i=0; i<this->size; i++){
                s.vector[i]=6*(vec.vector[i+1]-vec.vector[i]);
            }
            
        }
        

       /* Vector operator - (Vector vec1){
            if( this->size != vec1.size){
                cout<<"Error: El tamaño de los vectores no es el mismo"<<endl;
                return NULL;
            }
            Vector result = Vector(this->size);
            for(int i=0; i<this->size; i++){
                result.vector[i] = this->vector[i]-vec1.vector[i];
            }
            return result;
        }*/

        void restByVector(Vector restar, Vector *result){
            if( this->size != restar.get_size()){
                cout<<"Error: El tamaño de los vectores no es el mismo"<<endl;
            }
            for(int i=0; i<this->size; i++){
                result->vector[i] = this->vector[i]-restar.vector[i];
            }
        }



        // Vector operator =(Vector original){
        //     cout<<"overloading = operator"<<endl;
        //     original.print_vector();
        //     for(int i=0; i<this->size; i++){
        //         this->vector[i]= original.vector[i];
        //     }
        //     return *this; 
        // }

        

        

};
 



int main ()
{
  //float x, fx;
    int size;
    float a,b;
    int i=0;
    cout<<"Dime tamaño de tus datos"<<endl;
    cin>>size;
    Vector x = Vector(size);
    Vector fx = Vector(size);
    Vector h = Vector(size-1);
    Vector dd= Vector(size-1);
    Vector ss= Vector(size-2);
    cout<< "Escribe tu columna x"<<endl;
    x.Vector :: user_poblate();
    cout<< "Escribe tu columna fx"<<endl;
    fx.Vector :: user_poblate();
    x.Vector :: dif_h(x,h);
    fx.Vector :: dif_div(fx,h,dd);
    dd.Vector :: dif_s(dd,ss);
    x.print_vector();
    cout<<endl;
    fx.print_vector();
    cout<<endl;
    h.print_vector();
    cout<<endl;
    dd.print_vector();
    cout<<endl;
    ss.print_vector();  
    
} 

