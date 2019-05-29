#include "../libraries.h"
#include "matrix.cpp"

void sistEcu1(float x, float y, Vector &vec){
vec.vector[0] = (x*x) + (x*y) - 10;
vec.vector[1] = y + (3*x*y*y) - 50;

}

void sistEcu2(float x, float y, Vector &vec){
    vec.vector[0] = (x*x) + (y*y) - 9;
    vec.vector[1] = -(exp(x)) - (2*y) - 3;

}

void sistEcu3(float x, float y, float z, Vector &vec){
    vec.vector[0] = (2*x*x) - (4*x) +(y*y) +(3*z*z) + (6*z) + 2;
    vec.vector[1] = (x*x) + (y*y) - (2*y) + (2*z*z) - 5;
    vec.vector[2] = (3*x*x) - (12*x) + (y*y) - (3*z*z) + 8;

}


void sistEcu4(float x, float y, float z, Vector &vec){
    vec.vector[0] = (x*x) - (4*x) + (y*y);
    vec.vector[1] = (x*x) - x -(12*y) + 1;
    vec.vector[2] = (3*x*x) - (12*x) + (y*y) - (3*z*z) + 8;

}

void jacobiana1(float x, float y, Matrix &jac){
    jac.mat[0][0] = (2*x) + y;
    jac.mat[0][1] = x;
    jac.mat[1][0] = 3*y*y;
    jac.mat[1][1] = 1 + (6*x*y);
}

void jacobiana2(float x, float y, Matrix &jac){
    jac.mat[0][0] = 2*x;
    jac.mat[0][1] = 2*y;
    jac.mat[1][0] = -(exp(x));
    jac.mat[1][1] = -2;
}
void jacobiana3(float x, float y, float z, Matrix &jac){
    jac.mat[0][0] = 4*x - 4;
    jac.mat[0][1] = 2*y;
    jac.mat[0][2] = 6*z + 6;
    jac.mat[1][0] = 2*x;
    jac.mat[1][1] = 2*y - 2;
    jac.mat[1][2] = 4*z;
    jac.mat[2][0] = 6*x - 12;
    jac.mat[2][1] = 2*y;
    jac.mat[2][2] = -6*z;
}

void jacobiana4(float x, float y, float z, Matrix &jac){
    jac.mat[0][0] = 2*x - 4;
    jac.mat[0][1] = 2*y;
    jac.mat[0][2] = 0;
    jac.mat[1][0] = 2*x - 1;
    jac.mat[1][1] = -12;
    jac.mat[1][2] = 0;
    jac.mat[2][0] = 6*x - 12;
    jac.mat[2][1] = 2*y;
    jac.mat[2][2] = -6*z;
}


/* int main (){
     Vector x =  Vector(2);
	 sistEcu1(2,1, x);
	 x.print_vector();
        
}*/
// int main (){
//     Matrix x =  Matrix(2);
//     jacobiana1(2,1,x);
//     x.print_matrix();

// }

