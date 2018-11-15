#include <stdio.h>
#include <string.h>

double leerDato (double min, double max){
double dato;

    do{
        printf("Introduzca un valor real comprendido entre %f y %f: ",min,max);
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

double riesgo (double ldl, double hdl, char* hayRiesgo){
    double indiceRiesgo;
    indiceRiesgo = ldl/hdl;
    char positivo[] ="Hay riesgo cardiovascular ya que el indice de riesgo es";
    char negativo[] ="No hay riesgo cardiovascular ya que el indice de riesgo es";
    int i;
    if (indiceRiesgo>3){
        strcpy(hayRiesgo,positivo);
    }else{
        strcpy(hayRiesgo,negativo);
    }
    return indiceRiesgo;
}

void main(){
    printf("Introduzca el valor de LDL y HDL\n");
    char hayRiesgo[100];
    double ldl=leerDato(100,220);
    double hdl=leerDato(20,80);
    double valorRiesgo = riesgo(ldl,hdl,hayRiesgo);
    printf("%s %f (limite 3)",hayRiesgo,valorRiesgo);
}
