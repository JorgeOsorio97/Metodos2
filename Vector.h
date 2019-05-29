#ifndef FLAG
    #define FLAG "flag"
    #include "libraries.h"
class Matrix;

class Vector{
    private:
        int size;

    public: 
        float *vector;
        // float *vec;

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

        void user_poblate(Vector &ve){
            for(int i=0; i<size; i++){
                    cin>>ve.vector[i];
            }
        }
        
        

        void modify_element(int idx, float newVal){
            this->vector[idx] = newVal;
        }

        void dif_h(Vector &vec, Vector &h){
            for(int i=0; i<this->size-1; i++){
                h.vector[i]=vec.vector[i+1]-vec.vector[i];
            }
            h.vector[size-1]=0;
            
        }

        void dif_div(Vector &v1, Vector &v2, Vector &vres){ 
            for (int i=0; i<this->size-1; i++){
                vres.vector[i]=(v1.vector[i+1]-v1.vector[i])/v2.vector[i];
            }
            vres.vector[size-1]=0;
        }
        
         void dif_s(Vector &vec, Vector &s, int size){
            for(int i=0; i<size; i++){
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

        friend Vector operator * (Matrix& mat, Vector& vec);

         static void normaEspectral(Vector &a0, Vector &a1, float *norma){
            *norma = -1555;
            if(a0.get_size()!=a1.get_size()){
                cout<<"el tamaño de los vectores no coincide"<<endl;
            }
            //a0.print_vector();
            //a1.print_vector();
            // Vector result = Vector(a0.get_size());

            // a1.restByVector(a0, &result);
            // cout<<"Vector resultado"<<endl;
            // result.print_vector();

            float result[a1.get_size()];

            for(int i=0; i<a1.get_size(); i++){
                //cout<<a0.vector[i]<<"-"<<a1.vector[i]<<endl;
                result[i] = a0.vector[i] - a1.vector[i];
                //cout<<"="<<result[i]<<endl;
            }


            for(int i=0; i<a0.get_size(); i++){
                float temp=0;
                if(result[i]<0){
                    temp = (-1)* result[i];
                }
                else{
                    temp = result[i];
                }
                if(temp>*norma || *norma == -1555){
                    //cout<<"Cambio de norma"<<*norma<<endl;
                    *norma = temp;
                    //cout<<"Cambio de norma"<<*norma<<endl;
                }
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

#endif
