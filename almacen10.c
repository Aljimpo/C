/*Ejercicio: Codificar un programa en C que mantenga almacenado los 10 últimos
números enteros, incluido el 0, introducidos por teclado. Si el número
introducido es el 0, el programa mostrará por pantalla dichos números y
finalizará.*/

#include <stdio.h>

#define DIEZ 10
int main(){

    int i=0;
    int b;
    int num[10];
    int tamano =sizeof(num) / sizeof(num[0]);

    printf("Introduzca numeros y termina con 0\n");

    do{

        if(i<10){
            i++;
            scanf("%d",&num[i]);
        }else{
            for(b=1;b<10;b++){
                num[b]=num[b+1];
            }
            scanf("%d",&num[10]);
        }

    }while(num[i]!=0 && num[10]!=0);

    printf("Los ultimos 10 numeros introducidos son:\n");
    int c;
    for(c=1;c<i;c++){
            printf("%d\n",num[c]);

    }

}
