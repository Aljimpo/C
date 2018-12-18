
#include <stdio.h>
#include <string.h>


/******     CONSTANTES    ******/

/** Longitud maxima del campo senial (emisión interestelar recibida) */
#define MAX_SENIAL 80

/** Longitud maxima del campo fecha */
#define MAX_FECHA 12

/** Longitud maxima del nombre de radiotelescopio */
#define MAX_NOMBRE 20

/** Número máximo de capturas que se pueden almacenar.
    Para poder probar la funcionalidad de la aplicación se ha reducido a 5 */
#define MAX_CAPTURAS 5

/** Longitud maxima de cada secuencia (subcadena) candidata a tener un origen no natural */
#define MAX_SUBCADENA 15

/** Número de secuencias candidatas a tener un origen no natural almacendas */
#define MAX_SUBCADENAS 5








/******     TIPOS DE DATOS   ******/

/** Tipo de dato para la variable que almacena las secuencias con posible origen no natural */
typedef char tSubcadena[MAX_SUBCADENA];
typedef tSubcadena tSubcadenas[MAX_SUBCADENAS];

typedef struct{
    char fecha[MAX_FECHA];
    }tFecha;
typedef struct{
    char nombre[MAX_NOMBRE];
    }tNombre;
typedef struct{
    char senial[MAX_SENIAL];
    }tSenial;

typedef struct{
        tSenial senial;
        tFecha fecha;
        tNombre nombre;
    }tCaptura;

typedef struct {
    tCaptura captura;
    int ocupado;
}tMiembroSeti;

typedef tMiembroSeti tSeti[MAX_CAPTURAS];




/******     PROTOTIPOS    ******/


/**************************************************************************************
 Función: inicializarCapturas
        Inicializa la estructura de datos.
    Parámetro de salida:
        capturas: estructura que almacena la información de la aplicación
 ***************************************************************************************/
void inicializarCapturas(tSeti capturas);


/**************************************************************************************
 Función: incluirCaptura
       Incluye una nueva captura, que es la señal recibida
       junto con la fecha y radiotelescopio de recepción.
    Parámetro de entrada/salida:
        capturas: estructura que almacena la información de la aplicación
***************************************************************************************/
void incluirCaptura (tSeti capturas);

/**************************************************************************************
 Función: haySitioEnCapturas
       Analiza si hay sitio en capturas para añadir una nueva captura.
    Parámetro de entrada:
        capturas: estructura que almacena la información de la aplicación
    Parámetro de salida (por referencia):
        sitio: índice del array donde hay sitio, en el caso de que lo haya.
    Parámetro de salida (valor devuelto por la función):
             1 si hay sitio
             0 si no hay sitio
    Postcondición: sólo en el caso de que el valor devuelto por la función
                    sea 1 tiene sentido el valor del parámetro "sitio"
***************************************************************************************/
int haySitioEnCapturas (const tSeti capturas, int *sitio);

/**************************************************************************************
 Función: existeCaptura
       Analiza si existe en capturas una captura con el nombre de
       radiotelescopio igual a "nom".
    Parámetros de entrada:
        capturas: estructura que almacena la información de la aplicación
        nom: nombre del radiotelescopio que se busca
    Parámetro de salida (por referencia):
        pos: índice del array donde está la captura asociada al radiotelescopio
              de nombre "nom", en el caso de que exista dicha captura.
    Parámetro de salida (valor devuelto por la función):
             1 existe
             0 no existe
    Postcondición: sólo en el caso de que el valor devuelto por la función
                    sea 1 tiene sentido el valor del parámetro "pos"
*******************************************************************************/
int existeCaptura(const tSeti capturas, const tNombre nom, int *pos);

/**************************************************************************************
 Función: analizarCapturas
       El análisis consiste en buscar, en la señal de cada captura, la
       aparición de alguna secuencia candidata a tener un origen no natural.
       Si una señal incluye alguna de estas secuencias, se convierte
       en señal prometedora y los datos de la captura que la contiene
       se imprimen por pantalla.
    Parámetros de entrada:
        capturas: estructura que almacena la información de la aplicación
        secuencias: array de cadenas de caracteres que contiene las
                    subcadenas (secuencias) candidatas a tener un origen
                    no natural.

***************************************************************************************/
void analizarCapturas(const tSeti capturas, const tSubcadenas secuencias);

int main(void){

    /** se leerán del fichero de texto "emisionesInteligentes.txt" */

    FILE *emisionesinteligentes;
    tSubcadenas subcs;
    char str[1000];
    int i=0;
    char* filename = "C:/Users/Alvaroo/Desktop/Fase 2/Fase2/emisionesinteligentes.txt";
    char guardar[50];

    emisionesinteligentes = fopen(filename, "r");

    while(fgets(str,1000,emisionesinteligentes)!=NULL){

        strcpy(subcs[i],str);
        i++;
    }
    fclose(emisionesinteligentes);

    printf("/************************************************************************\n"
           "/*  PROGRAMACION I. CURSO 2018-2019. PRACTICA 4.                        *\n"
           "/*  PROYECTO SETI                                                       *\n"
           "/*  La aplicacion procesa señales que llegan a la tierra desde el       *\n"
           "/*  espacio exterior. El usuario puede:                                 *\n"
           "/*       1.- Incluir una nueva captura, que es la señal recibida        *\n"
           "/*           junto con la fecha y radiotelescopio de recepcion.         *\n"
           "/*       2.- Analizar las capturas en busca de señales candidatas       *\n"
           "/*           a tener un origen no natural y escribir los datos de       *\n"
           "/*           las mismas en un fichero.                                  *\n"
           "/*       3.- Visualizar datos de una captura.                           *\n"
           " ************************************************************************ \n");

    tSeti capturas;
    inicializarCapturas(capturas);
    int opcion;

    do
    {   opcion=menu();
        fflush(stdin);
        switch(opcion)
        {
            case 1:
                incluirCaptura(capturas);
                break;

            case 2:
                analizarCapturas(capturas,subcs);
                break;

            case 3:
                datosCaptura(capturas);
                break;

            case 4:
                printf("\n\nFIN DEL PROGRAMA.\n\n");
                printf("\n\n GUARDANDO LOS DATOS\n\n");
                FILE *guardar;
                int i;
                char str[1000];

                guardar = fopen("C:/Users/Alvaroo/Desktop/Fase 2/Fase2/datosRegistrados.txt","w");

                for(i=0;i<MAX_CAPTURAS;i++){
                    fprintf(guardar,"%s",capturas[i].captura.nombre.nombre);
                    fprintf(guardar,"%s",capturas[i].captura.fecha.fecha);
                    fprintf(guardar,"%s",capturas[i].captura.senial.senial);
                }


                break;

            default:
                printf("\n\nOpcion incorrecta.\n\n");
        }

    } while(opcion != 4);

return 0;
}/* Fin del menu */


int menu(void){
    int n;

    while(n != 4){
        printf(" ****************************** Opciones ********************************\n *"
               "  1. Incluir captura                                                  *\n *"
               "  2. Analizar capturas y emitir reporte                               *\n *"
               "  3. Visualizar datos de un radiotelescopio                           *\n *"
               "  4. Salir                                                            *\n *"
               "                                                                      *\n *"
               "  ELIJA UNA OPCION:                                                   *\n"
               " ************************************************************************\n");

        fflush(stdin);
        scanf("%d", &n);
        fflush(stdin);
        return n;


    }

}/* Fin del menu */

/*Por último, se implementará la funcionalidad relativa a la Opción 3 del menú con la función datosCaptura().
 Se solicitará el nombre del radiotelescopio de la captura a buscar y se leerá.
Se comprobará que existen datos asociados a ese radiotelescopio y, en caso de existir, se mostrarán por la salida estándar.*/







void analizarCapturas(const tSeti capturas, const tSubcadenas secuencias){
    int i;
    int b;

    for(i=0;i<MAX_CAPTURAS;i++){
        for(b=0;b<MAX_CAPTURAS;b++){
            //printf("La captura es : %s\n",capturas[i].captura.senial.senial);
            //printf("La secuencia es: %s\n",secuencias[b]);
            if(strstr(capturas[i].captura.senial.senial,secuencias[b]) != NULL) {
                printf("Captura prometedora.... :\n");
                printf("\n*********\n%s\n----------\n%s----------\n%s\n",capturas[i].captura.nombre.nombre,capturas[i].captura.fecha.fecha,capturas[i].captura.senial.senial);


                FILE *reportes;
                //printf("Creamos variable reportes\n");
                char* direccion= "C:/Users/Alvaroo/Desktop/Fase 2/Fase2/reportes.txt";
                //printf("Creamos variable char\n");
                reportes = fopen(direccion,"ab");
                //printf("abrimos direccion\n");

                fputs("Captura prometedora.... :\n",reportes);
                fputs("\n*********\n",reportes);
                fprintf(reportes,"%s\n----------\n",capturas[i].captura.nombre.nombre);
                fprintf(reportes,"%s----------\n",capturas[i].captura.fecha.fecha);
                fprintf(reportes,"%s\n",capturas[i].captura.senial.senial);

                //printf("Escribimos en el archivo");
                fclose(reportes);
                //printf("Cerramos");
            }
        }
    }

}


void datosCaptura(tSeti capturas){
    tSubcadena telescopio;
    int i;
    printf("Introduzca el nombre del radiotelescopio: \n");

    fgets(telescopio,MAX_NOMBRE,stdin);
    fflush(stdin);
    int contador=0;
    int pos;
    for (i=0;i<MAX_CAPTURAS;i++){
        if(strcmp(capturas[i].captura.nombre.nombre,telescopio)==0)
            contador = contador +1;
            pos = i;
    }
    if(contador >=1){
        printf("\n\n\n*********\n%s\n----------\n%s----------\n%s",telescopio,capturas[pos].captura.fecha.fecha,capturas[pos].captura.senial.senial);
    }else{
        printf("No existen datos de ese radiotelescopio\n\n");
    }
}

void incluirCaptura (tSeti capturas){

    tNombre nombre;
    tSenial senial;
    tFecha fecha;
    int pos;
    int sitio =0;

    fflush(stdin);

    printf("Escriba el nombre del radiotelescopio\n");
    fgets(nombre.nombre,MAX_NOMBRE,stdin);
    // printf("post nombre\n");


    int existe = existeCaptura(capturas,nombre,&pos);
    // printf("post existe\n");
    // printf("El valor de existe es: %d\n",existe);

    if (existe==0){
        printf("Ya existe un radiotelescopio con ese nombre. Se sustituye la senial recibida.\n");

          printf("Introduzca la senial (emision interestelar):\n");

            fflush(stdin);

            fgets(senial.senial,MAX_SENIAL,stdin);

            strcpy(capturas[pos].captura.senial.senial,senial.senial);

            printf("Introduzca la fecha con formato dd-mm-aa:\n");

            fflush(stdin);

            fgets(fecha.fecha,MAX_FECHA,stdin);

            strcpy(capturas[pos].captura.fecha.fecha,fecha.fecha);
    }
    else if(existe == 1){
        printf("No hay capturas previas de este radiotelescopio.\n");

        if(haySitioEnCapturas(capturas,&sitio)){
            // printf("Se aniade a la red\n");
            // printf("El sitio es %d\n",sitio);
            // printf("El nombre es %s\n",nombre.nombre);

            strcpy(capturas[sitio].captura.nombre.nombre,nombre.nombre);
            // printf("El nombre guardado en la posicion %d de memoria es: %s\n",sitio,capturas[sitio].captura.nombre.nombre);
            capturas[sitio].ocupado = 1;
            // printf("Se ha puesto como ocupado la posicion %d, su valor es %d\n", sitio, capturas[sitio].ocupado);

            printf("Introduzca la senial (emision interestelar):\n");

            fflush(stdin);

            fgets(senial.senial,MAX_SENIAL,stdin);

            strcpy(capturas[sitio].captura.senial.senial,senial.senial);

            printf("Introduzca la fecha con formato dd-mm-aa:\n");

            fflush(stdin);

            fgets(fecha.fecha,MAX_FECHA,stdin);

            strcpy(capturas[sitio].captura.fecha.fecha,fecha.fecha);

            // printf("La senial de la captura en el sitio %d es %s , su fecha es:'%s'",sitio,  capturas[sitio].captura.senial.senial, capturas[sitio].captura.fecha.fecha);

        }else{
            printf("Lo sentimos no hay sitio para mas capturas\n");
        }
    }
}


int haySitioEnCapturas (const tSeti capturas, int *sitio){

    int i;
    int posicion=0;
    for(i=0;i<MAX_CAPTURAS;i++){
        if(capturas[i].ocupado == 0){
            *sitio = i;
            posicion++;
        }
    }
    if (posicion >=1){
        return 1;
    }else{
        return 0;
    }
}


int existeCaptura(const tSeti capturas, const tNombre nom, int *pos){

   // printf("Existe captura\n");
    int i;
    int existe=0;
    // printf("Existe captura2\n");
    // printf("el nombre dentro de existe captura es: %s\n",nom.nombre);
    // printf("Existe captura3\n");

   // printf("%s\n",capturas[1].captura.nombre.nombre);

    for(i=0;i<MAX_CAPTURAS;i++){

        if(strcmp(capturas[i].captura.nombre.nombre,nom.nombre)==0){
        *pos = i;
           existe = existe + 1;

        }
    }

    if(existe >=1){
        return 0;
    }else{
        return 1;
    }

}


void inicializarCapturas(tSeti capturas){

    int i;
    for(i=0;i<MAX_CAPTURAS;i++){
        capturas[i].ocupado = 0;
        strcpy(capturas[i].captura.nombre.nombre,"");
        strcpy(capturas[i].captura.fecha.fecha,"");
        strcpy(capturas[i].captura.senial.senial,"");
    }

    FILE *leer;
    char str[1000];
    leer = fopen("C:/Users/Alvaroo/Desktop/Fase 2/Fase2/datosRegistrados.txt","r");
    int c =4;
    printf("tutillo1");
    for(c=4;c>=0;c--){
        if(fgets(str,1000,leer)!=NULL){
            strcpy(capturas[c].captura.nombre.nombre,str);
        }
        if(fgets(str,1000,leer)!=NULL){
            strcpy(capturas[c].captura.fecha.fecha,str);
        }
        if(fgets(str,1000,leer)!=NULL){
            strcpy(capturas[c].captura.senial.senial,str);
        }
    }
}
