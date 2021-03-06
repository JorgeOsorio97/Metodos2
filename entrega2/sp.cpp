#include "../libraries.h"
#include "../Vector.h"
#include "matrix_gauss.cpp"


using namespace std;

 
void pob_mat(Matrix &m, Vector &h, Vector &s, int size){


    m.mat[0][0]=2*(h.vector[0]+h.vector[1]);
    m.mat[0][1]=h.vector[1];
    for (int i=2; i<size; i++){
       m.mat[0][i]=0;
    }
   
    for (int j=1; j<size-1; j++){
        int i= 0;
    
        for(i=0; i<j-1; i++){
            m.mat[j][i]=0;
        }
        
        
            m.mat[j][i]=h.vector[i+1];
            m.mat[j][i+1]=2*(h.vector[i+1]+h.vector[i+2]);
            m.mat[j][i+2]=h.vector[i+2];
        




        for (int i=j+2;i<size; i++){
            m.mat[j][i]=0;
        }
    }

    for(int i=0; i<size-2; i++){
       m.mat[size-1][i]=0;
    }

    m.mat[size-1][size-2]=h.vector[size-1];
    m.mat[size-1][size-1]=2*(h.vector[size-1]+h.vector[size]);
    


for (int j=0; j<size ; j++){
    for (int i=0;i<size; i++){
        
        m.vector[i]=s.vector[i];
    }
}
}

void spline (Vector &vx,Vector &vfx, int sizp)
{
    vx.print_vector();
    vfx.print_vector();
    cout<<sizp<<endl;
    Vector h = Vector(sizp);
    Vector dd= Vector(sizp);
    Vector ss= Vector(sizp-2);
    



    vx.Vector :: dif_h(vx,h);
    vfx.Vector :: dif_div(vfx,h,dd);
    dd.Vector :: dif_s(dd,ss, sizp-2);
    cout<<"tabla"<<endl;
    //cout<<"x"<<endl;
   // vx.print_vector();
    cout<<endl;
    //cout<<"f(x)"<<endl;
    //vfx.print_vector();
    cout<<endl;
    //cout<<"h"<<endl;
    //h.print_vector();
    cout<<endl;
    //cout<<"Diferencias divididas"<<endl;
    //dd.print_vector();
    cout<<endl;
    //cout<<"hola"<<endl;
    //cout<<"S_i resultados del sistema de ecuaciones"<<endl;
    //ss.print_vector();  
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int msize=sizp-2;

    Matrix mat = Matrix(msize);
    
    //cout<<"Matriz"<<endl;
    pob_mat(mat, h, ss, msize);
    //mat.print_matrix();
    // hasta aqui llena la tabla bien
    Matrix triangular = mat.gauss_elimination();
     cout<<"Matriz triangulada"<<endl;
     //triangular.print_matrix();
    float determinante = mat.determinant(triangular);
     cout<<"Determinante = "<< determinante<<endl;
    Vector res= Vector(sizp);
    Vector a= Vector(sizp);
    Vector b= Vector(sizp);
    Vector c= Vector(sizp);
    Vector d= Vector(sizp);
    res.vector[0]=0;
    res.vector[sizp-1]=0;
    for(int i=0; i<sizp-1; i++){
        res.vector[i+1] = mat.system_solution(triangular)[i];
         cout<<i<<endl;


    }
    
      //  res.print_vector();

    for (int i=0; i<sizp; i++){
        a.vector[i]=(res.vector[i+1]-res.vector[i])/(6*h.vector[i]);
        b.vector[i]=(res.vector[i])/(2);
        c.vector[i]=dd.vector[i]-((res.vector[i+1]+2*res.vector[i])/(6))*(h.vector[i]);
        d.vector[i]=vfx.vector[i];
    }
    a.vector[sizp-1]=0;
    cout<<"x"<<endl;
    vx.print_vector();
    cout<<"y"<<endl;
    vfx.print_vector();
    cout<<"h"<<endl;
    h.print_vector();
    cout<<"Matriz"<<endl;
    mat.print_matrix();
    cout<<"s"<<endl;
    res.print_vector();

    cout<<"a"<<endl;
    a.print_vector();
    cout<<"b"<<endl;
    b.print_vector();
    cout<<"c"<<endl;
    c.print_vector();
    cout<<"d"<<endl;
    d.print_vector();
for (int i=0; i<sizp-1;i++){
    cout<<"g"<<i<<"(x) =  ("<<a.vector[i]<<")(x-"<<vx.vector[i]<<")^3+("<<b.vector[i]<<")(x-"<<vx.vector[i]<<")^2+("<<c.vector[i]<<")(x-"<<vx.vector[i]<<")+("<<d.vector[i]<<")              "<<vx.vector[i]<<" <=  x < "<<vx.vector[i+1];
    cout<<endl;
    cout<<endl;
}
    
} 


