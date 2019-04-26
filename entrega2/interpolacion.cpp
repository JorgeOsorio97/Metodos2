#include "../libraries.h"


class NewtonInterpolation{
    private:
        float *x_values;
        float *fx_values;
        int size;

    public:

        enum Type{
            PROGRESIVO,
            REGRESIVO,
            ERROR
        };

        Type type;

        /** Constructor */
        NewtonInterpolation(float *ox, float *ofx, int osize){
            size = osize;
            x_values = (float*) malloc(size * sizeof(float));
            fx_values = (float*) malloc(size * sizeof(float));
            for(int i=0; i<size; i++){
                x_values[i] = ox[i];
                fx_values[i] = ofx[i];
            }

        }

        /** Getters y Setters */
        float get_x_val(int idx){ return x_values[idx]; }
        float get_fx_val(int idx){ return fx_values[idx]; }
        void set_x_val(int idx, float newval){ x_values[idx] = newval; }
        void set_fx_val(int idx, float newval){ fx_values[idx] = newval; }

        float test_value(float test, int degree){
            if(!check_equally_spaced()){
                cout<<"Tus valores no estan igualmente espaciados"<<endl;
                return 0;
            }
            cout<<"Vector igualmente espaciado"<<endl;
            int index = get_idx_value(test, 0, size-1);
            if(index == -1){
                return 0;
            }
            cout<<"index = "<<index<<endl;
            Type type = check_possible_polynomial_degree(degree, index);
            if(type == NewtonInterpolation::Type::ERROR){
                return 0;
            }
            
            cout<<"grado:"<<degree<<endl;

            //Crear matriz de diferencias
            float differences_table[degree+1][degree+2];

            for(int i=0; i<degree+1; i++){
                differences_table[i][0] = x_values[index + i];
                differences_table[i][1] = fx_values[index + i];
            }
            if(type == NewtonInterpolation::Type::REGRESIVO){
                // invert_values();
                for(int i=0; i<degree+1; i++){
                    differences_table[i][0] = x_values[index - (degree-1-i)];
                    differences_table[i][1] = fx_values[index - (degree-1-i)];
                }
                index = size-index;
            }else{
                for(int i=0; i<degree+1; i++){
                    differences_table[i][0] = x_values[index + i];
                    differences_table[i][1] = fx_values[index + i];
                }
            }
            
            for(int col=2; col<degree+2; col++){
                int row_iterations = (degree+1)-(col-1);
                for(int row=0; row<row_iterations; row++){
                    differences_table[row][col] = differences_table[row+1][col-1]-differences_table[row][col-1];
                }
            }
            float h = (x_values[1]-x_values[0]);
            float s;

            //imprimir tabla
            for(int i=0; i<(degree+1); i++){
                for(int j=0; j<degree+2; j++){
                    cout<<differences_table[i][j]<<" ";
                }
                cout<<endl;
            }
            float result;
            if(type==NewtonInterpolation::Type::PROGRESIVO){
                result = differences_table[0][1];
                s = (test - differences_table[index][0])/h;
            }else{
                result = differences_table[degree][1];
                s = (test - differences_table[index+1][0])/h;
            }
            for(int i=1; i<=degree; i++){
                float mult_s = 1;
                if(type==NewtonInterpolation::Type::PROGRESIVO){
                    for(int j=0; j<i; j++){
                        mult_s *= (s-j);
                    }
                    result += (differences_table[0][i+1]/factorial(i))*mult_s;
                }
                else{
                    for(int j=0; j<i; j++){
                        mult_s *= (s+j);
                    }
                    int row_iterations = (degree+1)-(i+1);
                    float val = differences_table[row_iterations][i+1];
                    result += (val/factorial(i))*mult_s;
                }
                
            }
            return result;
        }
        
        /** Calcular el factorial de un entero */
        float factorial(int fac){
            //cout<<"FActorial de: "<<fac<<endl;
            float res = 1;
            for(int i=1; i<=fac; i++){
                res *=i;
            }
            //cout<<"factorial = "<<res<<endl;
            return res;
        }

        /** Encontrar entre que indices se encuentra el valor a buscar
         * @param values el valor al que le buscamos posicion
         * @param low_idx index of low 
         *              si es la primera iteracion usar 0;
         * @param high_idx index of high
         *              si es la primer iteracion usar size-1;
         * @return indice valor inicial del intervalo donde se encuetra
         *          ojo si es menor a 0 significa que no est en el intervalo
         */
        int get_idx_value(float value, int low_idx, int high_idx){
            if(value < x_values[low_idx] || value > x_values[high_idx]){
                return -1;
            }
            if(high_idx-low_idx == 1){
                return low_idx;
            }
            int middle_idx = low_idx + ((high_idx - low_idx) / 2);
            if(value < x_values[middle_idx]){
                return get_idx_value(value, low_idx, middle_idx);
            }
            if(value > x_values[middle_idx]){
                return get_idx_value(value, middle_idx, high_idx);
            }
        }

        /** Confirmar que alcancen los puntos para el grado solicitado */
        Type check_possible_polynomial_degree(int degree, int init_idx){
            int progressive = size - init_idx;
            if(progressive>=degree+1){
                cout<<"Progresivo"<<endl;
                return NewtonInterpolation::Type::PROGRESIVO;
            }
            if(init_idx+1>=degree+1){
                cout<<"Regresivo"<<endl;
                return NewtonInterpolation::Type::REGRESIVO;
            }
            return NewtonInterpolation::Type::ERROR;
        }

        /** Revisar que los valores esten igualmente espaciados */
        bool check_equally_spaced(){
            float separation, previous_separation;
            for(int i=0; i<(size-1); i++){
                separation = x_values[i+1]-x_values[i];
                if(i!=0){
                    if(!isEqual(separation,previous_separation)){
                        // cout<<"Espaciado no igual en indice: "<<i<<endl;
                        // cout<<"Previous: "<< previous_separation<<endl;
                        // cout<<"Current: "<<separation<<endl;
                        return false;
                    }
                }
                previous_separation = separation;
            }
            return true;
        }

        inline bool isEqual(double x, double y){
            const double epsilon = 1e-5;
            return std::abs(x - y) <= epsilon * std::abs(x);
        }

        /** Imprimir en consola los valores */
        void print_values(){
            cout<<"x\tf(x)"<<endl;
            for(int i=0; i<size; i++){
                cout<<x_values[i]<<"\t"<<fx_values[i]<<endl;
            }
        }

        /* Funciones para ordenar los valores */
        void order_values(int low, int high){
            
            if (low < high){ 
                /* pi is partitioning index, arr[p] is now 
                at right place */
                int pi = partition(low, high); 
        
                // Separately sort elements before 
                // partition and after partition 
                order_values(low, pi - 1); 
                order_values(pi + 1, high); 
            }
        }
        int partition ( int low, int high) { 
            int pivot = x_values[high];    // pivot 
            int i = (low - 1);  // Index of smaller element 
        
            for (int j = low; j <= high- 1; j++) { 
                // If current element is smaller than or 
                // equal to pivot 
                if (x_values[j] <= pivot) 
                { 
                    i++;    // increment index of smaller element 
                    swap(i, j); 
                } 
            } 
            swap(i + 1, high); 
            return (i + 1); 
        } 
        void swap(int a, int b){ 
            float t;
            t = x_values[a]; 
            x_values[a] = x_values[b]; 
            x_values[b] = t;
            //--------
            t = fx_values[a];
            fx_values[a] = fx_values[b];
            fx_values[b] = t;
        }

        /** Invertir los datos para caso de regresivo */
        void invert_values(){
            int iterations = size/2;
            // cout<<iterations<<endl;
            for(int i=0; i<((int)(size/2)); i++){
                swap(i,size-i-1);
            }
        }

        /** Destructor */
        ~NewtonInterpolation(){
            free(x_values);
            free(fx_values);
        }
};

// main(){
//     float *x, *fx;
//     int size;
//     cout<<"Dime tamaño de tus datos"<<endl;
//     cin>>size;
//     x = (float*) malloc(size * sizeof(float));
//     fx = (float*) malloc(size * sizeof(float));
    
//     for(int i=0; i<size; i++){
//         cout<<"Dime x en la posicion: "<<i+1<<endl;
//         cin>>x[i];
//     }
//     for(int i=0; i<size; i++){        
//         cout<<"Dime fx en la posicion: "<<i+1<<endl;
//         cin>>fx[i];
//     }
// //     // x[1] = 20;
// //     // fx[1] = 30;

//     NewtonInterpolation newton = NewtonInterpolation(x,fx,size);
    
// //     // newton.print_values();

// //     // int index = newton.get_idx_value(11.5,0,size-1);
// //     // cout<<"index = "<<index<<endl;

// //     // cout<<newton.check_possible_polynomial_degree(10,index);

// //     // newton.invert_values();
// //     newton.print_values();

//     cout<<"Resultado = "<<newton.test_value(1.1,3)<<endl;
// }
