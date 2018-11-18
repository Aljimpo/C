/*Ejercicio: Diseñar e implementar un programa que cuente y escriba en la salida
estándar cuántas letras vocales (mayúsculas o minúsculas) existen en una
secuencia de caracteres leída por la entrada estándar y terminada en ‘.’ (punto).
Donde el punto no pertenece a la secuencia de caracteres.
Para ello, debe definir y usar una función genérica que permita averiguar si una
letra es vocal o no, que debe tener la siguiente declaración:*/
#include <string.h>
#include <stdio.h>
void main(){
    int i;
    int numeroletras;
    char letras[1000];
    int numero;
    char ultchar;
    int contar=0;
    do{
        scanf("%s",&letras);

        numero= strlen(letras);

        ultchar =(letras[numero-1]);

        if(ultchar!='.'){
            printf("Error, la cadena debe terminar en .\n");
        }


    }while(ultchar!='.');


    for(i=0;i<numero;i++){
        contar += letraEsVocal(letras[i]);
    }
    printf("El numero de vocales en la cadena es: %d",contar);

}

int letraEsVocal(char* letra){

if(letra=='a' || letra == 'e' ||letra == 'i' || letra =='o' ||letra == 'u' ||letra == 'A' || letra == 'E' || letra == 'I' ||letra == 'O' || letra =='U'){
    return 1;
}else{
    return 0;
}


}
