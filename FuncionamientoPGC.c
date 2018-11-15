
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
#include <stdio.h>
#include <string.h>

double leerDato (double min, double max){
double dato;

    do{
        printf("Introduzca un valor real comprendido entre %g y %g:",min,max);
        scanf("%lf", &dato);

        if(min<=dato && dato<=max){
            return dato;
        }
        else{
            printf("ERROR: Valor fuera de rango");
        }
    }
    while(min<dato || dato<max);

}



void main (void){

    printf("Introduzca su IMC\n");
    double IMC = leerDato(MIN_IMC,MAX_IMC);

    printf("Escriba su edad\n");
    double edad = leerDato(MIN_EDAD,MAX_EDAD);

    printf("Introduzca su genero (hombre o mujer en minusculas)\n");
    char genero[10];
    char hombre[]="hombre";
    char mujer[]="mujer";
    scanf("%s",&genero);

    if ((strcmp(genero,hombre))==0 || (strcmp(genero,mujer))==0){
       grasaCorporal(genero,IMC,edad);

    }else{
        printf("ERROR: No se ha indicado el sexo correctamente.");
    }


}

void grasaCorporal (char *genero,double IMC,double edad){
    double grasa;
    char hombre[]="hombre";
    char mujer[]="mujer";

    if ((strcmp(genero,hombre))==0){
        grasa = (1.2*IMC)+(0.23*edad) -16.2;
    }if (strcmp(genero,mujer)==0){
        grasa = (1.2*IMC)+(0.23*edad) -5.4;
    }

    printf("El %c de grasa corporal es %f y hay OBESIDAD",37,grasa);
}
