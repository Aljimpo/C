#include <stdio.h>
#include <string.h>
#define ELEMENTOS 4
void main(){

    int array1[ELEMENTOS]={1,21,12,4};
    int array2[ELEMENTOS]={1,21,12,4};
    int i=0; int iguales;

    do{
        iguales=(array1[i]==array2[i]);
        i++;
    }while(iguales && i<ELEMENTOS);

    if (iguales){
        printf("array1 y array2 son iguales");
    }else{
        printf("array1 y array2 son diferentes");
    }

}
