#include "../libraries.h"
//#include "../Vector.h"
#include "matrix_gauss.cpp"


using namespace std;

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
 
void pob_mat(Matrix &m, Vector &h, Vector &s, int size){


    m.mat[0][0]=2*(h.vector[0]+h.vector[1]);
    m.mat[0][1]=h.vector[1];
    for (int i=2; i<size; i++){
       m.mat[0][i]=0;
    }
   
    for (int j=1; j<size-1; j++){
        int i= 0;
    
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
    


for (int j=0; j<size ; j++){
    for (int i=0;i<size; i++){
        
        m.vector[i]=s.vector[i];
    }
}
}

void spline (Vector &vx,Vector &vfx, int sizp)
{

    Vector h = Vector(sizp);
    Vector dd= Vector(sizp);
    Vector ss= Vector(sizp-2);
    



    vx.Vector :: dif_h(vx,h);
    vfx.Vector :: dif_div(vfx,h,dd);
    dd.Vector :: dif_s(dd,ss, sizp-2);
    cout<<"tabla"<<endl;
    //cout<<"x"<<endl;
   // vx.print_vector();
    cout<<endl;
    //cout<<"f(x)"<<endl;
    //vfx.print_vector();
    cout<<endl;
    //cout<<"h"<<endl;
    //h.print_vector();
    cout<<endl;
    //cout<<"Diferencias divididas"<<endl;
    //dd.print_vector();
    cout<<endl;
    //cout<<"hola"<<endl;
    //cout<<"S_i resultados del sistema de ecuaciones"<<endl;
    //ss.print_vector();  
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int msize=sizp-2;

    Matrix mat = Matrix(msize);
    
    //cout<<"Matriz"<<endl;
    pob_mat(mat, h, ss, msize);
    //mat.print_matrix();
    // hasta aqui llena la tabla bien
    Matrix triangular = mat.gauss_elimination();
     cout<<"Matriz triangulada"<<endl;
     //triangular.print_matrix();
    float determinante = mat.determinant(triangular);
     cout<<"Determinante = "<< determinante<<endl;
    Vector res= Vector(sizp);
    Vector a= Vector(sizp);
    Vector b= Vector(sizp);
    Vector c= Vector(sizp);
    Vector d= Vector(sizp);
    res.vector[0]=0;
    res.vector[sizp-1]=0;
    for(int i=0; i<sizp-1; i++){
        res.vector[i+1] = mat.system_solution(triangular)[i];
         cout<<i<<endl;


    }
    
      //  res.print_vector();

    for (int i=0; i<sizp; i++){
        a.vector[i]=(res.vector[i+1]-res.vector[i])/(6*h.vector[i]);
        b.vector[i]=(res.vector[i])/(2);
        c.vector[i]=dd.vector[i]-((res.vector[i+1]+2*res.vector[i])/(6))*(h.vector[i]);
        d.vector[i]=vfx.vector[i];
    }
    a.vector[sizp-1]=0;
    cout<<"x"<<endl;
    vx.print_vector();
    cout<<"y"<<endl;
    vfx.print_vector();
    cout<<"h"<<endl;
    h.print_vector();
    cout<<"Matriz"<<endl;
    mat.print_matrix();
    cout<<"s"<<endl;
    res.print_vector();

    cout<<"a"<<endl;
    a.print_vector();
    cout<<"b"<<endl;
    b.print_vector();
    cout<<"c"<<endl;
    c.print_vector();
    cout<<"d"<<endl;
    d.print_vector();
for (int i=0; i<sizp-1;i++){
    cout<<"g"<<i<<"(x) =  ("<<a.vector[i]<<")(x-"<<vx.vector[i]<<")^3+("<<b.vector[i]<<")(x-"<<vx.vector[i]<<")^2+("<<c.vector[i]<<")(x-"<<vx.vector[i]<<")+("<<d.vector[i]<<")              "<<vx.vector[i]<<" <=  x < "<<vx.vector[i+1];
    cout<<endl;
    cout<<endl;
}
    
} 


