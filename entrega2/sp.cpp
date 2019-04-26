#include "../libraries.h"
#include "matrix_gauss.cpp"


using namespace std;

class Vector{
    private:
        int size;

    public: 
        float *vector;
        float *vec;

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
        void conversar(Vector &ve, float *newton, int size){
            for(int i=0; i<size; i++){
                    ve.vector[i]=newton[i];
            }
        }

        void modify_element(int idx, float newVal){
            this->vector[idx] = newVal;
        }

        void dif_h(Vector &vec, Vector &h){
            for(int i=0; i<this->size-1; i++){
                h.vector[i]=vec.vector[i+1]-vec.vector[i];
            }
            h.vector[size]=0;
            
        }

        void dif_div(Vector &v1, Vector &v2, Vector &vres){ 
            for (int i=0; i<this->size-1; i++){
                vres.vector[i]=(v1.vector[i+1]-v1.vector[i])/v2.vector[i];
            }
            vres.vector[size-1];
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
 
void pob_mat(Matrix &m, Vector &h, Vector &s, int size){


    m.mat[0][0]=2*(h.vector[0]+h.vector[1]);
    m.mat[0][1]=h.vector[1];
    for (int i=2; i<size; i++){
       m.mat[0][i]=0;
    }
    int i;
    for (int j=1; j<size-1; j++){
        i=0;
    
        for(i=0; i<j-1; i++){
            m.mat[j][i]=0;
        }
        
        
            m.mat[j][i]=h.vector[i+1];
            m.mat[j][i+1]=2*(h.vector[i+1]+h.vector[i+2]);
            m.mat[j][i+2]=h.vector[i+2];
        




        for (int i=j+2;i<size; i++){
            m.mat[j][i]=0;
        }
    }

    for(int i=0; i<size-2; i++){
       m.mat[size-1][i]=0;
    }

    m.mat[size-1][size-2]=h.vector[size-1];
    m.mat[size-1][size-1]=2*(h.vector[size-1]+h.vector[size]);
    



    for (int i=0;i<size; i++){
        
        m.vector[i]=s.vector[i];
    }

}

void spline (Vector &vx,Vector &vfx, int sizp)
{

    Vector h = Vector(sizp);
    Vector dd= Vector(sizp);
    Vector ss= Vector(sizp-2);
    Vector fi=Vector(sizp);
    



    vx.Vector :: dif_h(vx,h);
    vfx.Vector :: dif_div(vfx,h,dd);
    dd.Vector :: dif_s(dd,ss);

    cout<<"tabla"<<endl;
    cout<<"x"<<endl;
    vx.print_vector();
    cout<<endl;
    cout<<"f(x)"<<endl;
    vfx.print_vector();
    cout<<endl;
    cout<<"h"<<endl;
    h.print_vector();
    cout<<endl;
    cout<<"Diferencias divididas"<<endl;
    dd.print_vector();
    cout<<endl;
    cout<<"S_i resultados del sistema de ecuaciones"<<endl;
    ss.print_vector();  
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int msize=sizp-2;

    Matrix mat = Matrix(msize);
    
    cout<<"Matriz"<<endl;
    pob_mat(mat, h, ss, msize);
    mat.print_matrix();
    // hasta aqui llena la tabla bien
    Matrix triangular = mat.gauss_elimination();
     cout<<"Matriz triangulada"<<endl;
     triangular.print_matrix();
    float determinante = mat.determinant(triangular);
     cout<<"Determinante = "<< determinante<<endl;
    float *resultado;
    resultado = (float *) malloc(sizp * sizeof(float));
    for(int i=0; i<sizp-2; i++){
        resultado[i] = mat.system_solution(triangular)[i];
         }
    for (int i= 0; i<sizp-2; i++){
        cout<<resultado[i]<<endl;
    }
    Vector a = Vector(sizp);
    Vector b = Vector(sizp);
    Vector c = Vector(sizp);
    Vector d = Vector(sizp);
    Vector newres = Vector(sizp);

    newres.vector[0]=0;
    newres.vector[sizp-1]=0;
    for(int i=1;i<sizp-1; i++){
        newres.vector[i]=resultado[i-1];
    }
    for(int i=0;i<sizp; i++){
        cout<<newres.vector[i]<<endl;
    }
  
  
    
for (int i=0; i<sizp-1; i++){
    a.vector[i]=((newres.vector[i+1]-newres.vector[i])/(6*(h.vector[i])));
}
a.vector[sizp-1]=0;
cout<<"a"<<endl;
for (int i=0; i<sizp; i++){
    
    cout<<a.vector[i]<<endl;
}
for (int i=0; i<sizp-1; i++){
    b.vector[i]=(newres.vector[i])/2;
}
b.vector[sizp-1]=0;
cout<<"b"<<endl;
for (int i=0; i<sizp; i++){
    
    cout<<b.vector[i]<<endl;
}
for(int i=0; i<sizp-1; i++){
    c.vector[i]=(dd.vector[i])-(((newres.vector[i+1]+(2*newres.vector[i]))/(6))*h.vector[i]); 

}
c.vector[sizp-1]=0;
cout<<"c"<<endl;
for (int i=0; i<sizp; i++){
    
    cout<<c.vector[i]<<endl;
    }
    for (int i=0; i<sizp; i++){
        d.vector[i]=vfx.vector[i];
    }
    cout<<"d"<<endl;
    for (int i=0; i<sizp; i++){
    
    cout<<d.vector[i]<<endl;
    }

    
}



