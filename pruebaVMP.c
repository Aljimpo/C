#include <stdio.h>
#include <string.h>

/* Definicion de constantes */

#define VECES_PESO 4

void pesosMes(double* pesomes){
scanf("%lf" "%lf" "%lf" "%lf",&pesomes[0],&pesomes[1],&pesomes[2],&pesomes[3]);
}

void main (void){
    double pesomes[VECES_PESO];
    pesosMes(pesomes);
    pesoMinMax(pesomes);
}

void pesoMinMax (double *pesomes, double *peso_minn, double *peso_maxx){

    double pesomin;
    double pesomax;

    peso_minn = &pesomes[0];
    peso_maxx = &pesomes[0];

    pesomin = *peso_minn;
    pesomax = *peso_maxx;


    int i;
    for(i=0;i<sizeof(pesomes);i++){
        if (pesomes[i] < pesomin){
            pesomin = pesomes[i];
        }
        if (pesomes[i] > pesomax){
            pesomax = pesomes[i];
        }
    }
    printf("El peso min es:%f\n",pesomin);
    printf("El peso max es:%f\n",pesomax);
}

