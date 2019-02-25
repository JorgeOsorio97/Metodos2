#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Matrix;

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
                cout<<"Dame el valor de la posicion:  "<<i+1<<" en el vector: ";
                    cin>>vector[i];
            }
        }

        void modify_element(int idx, float newVal){
            this->vector[idx] = newVal;
        }

        Vector operator - (Vector vec1){
            if( this->size != vec1.size){
                cout<<"Error: El tamaño de los vectores no es el mismo"<<endl;
                return NULL;
            }
            Vector result = Vector(this->size);
            for(int i=0; i<this->size; i++){
                result.vector[i] = this->vector[i]-vec1.vector[i];
            }
            return result;
        }

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

        friend Vector operator * (Matrix& mat, Vector& vec);

        Vector normaEspectral(Vector anterior){
            
        }

};

class Matrix {
    private:
        int size;

    public:
        float **mat;
        float determinant;

        Matrix(int osize){
            size = osize;
            mat = (float **) malloc(size * sizeof(float *));
            for(int i=0; i<size; i++){
                mat[i] = (float *) malloc(size * sizeof(float));
            }
        }

        ~Matrix(){
            free(mat);
        }

        int get_size(){
            return this->size;
        }

        void user_poblate(){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    cout<<"Dame el valor de la posicion:  "<<i+1<<j+1<<": ";
                    cin>>mat[i][j];
                }
            }
            cout<<"";
        }

        void print_matrix(){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    cout<<mat[i][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"";
        }


        void copy_matrix( Matrix &org){
            if(size != org.size){
                cout<<"No cuadran los tamaños";
            }
            else{
                for(int i=0; i<size; i++){
                    for(int j=0; j<size; j++){
                        this->mat[i][j]= org.mat[i][j];
                    }
                }
            }
        }

        Matrix get_triangle_matrix(){
            Matrix result = Matrix(size);
            result.copy_matrix(*this);
            int pivot, row, col;
            for(pivot=0; pivot<size-1; pivot++){
                for(row = pivot + 1; row<size; row++){
                    float factor = 0;
                    if(result.mat[pivot][pivot] < 0 && result.mat[row][pivot] > 0){
                        factor = (-1)*(result.mat[row][pivot]/result.mat[pivot][pivot]);
                    }
                    else{
                        factor = (-1)*(result.mat[row][pivot]/result.mat[pivot][pivot]);
                    }
                    
                    for(col=0; col<size; col++){
                        if(col == pivot){
                            result.mat[row][col] = 0;
                        }
                        else{
                            result.mat[row][col] = (result.mat[row][col])+((factor)*(result.mat[pivot][col]));
                        }
                    }
                }
            }
            return result;
        }

        float get_determinant(){
            if(!this->determinant){
                return this->determinant;
            }
            Matrix triangled = get_triangle_matrix();
            float determinant = 1;
            for(int i = 0; i<size; i++){
                determinant *= triangled.mat[i][i];
            }
            this->determinant = determinant;
            return determinant;
        }

        void modify_element(int &row, int &col, float &newval){
            mat[row-1][col-1] = newval;
        }

        int checkEDD(){
            int row, col, val;
            val=1;
            for(row=0; row<size; row++){
                float sum = 0;
                for(col=0; col<size; col++){
                    if(col!=row){
                        sum+=mat[row][col];
                    }
                }
                if(sum >= mat[row][row]){
                    val = 0;
                }
            }
            return val;
        }

        friend Vector operator * (Matrix& mat, Vector& vec);

        void multiplyByVector(Vector& vector1, Vector *result){
            if(this->size != vector1.get_size()){
                cout<<"Error: Los tamaños no coinciden"<<endl;
            }
            float temp;
            int row, col;
            for(row=0; row<this->size; row++){
                temp = 0;
                for(col=0; col<this->size; col++){
                    temp+=this->mat[row][col]*vector1.vector[col];
                    //cout<<row<<col<<temp<<endl;
                }
                //cout<<result.vector[row]<<endl;
                //cout<<temp<<endl;
                result->vector[row] = temp;
                //cout<<result.vector[row]<<endl;
            }
        }
        Matrix cofactores(){
            Matrix cofactores = Matrix(size);
            cofactores.copy_matrix(*this);
            int row, col;
            cofactores.mat[0][0] = (this->mat[1][1]) * (this->mat[2][2]) - (this->mat[1][2]) * (this->mat[2][1]);
            cofactores.mat[0][1] = (this->mat[1][0]) * (this->mat[2][2]) - (this->mat[1][2]) * (this->mat[2][0]);
            cofactores.mat[0][2] = (this->mat[1][0]) * (this->mat[2][1]) - (this->mat[1][1]) * (this->mat[2][0]);
            cofactores.mat[1][0] = (this->mat[0][1]) * (this->mat[2][2]) - (this->mat[0][2]) * (this->mat[2][1]);
            cofactores.mat[1][1] = (this->mat[0][0]) * (this->mat[2][2]) - (this->mat[0][2]) * (this->mat[2][0]);
            cofactores.mat[1][2] = (this->mat[0][0]) * (this->mat[2][1]) - (this->mat[0][1]) * (this->mat[2][0]);
            cofactores.mat[2][0] = (this->mat[0][1]) * (this->mat[1][2]) - (this->mat[0][2]) * (this->mat[1][1]);
            cofactores.mat[2][1] = (this->mat[0][0]) * (this->mat[1][2]) - (this->mat[0][2]) * (this->mat[1][0]);
            cofactores.mat[2][2] = (this->mat[0][0]) * (this->mat[1][1]) - (this->mat[0][1]) * (this->mat[1][0]);
            for(row=0; row<size; row++){
                for(col=0; col<size; col++){
                    cofactores.mat[row][col]= pow(-1,row+col)*cofactores.mat[row][col];
                }
            }
            return cofactores;
        }

        Matrix invertir_matriz(){
            Matrix inversa = Matrix(size);
            if(!this->determinant){
                get_determinant();
            }
            if(size==2){
                inversa.mat[0][0] = mat[1][1]/determinant;
                inversa.mat[0][1] = (-mat[0][1])/determinant;
                inversa.mat[1][0] = (-mat[1][0])/determinant;
                inversa.mat[1][1] = mat[0][0]/determinant;
            }
            else if(size==3){
                Matrix cofactores = this->cofactores();
                Matrix adjTranspuesta= Matrix(size);
                int row, col;
                for(row=0; row<size; row++){
                    for(col=0; col<size; col++){
                        adjTranspuesta.mat[row][col] = cofactores.mat[col][row];
                    }
                }
                cout<<"Cofactores"<<endl;
                //cofactores.print_matrix();
                cout<<"Adjunta"<<endl;
                //adjTranspuesta.print_matrix();
                for(row=0; row<size; row++){
                    for(col=0; col<size; col++){
                        inversa.mat[row][col] = adjTranspuesta.mat[row][col]/determinant;
                    }
                }
            }
            //cout<<"Inversa"<<endl;
            //inversa.print_matrix();
            return inversa;
        }
};

Vector operator * (Matrix& mat, Vector& vec){
            if(mat.get_size() != vec.get_size()){
                cout<<"Error: Los tamaños no coinciden"<<endl;
                return NULL;
            }
            Vector result = Vector(mat.size);
            float temp;
            int row, col;
            for(row=0; row<mat.size; row++){
                temp = 0;
                for(col=0; col<mat.size; col++){
                    temp+=mat.mat[row][col]*vec.vector[col];
                    //cout<<row<<col<<temp<<endl;
                }
                //cout<<result.vector[row]<<endl;
                //cout<<temp<<endl;
                result.vector[row] = temp;
                //cout<<result.vector[row]<<endl;
            }
            result.print_vector();
            return result;
        }







// int main(){
//     int tamanio;
//     cout<<"De que tamaño"<<endl;
//     cin>>tamanio;
//     Matrix mat = Matrix(tamanio);
//     mat.user_poblate();
//     mat.print_matrix();
//     mat.mat[0][0]= 0.01;
//     //Matrix inv = mat.Jacobi();
//     Vector vector = Vector(tamanio);
//     //vector.user_poblate();
//     vector.print_vector();
//     vector.vector[0] = 0.01;
//     Vector mult = Vector(tamanio);
//     //mult = mat * vector;
//     mat.multiplyByVector(vector, &mult);
//     // cout<<"El resultado de vec * mat = "<<endl;
//     // mult.print_vector();
//     // cout<<"El resultado de vec - vec = "<<endl;
//     // Vector resta = Vector(tamanio);
//     // mult.restByVector(vector, &resta);
//     // resta.print_vector();
//     cout<<mat.get_determinant()<<endl;
//     Matrix inversa = mat.invertir_matriz();
//     inversa.print_matrix();

//     return 0;
// } 
 