#include "../libraries.h"
#include "../entrega2/sp.cpp"

float diferenciaCentrada(Vector x, Vector fx, int idx){
    if(idx < x.get_size()-1 && idx > 0){
        return (fx.vec[idx+1] - fx.vec[idx-1])/(2*(fx.vec[0]-fx.vec[1]));
    }
    return 0;
}

