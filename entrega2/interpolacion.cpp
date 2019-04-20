#include "../libraries.h"

class NewtonInterpolation{
    private:
        float *x_values;
        float *fx_values;
        int size;


    public:
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

        /** Imprimir en consola los valores */
        void print_values(){
            cout<<"--x\tf(x)--"<<endl;
            for(int i=0; i<size; i++){
                cout<<"--"<<x_values[i]<<"\t"<<fx_values[i]<<"--"<<endl;
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

        ~NewtonInterpolation(){
            free(x_values);
            free(fx_values);
        }
};

main(){
    float *x, *fx;
    int size;
    cout<<"Dime tamaño de tus datos"<<endl;
    cin>>size;
    x = (float*) malloc(size * sizeof(float));
    fx = (float*) malloc(size * sizeof(float));
    
    for(int i=0; i<size; i++){
        x[i] = i;
        fx[i] = i;
    }

    // for(int i=0; i<size; i++){
    //     cout<<"--"<<x[i]<<"\t"<<fx[i]<<"--"<<endl;
    // }

    x[1] = 20;
    fx[1] = 30;

    NewtonInterpolation newton = NewtonInterpolation(x,fx,size);

    newton.set_x_val(2, 15);

    
    newton.print_values();

}