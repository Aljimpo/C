#include <stdio.h>
#define ELEMENTOS 4
void main(){

    int array1[ELEMENTOS]={1,21,12,4};
    int buscar;
    printf("El array es 1,21,12,4\n");
    printf("Introduzca un numero para comprobar si esta en el array\n");

    scanf("%d",&buscar);

    int i=0; int encontrar=0;

    do{
        encontrar = (buscar==array1[i]);
        i++;
    }while(encontrar==0 && i<ELEMENTOS);

    if (encontrar){
        printf("Encontrado");
    }else{
        printf("No encontrado");
    }

}
