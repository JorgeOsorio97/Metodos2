#include "../libraries.h"
#include "../Vector.h"

class Matrix1 {
    private:
        int size;
        int mat_col_size;
        int mat_row_size;

    public:
        float **mat;
        float determinant = -2536847;

        Matrix1(int osize){
            size = osize;
            mat = (float **) malloc(size * sizeof(float *));
            for(int i=0; i<size; i++){
                mat[i] = (float *) malloc(size * sizeof(float));
            }
            mat_col_size = sizeof(mat[0])/sizeof(float);
            mat_row_size = sizeof(mat)/sizeof(float *);
        }

        ~Matrix1(){
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


        static void copy_matrix( Matrix1 &org, Matrix1 &res){
            if(res.size != org.size){
                cout<<"No cuadran los tamaños";
            }
            else{
                for(int i=0; i<res.size; i++){
                    for(int j=0; j<res.size; j++){
                        float temp = org.mat[i][j];
                        res.mat[i][j]= temp;
                    }
                }
            }
        }

        Matrix1 get_triangle_matrix(){
            Matrix1 result = Matrix1(size);
            Matrix1::copy_matrix(*this,result);
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
            
            // if(this->determinant != -2536847){
            //     return this->determinant;
            // }
            // Matrix1 triangled = get_triangle_matrix();
            // float determinant = 1;
            // for(int i = 0; i<size; i++){
            //     determinant *= triangled.mat[i][i];
            // }
            float determinant;
            if(this->size == 2){
                determinant = this->mat[0][0]*this->mat[1][1]
                            -this->mat[0][1]*this->mat[1][0];
            }
            else if(this->get_size() == 3){
                determinant = this->mat[0][0]*this->mat[1][1]*this->mat[2][2]
                                + this->mat[0][1]*this->mat[1][2]*this->mat[2][0]
                                + this->mat[0][2]*this->mat[1][0]*this->mat[2][1]
                                - this->mat[0][2]*this->mat[1][1]*this->mat[2][0]
                                - this->mat[0][1]*this->mat[1][0]*this->mat[2][2]
                                - this->mat[0][0]*this->mat[1][2]*this->mat[2][1];
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

        friend Vector operator * (Matrix1& mat, Vector& vec);

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
                //cout<<result->vector[row]<<endl;
            } 
        }
        Matrix1 cofactores(){
            Matrix1 cofactores = Matrix1(size);
            //Matrix1::copy_matrix(*this, cofactores);
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

        void invertir_matriz(Matrix1 &inversa){
            if(!this->determinant){
                get_determinant();
            }
            //cout<<"DETERMINANTE: "<<determinant<<endl;
            if(size==2){
                inversa.mat[0][0] = mat[1][1]/determinant;
                inversa.mat[0][1] = (-mat[0][1])/determinant;
                inversa.mat[1][0] = (-mat[1][0])/determinant;
                inversa.mat[1][1] = mat[0][0]/determinant;
            }
            else if(size==3){
                Matrix1 cofactores = this->cofactores();
                Matrix1 adjTranspuesta= Matrix1(size);
                int row, col;
                for(row=0; row<size; row++){
                    for(col=0; col<size; col++){
                        adjTranspuesta.mat[row][col] = cofactores.mat[col][row];
                    }
                }
                //cout<<"Cofactores"<<endl;
                //cofactores.print_matrix();
                //cout<<"Adjunta"<<endl;
                //adjTranspuesta.print_matrix();
                for(row=0; row<size; row++){
                    for(col=0; col<size; col++){
                        inversa.mat[row][col] = adjTranspuesta.mat[row][col]/determinant;
                    }
                }
            }
            //cout<<"Inversa"<<endl;
            //inversa.print_matrix();
        }
};

/*Vector operator * (Matrix1& mat, Vector& vec){
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
*/






// int main(){
//     int tamanio;
//     cout<<"De que tamaño"<<endl;
//     cin>>tamanio;
//     Matrix1 mat = Matrix1(tamanio);
//     mat.user_poblate();
//     mat.print_matrix();
//     mat.mat[0][0]= 0.01;
//     //Matrix1 inv = mat.Jacobi();
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
//     Matrix1 inversa = mat.invertir_matriz();
//     inversa.print_matrix();

//     return 0;
// } 
 
// int main(){
//     Vector a0= Vector(3);
//     Vector a1 = Vector(3);
//     a0.user_poblate(); 
//     a1.user_poblate();
//     float result = Vector::normaEspectral(a0,a1);
//     cout<<result<<endl;
// }