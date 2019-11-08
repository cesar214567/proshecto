#include <iostream>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  
#include <cmath>
#define TAMANO_DE_MATRIZ 1000
using namespace std; 
double **matrix,diferencial;
/*double get_materia(int celda, int numero ){
    if(celda>=TAMANO_DE_MATRIZ || celda<0){
        return 0;
    }
    if (matrix[numero][celda]!=-1){
        return matrix[numero][celda];
    }else{
        matrix[numero][celda]=(get_materia(celda,numero-1)*(get_materia(celda+1,numero-1)-get_materia(celda,numero-1))+get_materia(celda+2,numero-1)-get_materia(celda+1,numero-1)-get_materia(celda-1,numero-1))/1000;
        return matrix[numero][celda];
    }   
}*/
double get_materia(int celda, int numero){
    if(celda>=TAMANO_DE_MATRIZ || celda<0){
        return 0;
    }
    if (matrix[numero][celda]!=-1){
        return matrix[numero][celda];
    }else{
        matrix[numero][celda]=get_materia(celda,numero-1)+3*(diferencial*TAMANO_DE_MATRIZ)*get_materia(celda,numero-1)*(get_materia(celda+1,numero-1)-get_materia(celda-1,numero-1));
        matrix[numero][celda]-=(diferencial*TAMANO_DE_MATRIZ*TAMANO_DE_MATRIZ*TAMANO_DE_MATRIZ/2/*recordar que dif x=1/tamano de matriz*/)*(get_materia(celda+2,numero-1)-2*get_materia(celda+1,numero-1)+2*get_materia(celda-1,numero-1)-get_materia(celda-2,numero-1));
        return matrix[numero][celda];
    }
}



int main(){
    srand (time(NULL));
    double tiempo,celda;
    int numero;
    cout<<"ingrese el numero de celda a buscar desde 0 a 999"<<endl;
    cin>> celda;
    cout<<"ingrese el numero en donde quiere buscar"<<endl;
    cin>>tiempo;
    cout<<"ingrese la diferencial del tiempo"<<endl;
    cin>>diferencial;
    numero=tiempo/diferencial;
    cout<<numero;
    matrix=new double*[numero];
    for (int i=0;i<numero;i++){
        matrix[i]=new double[TAMANO_DE_MATRIZ];
    }
    for (int i=0;i<numero;i++){
        for (int j=0;j<TAMANO_DE_MATRIZ;j++){
            if (i!=0){
                matrix[i][j]=-1;
            }else{
                matrix[i][j]=-0.5*pow(1/cosh(j/2.0),2);
            }
            
        }
    }
    
    cout<<"la cantidad de materia en la celda "<<celda<<" en el numero"<< numero<<" es "<<get_materia(celda,numero-1)<<endl;
    cout<<endl;
    for (int j=0;j<TAMANO_DE_MATRIZ;j++){
            cout<<matrix[0][j]<<" ";
        }
        cout<<endl;

    for (int i=0;i<numero/2;i++){
        cout<<i<<endl;
        for (int j=0;j<TAMANO_DE_MATRIZ;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
