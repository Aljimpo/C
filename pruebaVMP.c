#include <stdio.h>
#include <string.h>

/* Definicion de constantes */

#define VECES_PESO 4

void pesosMes(double* pesomes){
    
int i;

scanf("%lf" "%lf" "%lf" "%lf",&pesomes[1],&pesomes[2],&pesomes[3],&pesomes[4]);

}

void main (void){

    double pesomes[VECES_PESO];
    pesosMes(pesomes);

    double peso_min;
    peso_min = pesomes[1];

    double peso_max;
    peso_max = pesomes[4];

    int i;

    for(i=1;i<sizeof(VECES_PESO);i++){
        if (peso_min < pesomes[i]){
            peso_min = pesomes[i];
        }
        if (peso_max > pesomes[i]){
            peso_max = pesomes[i];
        }
}

printf("%f\n",peso_min);
printf("%f\n",peso_max);
}


void pesoMinMax (void);
