#include <stdio.h>
#include <string.h>

/* Definición de constantes */

#define MIN_HDL 20.0
#define MAX_HDL 80.0

#define MIN_LDL 100.0
#define MAX_LDL 220.0

#define MIN_EDAD 1.0
#define MAX_EDAD 105.0

#define MIN_PESO 5.0
#define MAX_PESO 150.0

#define MIN_TALLA 0.5
#define MAX_TALLA 2.20

#define MIN_IMC 0.0
#define MAX_IMC 100.0

#define VECES_PESO 4

#define MAX_CAD 30
void pesosMes(double* pesomes){
int i;


   for(i=1;i<sizeof(VECES_PESO);i++){
        scanf("%lf\n",&pesomes[i]);
    }

//    printf("%f\n\n",pesomes[2]);


}

void main (void){

    double pesomes[VECES_PESO];
    pesosMes(pesomes);

    double peso_min;
    peso_min = pesomes[0];

    double peso_max;
    peso_max = pesomes[1];

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
