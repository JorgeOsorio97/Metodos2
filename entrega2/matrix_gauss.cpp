#include "../libraries.h"

class Matrix {
    private:
        int size;       

    public:
        float **mat;
        float *vector;
        Matrix(int osize){
            size = osize;
            mat = (float **) malloc(size * sizeof(float *));
            for(int i=0; i<size; i++){
                mat[i] = (float *) malloc(size * sizeof(float));
            }
            vector = (float *) malloc(size * sizeof(float));
        }
        ~Matrix(){
            free(mat);
            free(vector);
        }

        void poblate_matrix(){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    cout<<"Dame el valor de la posicion:  "<<i+1<<j+1<<": ";
                    cin>>mat[i][j];
                }
            }
            cout<<"";
        }
		
        void poblate_vector(){
            for(int i=0; i<size; i++){
                cout<<"Dame el valor de la posicion:  "<<i+1<<" en el vector: ";
                    cin>>vector[i];
            }
        }
		
		
        void print_matrix(){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    cout<<mat[i][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"";
            for(int j=0; j<size; j++){
                    cout<<vector[j]<<"\n";
                }
                cout<<"\n";
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
                for(int i=0; i<size; i++){
                    this->vector[i]=org.vector[i];
                }
            }
        }

        Matrix gauss_elimination(){
            Matrix det = Matrix(size);
            det.copy_matrix(*this);
            int pivot, row, col;
            for(pivot=0; pivot<size-1; pivot++){
                for(row = pivot + 1; row<size; row++){
                    float factor = 0;
                    if(det.mat[pivot][pivot] < 0 && det.mat[row][pivot] > 0){
                        factor = (-1)*(det.mat[row][pivot]/det.mat[pivot][pivot]);
                    }
                    else{
                        factor = (-1)*(det.mat[row][pivot]/det.mat[pivot][pivot]);
                    }
                    
                    for(col=0; col<size; col++){
                        if(col == pivot){
                            det.mat[row][col] = 0;
                        }
                        else{
                            det.mat[row][col] = (det.mat[row][col])+((factor)*(det.mat[pivot][col]));
                        }
                        //det.print_matrix();
                    }
                    det.vector[row] = (det.vector[row])+((factor)*(det.vector[pivot]));
                }
            }
            //det.print_matrix();
            return det;
        }
		
		
        float determinant(Matrix &det){
            float determinant = 1;
            for(int i = 0; i<size; i++){
                determinant *= det.mat[i][i];
            }
            //cout<<"La determinante de la matriz es: "<<determinant<<"\n";
            return determinant;
        }
		
		
        float* system_solution(Matrix &triangle){
            //triangle.print_matrix();
            float *result = new float[size];
            for(int row=size-1; row>=0; row--){
                float sum = triangle.vector[row];
                for(int col=1; col<size; col++){
                    if(col>row){
                        sum -= triangle.mat[row][col]*result[col]; 
                        //cout<<sum<<"-="<<triangle.mat[row][col]<<"*"<<triangle.vector[col]<<endl;
                    }
                }
                result[row] = sum/triangle.mat[row][row];
                
            }
            // for(int i=0; i<size; i++){
            //     cout<<"X"<<i+1<<"="<<result[i]<<"\n";
            // }
            return result;
        }
        
        void modify_matrix_element(int &row, int &col, float &newval){
            mat[row-1][col-1] = newval;
        }

        void modify_vector_element(int &idx, float &newval){
            vector[idx-1] = newval;
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

        float * Jacobi(int &max_it, float &tol){
            static float *result;
            result = (float *) malloc(size * sizeof(float));
            int i, row, col;
            for(i=0; i<size; i++){
                result[i] = 0;
            }

            int iterations = 0;
            float reached_tol=1000000;
            do{
                float old_result[size];
                for(int x=0; x<size; x++){
                    old_result[x]=result[x];
                }
                for(row = 0; row<size; row++){
                    float sum = 0;
                    for(col = 0; col<size; col++){
                        if(col != row){
                            sum += mat[row][col]*result[col];
                        }
                    }
                    result[row] = (vector[row]-sum)/mat[row][row];
                }
                iterations++;
                reached_tol=0;
                for(int y=0; y<size; y++){
                    float val = result[y]-old_result[y];
                    if(val<0){
                        val = val*(-1);
                    }
                    if(reached_tol<val){
                        reached_tol=val;
                    }
                }
                cout<<"Iteracion: "<<iterations<<endl;
                for(int k=0; k<size; k++){
                    cout<<result[k]<<endl;
                }
            }while(iterations < max_it && reached_tol>tol);
            return result;
        }

        float Potencias(int max_it, float tol){
            float result, oldResult = 0;
            int iteracion=0;
            float tolAlcanzada;
            do{
                oldResult = result;
                multiplicarMatrizxVector();
                result = normaEspectralVector();
                normalizarVector();
                iteracion++;
                tolAlcanzada = result-oldResult;
                if(tolAlcanzada<0){
                    tolAlcanzada*=-1;
                }

            }while(iteracion<max_it && tolAlcanzada>tol);
            return result;
        }

        void multiplicarMatrizxVector(){
            float temp;
            float *resultVector = (float *) malloc(size * sizeof(float));
            int row,col,idx;
            for(row=0; row<size; row++){
                temp=0;
                for(col=0; col<size; col++){
                    temp+=mat[row][col]*vector[col];
                }
                resultVector[row] = temp;
            }
            for(int i = 0; i<size; i++){
                vector[i] = resultVector[i];
            }
        }

        void normalizarVector(){
            float max = normaEspectralVector();
            for(int j=0; j<size; j++){
                vector[j] = vector[j]/max;
            }
        }
        
        float normaEspectralVector(){
            float max = 0;
            float temp;
            for(int i=0; i<size; i++){
                if(vector[i]<0){
                    temp = vector[i]*(-1);
                }
                else{
                    temp = vector[i];
                }
                if(max<temp){
                    max = vector[i];
                }
            }
            return max;
        }

};

int main(){
    int size;
    cout<<"Dime el tamaño de la matriz"<<endl;
    cin>>size;
    Matrix mat = Matrix(size);
    mat.poblate_matrix();
    mat.mat[0][0]=100;
    mat.poblate_vector();
    mat.vector[0]=100;
    mat.print_matrix();
    Matrix triangular = mat.gauss_elimination();
    // cout<<"Matriz triangulada"<<endl;
    // triangular.print_matrix();
    float determinante = mat.determinant(triangular);
    // cout<<"Determinante = "<< determinante<<endl;
    float *resultado;
    resultado = (float *) malloc(size * sizeof(float));
    for(int i=0; i<size; i++){
        resultado[i] = mat.system_solution(triangular)[i];
        // cout<<i<<" ";
    }
    return 0;
}