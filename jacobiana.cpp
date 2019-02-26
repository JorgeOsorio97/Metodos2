#include "libraries.h"
#include "matrix.cpp"

float sistEcu1(float, float);
float sistEcu2(float, float);
float sistEcu3(float, float, float);
float sistEcu4(float, float, float);
float jacobiana1(float, float);
float jacobiana2(float, float);
float jacobiana3(float, float, float);
float jacobiana4(float, float, float);


float sistEcu1(float x, float y){
    float aux1 = (x*x) + (x*y) - 10;
    float aux2 = y + (3*x*y*y) - 57;
    Vector vec1 = Vector(2);
    vec1.vector[0] = aux1;
    vec1.vector[1] = aux2;
}

float sistEcu2(float x, float y){
    float aux1 = 4 -(x*x) - (y*y);
    float aux2 = 1 - (pow(exp(1.0), -x)) - y;
    Vector vec2 = Vector(2);
    vec2.vector[0] = aux1;
    vec2.vector[1] = aux2;
}

float sistEcu3(float x, float y, float z){
    float aux1 = (2*x*x) - (4*x) +(y*y) +(3*z*z) + (6*z) + 2;
    float aux2 = (x*x) + (y*y) - (2*y) + (2*z*z) - 5;
    float aux3 = (3*x*x) - (12*x) + (y*y) + (3*z*z) + 8;
    Vector vec3 = Vector(3);
    vec3.vector[0] = aux1;
    vec3.vector[1] = aux2;
    vec3.vector[2] = aux3;
}


float sistEcu4(float x, float y, float z){
    float aux1 = (x*x) - (4*y) + (y*y);
    float aux2 = (x*x) - x -(12*y) + 1; 
    float aux3 =(3*x*x) - (12*x) + (y*y) + (3*z*z) + 8;
    Vector vec4 = Vector(3);
    vec4.vector[0] = aux1;
    vec4.vector[1] = aux2;
    vec4.vector[2] = aux3;
}

float jacobiana1(float x, float y){
    float df1x = (2*x) + y;
    float df1y = x;
    float df2x = 3*y*y;
    float df2y = 1 + (6*x*y);
    Matrix jac1 = Matrix(2);
    jac1.mat[0][0] = df1x;
    jac1.mat[0][1] = df1y;
    jac1.mat[1][0] = df2x;
    jac1.mat[1][1] = df2y;
}
