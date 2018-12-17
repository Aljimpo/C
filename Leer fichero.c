#include <stdio.h>

void main() {
    FILE *fp;

    char str[1000];

    char* filename = "C:/Users/Alvaroo/Desktop/Fase 2/Fase2/fichero1.txt";

    fp = fopen(filename, "r");

    while(fgets(str,1000,fp)!=NULL)
    printf("%s",str);

    fclose(fp);
}
