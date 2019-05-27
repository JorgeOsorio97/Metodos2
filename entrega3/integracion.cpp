#include "../libraries.h"

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



        // Vector operator =(Vector original){
        //     cout<<"overloading = operator"<<endl;
        //     original.print_vector();
        //     for(int i=0; i<this->size; i++){
        //         this->vector[i]= original.vector[i];
        //     }
        //     return *this; 
        // }

        

        

};

void simpson_octavo(float h, Vector fxv){
    int size = fxv.get_size();  
    double res, sum = 0;
    float a = fxv.vector[0];
    float b = fxv.vector[fxv.get_size()-1];
    for (int i = 1; i < size - 1; i++){
        if(i%3 == 0){
            sum = sum + (2*fxv.vector[i]);
        }
        else{
            sum = sum+(3*fxv.vector[i]);
        }
    }
 
    res = 3*h/8*(a+b+sum);
    cout << "Complementando con regla de 3/8: "<<res<<endl;   //Se regresa y solo para hacer pruebas
}
void simpson_tercio(float h, Vector fxv){    
    int size = fxv.get_size();                                  //Vector auxiliar que contendra los valores multiplicados
    double res, sum = 0;
    float a = fxv.vector[0];
    float b = fxv.vector[fxv.get_size()-1];
    if((fxv.get_size() - 1 )%2 == 0){
        for (int i = 1; i < size - 1; i += 2){
        sum = sum+(4*fxv.vector[i]);
        }
        for (int i = 2; i < size - 2; i += 2){
            sum = sum+(2*fxv.vector[i]);
        }
        res = (h/3)*(a+b+sum);
        cout << "Resultado de la integral con regla de 1/3: "<<res <<endl;
    }else{
            for (int j = 1; j < size - 4; j += 2){
            sum = sum+(4*fxv.vector[j]);
            }
            for (int j = 2; j < size - 4; j += 2){
                sum = sum+(2*fxv.vector[j]);
            }
            res = (h/3)*(a+b+sum);    
        }
        simpson_octavo(h, fxv.vector[fxv.get_size() - 4]);
        
    }





float diferenciaCentrada(Vector x, Vector fx, int idx){
    if(idx < x.get_size()-1 && idx > 0){
        return (fx.vector[idx+1] - fx.vector[idx-1])/(2*(x.vector[1]-x.vector[0]));
    }
    return 0;
}

inline bool isEqual(double x, double y){
            const double epsilon = 1e-5;
            return abs(x - y) <= epsilon * abs(x);
        }
        
Vector generarVectorIE2(float init, float end, float step){
    int size = (end-init)/step+1;
    cout<<"Size: "<<size<<endl;
    Vector res = Vector(size);
     for(int i=0; i<size; i++){
        res.vector[i]=init+(i*step);
    }
    return res;
}

void generarVectorIE(float init, int size, float step, Vector &res){
    for(int i=0; i<size; i++){
        res.vector[i]=init+(i*step);
    }
    //res.print_vector();
}



float diferenciaCentrada(Vector &x, Vector &fx, int idxi, int idxf){
    int size = idxf-idxi+1;
    cout<<"Las derivadas solicitadas son"<<endl;
    cout<<"x \t f(x) \t f'(x)"<<endl;
    for(int i=0; i<size; i++){
        int pos = idxi+i;
        float der = diferenciaCentrada(x,fx,idxi+i);
        cout<<x.vector[idxi+i]<<" \t "<<fx.vector[idxi+i]<<" \t "<<der<<endl;
    }
}