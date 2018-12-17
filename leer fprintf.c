

                FILE *reportes;
                //printf("Creamos variable reportes\n");
                char* direccion= "C:/Users/Alvaroo/Desktop/Fase 2/Fase2/reportes.txt";
                //printf("Creamos variable char\n");
                reportes = fopen(direccion,"w");
                //printf("abrimos direccion\n");
                
                fputs("Captura prometedora.... :\n",reportes);
                fputs("\n*********\n",reportes);
                fprintf(reportes,"%s\n----------\n",capturas[i].captura.nombre.nombre);
                fprintf(reportes,"%s----------\n",capturas[i].captura.fecha.fecha);
                fprintf(reportes,"%s\n",capturas[i].captura.senial.senial);

                //printf("Escribimos en el archivo");
                fclose(reportes);
                //printf("Cerramos");
