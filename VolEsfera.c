/*Ejercicio: Diseñar e implementar un programa que lea el radio de una esfera y
escriba por la salida estándar su área y su volumen. Para ello, debe definir y
utilizar dos funciones con la siguiente declaración:*/

double esferaArea(float radio);
double esferaVolumen(float radio);

void main(){
printf("Introduzca el radio de la esfera: ");
float radio;
scanf("%f",&radio);
double area,volumen;

printf("El area de la esfera es: %f\n",esferaArea(radio));
printf("El Volumen de la esfera es: %f",esferaVolumen(radio));

}

double esferaArea(float radio){
    double area;
    area = 4*3.1415926*radio*radio;
    return area;
}

double esferaVolumen(float radio){
    double volumen;
    volumen = (radio*radio*radio*3.141592*4)/3;
    return volumen;
}
