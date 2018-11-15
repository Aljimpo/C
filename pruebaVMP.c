void pesosMes(double* pesomes){
scanf("%lf" "%lf" "%lf" "%lf",&pesomes[0],&pesomes[1],&pesomes[2],&pesomes[3]);
void pesosMes(double pesomes[]){
int i;
for(i=0;i<VECES_PESO;i++){
    printf("Introduzca el peso de la semana %i: ",i);
    scanf("%lf",&pesomes[i]);
}

}

void main (void){
    double pesomes[VECES_PESO];
    double pesomax,pesomin;
    pesosMes(pesomes);
    pesoMinMax(pesomes);
}
    pesoMinMax(pesomes,&pesomin,&pesomax);

void pesoMinMax (double *pesomes, double *peso_minn, double *peso_maxx){

    double pesomin;
    double pesomax;

    peso_minn = &pesomes[0];
    peso_maxx = &pesomes[0];
    printf("Peso maximo %f y minimo %f \n",pesomax,pesomin);
    printf("Peso primera semana %f y peso ultima semana %f\n",pesomes[0],pesomes[3]);
    printf("La diferencia de peso entre la primera y la ultima semana es: %f kilogramos",pesomes[0]-pesomes[3]);
}

    pesomin = *peso_minn;
    pesomax = *peso_maxx;
void pesoMinMax (double pesomes[], double *pesomin, double *pesomax){

     *pesomin = *pesomes;
     *pesomax = *pesomes;

    int i;
    for(i=0;i<sizeof(pesomes);i++){
        if (pesomes[i] < pesomin){
            pesomin = pesomes[i];
    for(i=0;i<VECES_PESO;i++){
        if (pesomes[i] < *pesomin){
            *pesomin = pesomes[i];
        }
        if (pesomes[i] > pesomax){
            pesomax = pesomes[i];
        if (pesomes[i] > *pesomax){
            *pesomax = pesomes[i];
        }
    }
    printf("El peso min es:%f\n",pesomin);
    printf("El peso max es:%f\n",pesomax);
}
