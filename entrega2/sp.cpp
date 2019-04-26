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
 
void pob_mat(Matrix &m, Vector &h, Vector &s, int size){


    m.mat[0][0]=2*(h.vector[0]+h.vector[1]);
    m.mat[0][1]=h.vector[1];
    for (int i=2; i<size; i++){
       m.mat[0][i]=0;
    }
    int i;
    float a,b,c;
    a=1;
    b=2;
    c=3;
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
    


for (int j=0; j<size ; j++){
    for (int i=0;i<size; i++){
        
        m.vector[i]=s.vector[i];
    }
}
}

void spline (Vector &vx,Vector &vfx, int sizp)
{

    Vector h = Vector(sizp);
    Vector dd= Vector(sizp-1);
    Vector ss= Vector(sizp-2);
    



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


    
} 
void prueba(){
    int siz=9;
    Matrix mati = Matrix(siz);
    
    Vector h = Vector(10);
    Vector ss= Vector(9);
    h.vector[0]=0.12;
    h.vector[1]=0.26;
    h.vector[2]=0.78;
    h.vector[3]=0.64;
    h.vector[4]=0.74;
    h.vector[5]=1.54;
    h.vector[6]=2.3;
    h.vector[7]=2.08;
    h.vector[8]=1.28;
    h.vector[9]=-0.839999;
    

    ss.vector[0]=-44.6923;
    ss.vector[1]=9.8416;
    ss.vector[2]=-7.65384;
    ss.vector[3]=-0.770272;
    ss.vector[4]=-5.98947;
    ss.vector[5]=10.7641;
    ss.vector[6]=-6.41589;
    ss.vector[7]=10.774;
    ss.vector[8]=-18.4197;
    pob_mat(mati, h, ss, siz);
    mati.print_matrix();
    //todo apartir de aqui tambien ponlo en spline
    Matrix triangular = mati.gauss_elimination();
     cout<<"Matriz triangulada"<<endl;
     triangular.print_matrix();
    float determinante = mati.determinant(triangular);
     cout<<"Determinante = "<< determinante<<endl;
    float *resultado;
    resultado = (float *) malloc(siz * sizeof(float));
    for(int i=0; i<siz; i++){
        resultado[i] = mati.system_solution(triangular)[i];
         cout<<i<<endl;


    }
    for (int i= 0; i<siz; i++){
        cout<<resultado[i]<<endl;
    }

}

