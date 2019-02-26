#include "libraries.h"
#include "matrix.cpp"

Vector sistEcu1(float, float);
Vector sistEcu2(float, float);
Vector sistEcu3(float, float, float);
Vector sistEcu4(float, float, float);
Matrix jacobiana1(float, float);
Matrix jacobiana2(float, float);
Matrix jacobiana3(float, float, float);
Matrix jacobiana4(float, float, float);


Vector sistEcu1(float x, float y){
    Vector vec1 = Vector(2);
    vec1.vector[0] = (x*x) + (x*y) - 10;
    vec1.vector[1] = y + (3*x*y*y) - 57;
    return vec1;
}

Vector sistEcu2(float x, float y){
    Vector vec2 = Vector(2);
    vec2.vector[0] = 4 -(x*x) - (y*y);
    vec2.vector[1] = 1 - (pow(exp(1.0), -x)) - y;
    return vec2;
}

Vector sistEcu3(float x, float y, float z){
    Vector vec3 = Vector(3);
    vec3.vector[0] = (2*x*x) - (4*x) +(y*y) +(3*z*z) + (6*z) + 2;
    vec3.vector[1] = (x*x) + (y*y) - (2*y) + (2*z*z) - 5;
    vec3.vector[2] = (3*x*x) - (12*x) + (y*y) + (3*z*z) + 8;
    return vec3;
}


Vector sistEcu4(float x, float y, float z){
    Vector vec4 = Vector(3);
    vec4.vector[0] = (x*x) - (4*y) + (y*y);
    vec4.vector[1] = (x*x) - x -(12*y) + 1;
    vec4.vector[2] = (3*x*x) - (12*x) + (y*y) + (3*z*z) + 8;
}

Matrix jacobiana1(float x, float y){
    Matrix jac1 = Matrix(2);
    jac1.mat[0][0] = (2*x) + y;
    jac1.mat[0][1] = x;
    jac1.mat[1][0] = 3*y*y;
    jac1.mat[1][1] = 1 + (6*x*y);
    return jac1;
}

Matrix jacobiana2(float x, float y){
    Matrix jac2 = Matrix (2);
    jac2.mat[0][0] = -2*x;
    jac2.mat[0][1] = -2*y;
    jac2.mat[1][0] = (pow(exp(1.0), -x));
    jac2.mat[1][1] = -1;
}
Matrix jacobiana3(float x, float y, float z){
    Matrix jac3 =  Matrix(3);
    jac3.mat[0][0] = 4*x - 4;
    jac3.mat[0][1] = 2*y;
    jac3.mat[0][2] = 6*z + 6;
    jac3.mat[1][0] = 2*x;
    jac3.mat[1][1] = 2*y - 2;
    jac3.mat[1][2] = 4*z;
    jac3.mat[2][0] = 6*x - 12;
    jac3.mat[2][1] = 2*y;
    jac3.mat[2][2] = 6*z;
}

Matrix jacobiana4(float x, float y, float z){
    Matrix jac4 = Matrix (3);
    jac4.mat[0][0] = 2*x;;
    jac4.mat[0][1] = 2*y - 4;
    jac4.mat[0][2] = 0;
    jac4.mat[1][0] = 2*x - 1;
    jac4.mat[1][1] = -12;
    jac4.mat[1][2] = 0;
    jac4.mat[2][0] = 6*x - 12;
    jac4.mat[2][1] = 2*y;
    jac4.mat[2][2] = -6*z;
}