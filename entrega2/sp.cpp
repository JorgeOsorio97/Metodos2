#include "../libraries.h"
#include "matrix_gauss.cpp"


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

        void user_poblate(Vector &ve){
            for(int i=0; i<size; i++){
                    cin>>ve.vector[i];
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
 
void pob_mat(Matrix &m, Vector &h, int siz){
   //int i=0;
   //int j=0;
   //siz=siz-1;
   m.mat[0][0]=2*(h.vector[0]+h.vector[1]);
   m.mat[0][1]=h.vector[1];
   for (int i=2; i<siz; i++){
       m.mat[i][0]=0;
    }
    for (int j=1;j<siz-1; j++){
        for(int i=0; i<j-1; i++){
            m.mat[i][j]=0;
        }
        for (int i=j-1; i<j+2; i++){
            m.mat[i][j]=h.vector[j];
            m.mat[i][j]=2*(h.vector[j]+h.vector[j+1]);
            m.mat[i][j]=h.vector[j+1];
        }




        for (int i=j+2;i<siz; i++){
            m.mat[i][j]=0;
        }
    }


    for(int i=0; i<siz-2; i++){
        m.mat[i][siz]=0;
    }
    m.mat[siz-1][siz]=h.vector[siz-1];
    m.mat[siz][siz]=2*(h.vector[siz-1]+h.vector[siz]);

}


void spline (Vector &vx,Vector &vfx, int sizp)
{
  //float x, fx;
    
    Vector h = Vector(sizp-1);
    Vector dd= Vector(sizp-1);
    Vector ss= Vector(sizp-2);
    
    vx.Vector :: dif_h(vx,h);
    vfx.Vector :: dif_div(vfx,h,dd);
    dd.Vector :: dif_s(dd,ss);
    vx.print_vector();
    cout<<endl;
    vfx.print_vector();
    cout<<endl;
    h.print_vector();
    cout<<endl;
    dd.print_vector();
    cout<<endl;
    ss.print_vector();  
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int msize=sizp-2;
    Matrix mat = Matrix(msize);
    pob_mat(mat, h, msize);
    mat.print_matrix();

    
} 

int main (){
    int size;
    float a,b;
    int i=0;
    cout<<"Dime tamaño de tus datos"<<endl;
    cin>>size;
    Vector x = Vector(size);
    Vector fx = Vector(size);
    cout<< "Escribe tu columna x"<<endl;
    x.Vector :: user_poblate(x);
    cout<< "Escribe tu columna fx"<<endl;
    fx.Vector :: user_poblate(fx);
    spline(x, fx, size);

    return 0;
}