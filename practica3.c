/*****************************************************************************************
 * practica3.c
 * Control de salud: índice de masa corporal, cálculo de los valores de riesgo de enfermedad
 * cardíaca, variación de peso, y porcentaje de grasa corporal de una persona.
 * El usuario puede elegir entre estas opciones tantas veces como desee.
 * Para cada una, se pedirán los datos, se realizará el cálculo y se mostrará
 * el resultado por pantalla.
 *
 * Programadores: Álvaro Jiménez Palenzuela, Esther García Medina
 * Fecha: Octubre 2018
 *
 *****************************************************************************************/

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



/***********************************************************************************
 Función: leerDato
		Lee un valor real en el rango [min, max].
 Algoritmo:
        La función pide un valor real contenido entre los valores del rango y
        lo lee de teclado. Mientras que el usuario introduzca un valor que no
        cumpla esa condición, volverá a solicitar y leer el valor.
	Parámetros de entrada:
		min: mínimo valor válido
		max: máximo valor válido
 	Parámetro de salida (valor devuelto por la función):
        Valor real leído por teclado.
***********************************************************************************/
    double leerDato (double min, double max);


/***********************************************************************************
 Función: menu
		Presenta el menú y lee la opción tecleada por el usuario.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
    Parámetro de salida (valor devuelto por la función):
        Opción elegida por el usuario (entero).
************************************************************************************/
    int menu(void);


/**********************************************************************************
 Función: procesamiento_IMC
        Lee los datos necesarios para calcular el IMC, lo calcula y muestra por
        pantalla los resultados.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
 	Parámetros de salida:
        Ninguno
*************************************************************************************/
    void procesamiento_IMC(void);


 /**********************************************************************************
 Función: procesamiento_VMP
        Lee los datos del peso de varias semanas (número de semanas definido en
        VECES_PESO) y los almacena en un array.
        Calcula el peso máximo y mínimo, lo escribe por pantalla junto con la
        variación entre ambos. Escribe también por pantalla el peso de la primera
        y última semana y su variación.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
 	Parámetros de salida:
        Ninguno
***********************************************************************************/
    void procesamiento_VMP(void);


 /***********************************************************************************
 Función: procesamiento_REC
	 	Lee los datos necesarios para calcular el riesgo de enfermedad cardiaca, lo
 		calcula y muestra por pantalla los resultados.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
 	Parámetros de salida:
        Ninguno
************************************************************************************/
    void procesamiento_REC(void);


/*************************************************************************************
 Función: procesamiento_PGC
        Lee los datos necesarios para calcular el porcentaje de grasa corporal, lo
        calcula y muestra por pantalla los resultados.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
 	Parámetros de salida:
        Ninguno
***************************************************************************************/
    void procesamiento_PGC(void);


/**************************************************************************************
 Función: riesgo
        Calcula el índice de riesgo de enfermedad cardiaca (ldl/hdl) e indica si hay
        riesgo (indice>3) o si no lo hay.
 Algoritmo:
 	Parámetros de entrada:
 		ldl: colesterol “malo” en mg/dL
 		hdl: colesterol “bueno” en mg/dL
    Precondiciones: ldl y hdl deben estar entre los rangos válidos.
    Parámetros de salida:
        hayRiesgo: mensaje "Hay riesgo cardiovascular" o "No hay riesgo cardiovascular"
    Parámetro de salida (valor devuelto por la función):
        Valor del índice de riesgo.
 ***************************************************************************************/
    double riesgo (double ldl, double hdl, char* hayRiesgo);


/* Funciones a describir por el alumno/a con sus comentarios de cabecera. */

/**************************************************************************************
 Función: indiceMC
        Recibe el peso y la altura y devuelve el Indice de Masa Corporal
 Precondiciones: los valores del peso (en Kgs), deben estar entre 5.0 y 150.0 y
                 los de la talla (en metros) entre 0.5 y 2.20.
 Algoritmo:  calcula el índice de masa corporal invocando a la función procesamientoIMC
 	Parámetros de entrada: peso (en Kgs), talla (en metros).
 	Precondiciones:

 	Parámetros de salida: Devuelve las cadenas de caracteres “Debería controlar su peso”
 	para el caso de delgadez severa (IMC < 16.0) y en caso de obesidad (IMC >= 30.0)
 	o “Peso aceptable” para el resto de los casos.

 	Parámetro de salida (valor devuelto por la función): devuelve el valor del indice de
    masa corporal.
 ***************************************************************************************/
    double indiceMC(double peso,double talla);


/**************************************************************************************
 Función: grasaCorporal
        Recibe el Indice de Masa Corporal, la edad y el sexo y calcula y devuelve
        el porcentaje de masa corporal
 Algoritmo:
 	Parámetros de entrada: La edad y el IMG
 	Precondiciones:

 	Parámetros de salida: Cadena de caracteres que contiene el sexo de la persona
 	y cadena de caracteres que contiene el mensaje "OBESIDAD" o "NORMAL", dependiendo del
 	resultado de calcular el porcentaje de grasa corporal.

 	Parámetro de salida (valor devuelto por la función): Ninguno
 ***************************************************************************************/
    void  grasaCorporal (double edad, double IMG, char* sexo, char* grasa);


/**************************************************************************************
 Función: pesoMes
        Lee de la entrada estándar los pesos registrados en un mes y los almacena en un
        array de tamaño VECES_PESO
 Algoritmo:
 	Parámetros de entrada: Array que contiene los pesos registrados en las semanas del mes
    Precondiciones:
 	Parámetros de salida: Ninguno
 	Parámetro de salida (valor devuelto por la función): Ninguno
 ***************************************************************************************/
    void pesosMes (double vectorPesos[]);


/**************************************************************************************
 Función: pesoMinMax
        Recibe la serie de pesos del mes y calcula y devuelve el peso máximo y el mínimo
 Algoritmo:
 	Parámetros de entrada: Array que contiene los pesos registrados en las semanas del mes

    Precondiciones:

 	Parámetros de salida: Se devuelven el peso mínimo, el máximo, la diferencia entre ambos,
 	y el peso de la primera semana y de la última y la diferencia de peso entre la primera y
 	la última semana.

 	Parámetro de salida (valor devuelto por la función): Ninguno
 ***************************************************************************************/
    void pesoMinMax (double vectorPesos[], double *p_pesoMin, double *p_pesoMax);



 /* Función principal */

int main(void)
{
	int opcion;

	do
	{
		opcion=menu();
		switch(opcion)
		{
			case 1: /* Índice de Masa Muscular */
				procesamiento_IMC();
				break;

			case 2: /* Variación Mensual del Peso */
				procesamiento_VMP();
				break;

			case 3: /* Riesgo de Enfermedad Cardiovascular */
				procesamiento_REC();
				break;

			case 4: /* Porcentaje de Grasa Corporal */
				procesamiento_PGC();
				break;

			case 5:
				printf("\n\nFIN DEL PROGRAMA.\n\n");
				break;

			default:
				printf("\n\nOpcion incorrecta.\n\n");
		}

	} while(opcion != 5);

return 0;
}

/* FUNCIONES  ***/

/* Codificación completa de menu  */

int menu(void){
    int n;

while(n != 5){
    printf("\n 1.- Indice de Masa Corporal");
    printf("\n 2.- Variacion mensual del peso");
    printf("\n 3.- Riesgo de enfermedad cardiovascular");
    printf("\n 4.- Porcentaje de grasa corporal");
    printf("\n 5.- Salir");
    printf("\n Escoja una opcion : ");
    fflush(stdin);
    scanf("%d", &n);
    return n;
}

}




/* Codificación completa de leerDato  */

double leerDato (double min, double max){
double dato;

    do{
        printf("Introduzca un valor real comprendido entre %g y %g: ", min, max);
        fflush(stdin);
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


/* Codificación completa de indiceMC  */

double indiceMC(double peso, double talla){

    double IMC;

    IMC= peso/(talla*talla);

    return IMC;
}


/* Codificación completa de pesosMes  */

void pesosMes(double vectorPesos[]) {
int i; /*indice del array pesosMes, es decir, número de la semana */

printf("\nIntroduzca los pesos que ha registrado este mes\n");

for(i=0; i < (VECES_PESO); i++){
    printf("\nIntroduzca el peso de la semana %d\n", (i+1));

    vectorPesos[i] = leerDato(MIN_PESO,MAX_PESO);
}
}


/* Codificación completa de pesoMinMax  */

void pesoMinMax(double vectorPesos[], double *p_pesoMin, double *p_pesoMax) {
    int j;
double pesoMin;
double pesoMax;
double variacionPeso;
double variacionMinMax;
double* p_variacionMinMax;
double* p_variacionPeso;

pesoMax = vectorPesos[0];
pesoMin = vectorPesos[0];


for(j=0; j< (VECES_PESO); j++){

    if(pesoMin >= vectorPesos[j]){
        pesoMin = vectorPesos[j];
    }
}
for(j=0; j < (VECES_PESO); j++){

    if(pesoMax <= vectorPesos[j]){
        pesoMax = vectorPesos[j];
    }
}
p_pesoMin = &pesoMin;
p_pesoMax = &pesoMax;
variacionMinMax = pesoMax - pesoMin;
variacionPeso = vectorPesos[3] - vectorPesos[0];

p_variacionMinMax = &variacionMinMax;
p_variacionPeso = &variacionPeso;

printf("Peso maximo: %g y peso minimo: %g                       Variacion: %g\n", *p_pesoMax, *p_pesoMin, *p_variacionMinMax);
printf("Peso primera semana: %g y peso ultima semana: %g        Variacion: %g\n", vectorPesos[0], vectorPesos[3] ,*p_variacionPeso);

}


/* Codificación completa de riesgo  */

double riesgo (double ldl, double hdl, char* hayRiesgo){
double indiceRiesgo;


indiceRiesgo = ldl/hdl;
    if(indiceRiesgo>3){
        strcpy(hayRiesgo,"Hay riesgo cardiovascular");
         printf("%s ya que el indice de riesgo es %g. (limite 3)\n", hayRiesgo, indiceRiesgo);
    }
    else{
        strcpy(hayRiesgo,"No hay riesgo cardiovascular");
        printf("%s ya que el indice de riesgo es %g. (limite 3)\n", hayRiesgo, indiceRiesgo);
    }

}


/* Codificación completa de grasaCorporal  */

void   grasaCorporal (double edad, double IMG, char* sexo, char* grasa) {
    double porcentajeGrasa;

    if(strcmp(sexo, "hombre\n") == 0){
       porcentajeGrasa = 1.2*IMG + 0.23*edad -16.2;

        if(porcentajeGrasa>=25){
            strcpy(grasa,"OBESIDAD");
            printf("\nEl porcentaje de grasa corporal es %g y hay %s\n", porcentajeGrasa, grasa);
        }
        else{
            strcpy(grasa,"NORMAL");
            printf("\nEl porcentaje de grasa corporal es %g y es %s\n", porcentajeGrasa, grasa);
        }
    }
    else{
        porcentajeGrasa = 1.2*IMG+0.23*edad -5.4;

        if(porcentajeGrasa>=30){
            strcpy(grasa,"OBESIDAD");
            printf("\nEl porcentaje de grasa corporal es %g y hay %s\n", porcentajeGrasa, grasa);
        }
        else{
            strcpy(grasa,"NORMAL");
            printf("\nEl porcentaje de grasa corporal es %g y es %s\n", porcentajeGrasa, grasa);
        }
    }

}



/** Codificación completa de procesamiento_IMC  **/

 void procesamiento_IMC(void) {
    double peso;
    double talla;
    double IMC;
    printf("\nIntroduzca el peso\n");

    peso = leerDato(MIN_PESO,MAX_PESO);

    printf("\nIntroduzca la talla\n");

    talla = leerDato(MIN_TALLA,MAX_TALLA);




    IMC = indiceMC(peso, talla);

    printf("\nIMC = %g  ", IMC);

    if(IMC<16.0 || IMC>=30.0)
        printf("Deberia controlar su peso\n");
    else
        printf("Peso aceptable\n");
 }


/** Codificación completa de procesamiento_VMP  **/

void procesamiento_VMP(void){
    double pesos[VECES_PESO];
    double pesoMinimo;
    double pesoMaximo;

    pesosMes(pesos);

    pesoMinMax(pesos, &pesoMinimo, &pesoMaximo);

}


/** Codificación completa de procesamiento_REC  **/

void procesamiento_REC(void){
 double LDL;
 double HDL;
 char hayRiesgo[MAX_CAD];


 printf("Introduzca el valor de LDL y de HDL\n");

 LDL = leerDato(MIN_LDL,MAX_LDL);

 HDL = leerDato(MIN_HDL,MAX_HDL);

 riesgo(LDL,HDL, hayRiesgo);
}


/** Codificación completa de procesamiento_PGC  **/

void procesamiento_PGC(void){
double edad;
double IMG;
char grasa[MAX_CAD];
char sexo[MAX_CAD];


printf("Introduzca su IMG\n");
IMG = leerDato(MIN_IMC,MAX_IMC);

printf("Escriba su edad\n");
edad= leerDato(MIN_EDAD,MAX_EDAD);


printf("Introduzca su sexo (hombre o mujer en minusculas): ");
fflush(stdin);
fgets(sexo, MAX_CAD,stdin);

if(strcmp(sexo, "hombre") == 0 || strcmp(sexo, "mujer") == 0){
    printf("\nERROR: No se ha indicado el sexo correctamente");

    }

grasaCorporal(edad, IMG, sexo, grasa);
}
