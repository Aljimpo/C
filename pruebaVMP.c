#include <stdio.h>
#include <string.h>

/* Definicion de constantes */

#define VECES_PESO 4

void pesosMes(double pesomes[]){
int i;
for(i=0;i<VECES_PESO;i++){
    printf("Introduzca el peso de la semana %i: ",i);
    scanf("%lf",&pesomes[i]);
}

}

void main (void){
    double pesomes[VECES_PESO];
    double pesomax,pesomin;
    pesosMes(pesomes);
    pesoMinMax(pesomes,&pesomin,&pesomax);


    printf("Peso maximo %f y minimo %f \n",pesomax,pesomin);
    printf("Peso primera semana %f y peso ultima semana %f\n",pesomes[0],pesomes[3]);
    printf("La diferencia de peso entre la primera y la ultima semana es: %f kilogramos",pesomes[0]-pesomes[3]);
}

void pesoMinMax (double pesomes[], double *pesomin, double *pesomax){

     *pesomin = *pesomes;
     *pesomax = *pesomes;

    int i;
    for(i=0;i<VECES_PESO;i++){
        if (pesomes[i] < *pesomin){
            *pesomin = pesomes[i];
        }
        if (pesomes[i] > *pesomax){
            *pesomax = pesomes[i];
        }
    }
}

