#include <stdio.h>

void main(){

    printf("1. Multiplicar dos numeros\n");
    printf("2. Potencia (base elevado a exponente)\n");
    printf("3. Factorial de un numero\n");
    printf("4. Salir\n");
    printf("Eliga una opcion\n");
    int opcion;
    scanf("%d",&opcion);

    switch(opcion){

        case 1:
            multiplica();
        case 2:
            potencia();
        case 3:
            factorial();
        case 4:
            break;

    }

}


void multiplica(){

    double num1;
    double num2;
    printf("Introduzca dos numeros\n");
    scanf("%lf %lf",&num1,&num2);
    printf("La multiplicacion es: %f",num1*num2);
}

void potencia(){
    double num1,num2;
    printf("Introduzca la base: \n");
    scanf("%lf",&num1);
    printf("Introduzca el exponente: \n");
    scanf("%lf",&num2);
    int i;
    double resul =1;
    for(i=0;i<num2;i++){
        resul = resul *num1;
    }
    printf("%f",resul);
}

void factorial(){
    int num;

    printf("Introduzca un numero\n");

    scanf("%d",&num);
    int i;
    int resul =1;
    for(i=1;i<=num;i++){

        resul = resul * i;
    }
    printf("%d",resul);
}
