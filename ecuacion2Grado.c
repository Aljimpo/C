#include <stdio.h>
#include <math.h>
#define ECUACIONRAICES_NOERROR 0
#define ECUACIONRAICES_NOREALES 1

int ecuacionRaices(float a, float b, float c, float *raiz1, float *raiz2);
void main (){

    float a;
    float b;
    float c;

    do{
        printf("Escriba el primer coeficiente de la ecuacion de segundo grado\n");
        scanf("%f",&a);
    }while(a<0);

    printf("Escriba el segundo coeficiente de la ecuacion de segundo grado\n");
    scanf("%f",&b);
    printf("Escriba el tercer coeficiente de la ecuacion de segundo grado \n");
    scanf("%f",&c);

    float raiz1,raiz2;

    if( ecuacionRaices(a,b,c,&raiz1,&raiz2) == 1){
        printf("La ecuacion no tiene raices reales\n");
    }else{
        printf("La ecuacion tiene solucion y es: \n");
        printf("La raiz 1 es: %lf", raiz1);
        printf("La raiz 2 es: %lf", raiz2);

    }

}

int ecuacionRaices(float a, float b, float c, float *raiz1, float *raiz2){


    *raiz1=((-1)*b+sqrt((b*b-(4*a*c))))/(2*a);
    *raiz2=((-1)*b-sqrt((b*b-(4*a*c))))/(2*a);



    if(((b*b-(4*a*c)))<0){
        return ECUACIONRAICES_NOREALES;
    }else{
        return ECUACIONRAICES_NOERROR;
    }



}
