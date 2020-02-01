/*############################################
* # Name: Jonathan Gorotiza Cornejo          #
* # Course: Operating System                 #
* # Date: 3 dec 2019                         #
* # This is a  twc code, a command to count  # 
* # words or lines from a file or various    # 
* # files at the same time                   # 
* ############################################
*/

/*
* Importaciones de lirerias a usar
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/*
* Declaracion de las funciones con las que
* se inicializara a los hilos
* esto puede ser para contar palabras
* o para contar lines de un archivo
*/
void *contarPalabras (void *);
void *contarLineas (void *);

/*
*Funcion princial del programa
*/
int main(int argc, char* argv[]){
	//Declaracion de los hilos a usar
	//en este caso se usara un hilo para cada archivo
	
	pthread_t hilos[argc -2]; 
	//Contador para inicializar los hilos
	int count = 0;
	//variable para hacer esperar al programa hasta
	//que presente los resultados
	int waitting = 10000 * (10^(argc));
	
	//Si el usaurio  ingresa la bandeta -w 
	//contara palabras y entrara en este caso
	if (strcmp(argv[1], "-w") == 0){
		//se recorre desde el arguento 2 debido a que
		// desde aqui se encontraran los nombres de 
		// los archivos a ser leidos
		for (int i = 2 ; i < argc; i ++){
		    //Se crea un hlo para cada archivo con su respectiva funcion
		    pthread_create (&hilos[count], NULL, contarPalabras, argv[i]);
		    count ++;
		}
	}
	
	// En caso que el usaurio ingrese la bandera -l
	//entrara en este caso
	if(strcmp(argv[1], "-l") == 0){
		for (int i = 2 ; i < argc; i ++){
		    pthread_create (&hilos[count], NULL, contarLineas, argv[i]);
		    count ++;
		}
	}else{
		printf("Solo se permiten banderas -w o -l\n");
	}
	//Bloque para hacer esperar al programa
	while(count < waitting){
		count ++;

	}
	return 0;
}



char * transformar(char * tamano){
	printf("HOLAA%s\n", tamano);
	if (strstr(tamano, "G"))
	{
		printf("GB\n");
	}else if (strstr(tamano, "K"))
	{
		printf("KB\n");
	}else if (strstr(tamano, "M"))
	{
		printf("MB\n");
	}
}


/*
* Implementacion de la funcion de contar lineas que recibe
* un nombre de archivo como argumento
*/
void *contarLineas (void *fileName){
	//Declaracion de variables
	FILE *archivo; //variable para el archivo
    int  lineas = 0; //contador de lienas iniciado en 0
	char caracter; //caracter que recorrera el archivo
	char linea[1000];
	char *logicalAddresSpace;
	char *physicalAddresSpace;
	char *pageSize;
	char *processSize;
	char *processName;
	char *algorithm;
	char *pageFrames;
	char linea_2[1024];
    FILE *fich;
 
    fich = fopen((char *)fileName, "r");
    //Lee línea a línea y escribe en pantalla hasta el fin de fichero

    while(fgets(linea_2, 1024, (FILE*) fich)) {
    	int n = strlen(linea);
    	linea[n] = '\0';
        //printf("LINEA: %s FIN_DE_LINEA\n", linea_2);
        lineas++;
        if (lineas == 2){
	    	printf("ENTRO AQUI\n");
	    	char *token = strtok(linea_2, "=");
		    if(token != NULL){
		    	int contador = 0;
		        while(token != NULL){
		        	if (contador == 1){
		        		if (lineas == 2)
		        		{
		        			logicalAddresSpace = token;	
		        		}
		        		
		        		
		        	}
		        	contador ++;
		        	token = strtok(NULL, "=");
		        }
			}
			printf("LAS %s\n",logicalAddresSpace );
	    }else if (lineas == 3){
	    	char *token = strtok(linea_2, "=");
		    if(token != NULL){
		    	int contador = 0;
		        while(token != NULL){
		        	if (contador == 1){
		        		
		        		physicalAddresSpace = token;
		        	}
		        	contador ++;
		        	token = strtok(NULL, "=");
		        }
			}
			printf("PAS %s\n",physicalAddresSpace );
	    }else if (lineas == 4){
	    	char *token = strtok(linea_2, "=");
		    if(token != NULL){
		    	int contador = 0;
		        while(token != NULL){
		        	if (contador == 1){
		        		
		        		pageSize = token;
		        	}
		        	contador ++;
		        	token = strtok(NULL, "=");
		        }
			}
			printf("PAGE SIZE %s\n",pageSize );
	    }else if (lineas == 6){
	    	char *token = strtok(linea_2, "=");
		    if(token != NULL){
		    	int contador = 0;
		        while(token != NULL){
		        	if (contador == 1){
		        		
		        		processName = token;
		        	}
		        	contador ++;
		        	token = strtok(NULL, "=");
		        }
			}
			printf("PROCESS NAME %s\n",processName );
	    }else if (lineas == 7){
	    	char *token = strtok(linea_2, "=");
		    if(token != NULL){
		    	int contador = 0;
		        while(token != NULL){
		        	if (contador == 1){
		        		
		        		processSize = token;
		        	}
		        	contador ++;
		        	token = strtok(NULL, "=");
		        }
			}
			printf("PROCESS SIZE %s\n",processSize );
	    }else if (lineas == 9){
	    	char *token = strtok(linea_2, "=");
		    if(token != NULL){
		    	int contador = 0;
		        while(token != NULL){
		        	if (contador == 1){
		        		
		        		algorithm = token;
		        	}
		        	contador ++;
		        	token = strtok(NULL, "=");
		        }
			}
			printf("ALGORITMO %s\n",algorithm );
	    }else if (lineas == 10){
	    	char *token = strtok(linea_2, "=");
		    if(token != NULL){
		    	int contador = 0;
		        while(token != NULL){
		        	if (contador == 1){
		        		
		        		pageFrames = token;
		        	}
		        	contador ++;
		        	token = strtok(NULL, "=");
		        }
			}
			printf("FRAMES %s\n",pageFrames );
	    }
	    printf("itera LAS %s\n",physicalAddresSpace );
			    
    }
    fclose(fich);
/*
	//apertura del archivo en modo lectura
	archivo = fopen((char *)fileName,"r");

	// Si no se abre el archivo
	if (archivo == NULL){
	    printf("\nError al abrir el archivo. \n\n");
	    exit(0);
	}else{
		// Si el archivo abre correctamente se lee
		// caracter por caracter hasta lleagr
		// al final del archivo
		int i = 0;
	    while((caracter = fgetc(archivo)) != EOF){
	    	//cada que encuentra un \n cuenta una linea
	    	linea[i] = caracter;
	    	i++;
			if(caracter == '\n'){

				i--;
				linea[i] = '\0';
			    lineas++;
			    printf("%d\n",lineas );
			    if (lineas == 2){
			    	printf("ENTRO AQUI\n");
			    	char *token = strtok(linea, "=");
				    if(token != NULL){
				    	int contador = 0;
				        while(token != NULL){
				        	if (contador == 1){
				        		
				        		logicalAddresSpace = token;
				        	}
				        	contador ++;
				        	token = strtok(NULL, "=");
				        }
    				}
    				printf("LAS %s\n",logicalAddresSpace );
    				linea[0] = '\0';
			    }else if (lineas == 3){
			    	char *token = strtok(linea, "=");
				    if(token != NULL){
				    	int contador = 0;
				        while(token != NULL){
				        	if (contador == 1){
				        		
				        		physicalAddresSpace = token;
				        	}
				        	contador ++;
				        	token = strtok(NULL, "=");
				        }
    				}
    				printf("PAS %s\n",physicalAddresSpace );
    				linea[0] = '\0';
			    }else if (lineas == 4){
			    	char *token = strtok(linea, "=");
				    if(token != NULL){
				    	int contador = 0;
				        while(token != NULL){
				        	if (contador == 1){
				        		
				        		pageSize = token;
				        	}
				        	contador ++;
				        	token = strtok(NULL, "=");
				        }
    				}
    				printf("PAGE SIZE %s\n",pageSize );
    				linea[0] = '\0';
			    }else if (lineas == 6){
			    	char *token = strtok(linea, "=");
				    if(token != NULL){
				    	int contador = 0;
				        while(token != NULL){
				        	if (contador == 1){
				        		
				        		processName = token;
				        	}
				        	contador ++;
				        	token = strtok(NULL, "=");
				        }
    				}
    				printf("PROCESS NAME %s\n",processName );
    				linea[0] = '\0';
			    }else if (lineas == 7){
			    	char *token = strtok(linea, "=");
				    if(token != NULL){
				    	int contador = 0;
				        while(token != NULL){
				        	if (contador == 1){
				        		
				        		processSize = token;
				        	}
				        	contador ++;
				        	token = strtok(NULL, "=");
				        }
    				}
    				printf("PROCESS SIZE %s\n",processSize );
    				linea[0] = '\0';
			    }else if (lineas == 9){
			    	char *token = strtok(linea, "=");
				    if(token != NULL){
				    	int contador = 0;
				        while(token != NULL){
				        	if (contador == 1){
				        		
				        		algorithm = token;
				        	}
				        	contador ++;
				        	token = strtok(NULL, "=");
				        }
    				}
    				printf("ALGORITMO %s\n",algorithm );
    				linea[0] = '\0';
			    }else if (lineas == 10){
			    	char *token = strtok(linea, "=");
				    if(token != NULL){
				    	int contador = 0;
				        while(token != NULL){
				        	if (contador == 1){
				        		
				        		pageFrames = token;
				        	}
				        	contador ++;
				        	token = strtok(NULL, "=");
				        }
    				}
    				printf("FRAMES %s\n",pageFrames );
    				linea[0] = '\0';
			    }
			    
			    i=0;
			    char linea[1000];
			}
			//printf("LAS %s\n",logicalAddresSpace );
	    }
	    printf("PAS %s\n", processName);

	    printf("%s\n", transformar(logicalAddresSpace));
	    printf("%s\n", transformar(physicalAddresSpace));
	}*/
	printf("PAS %s\n", logicalAddresSpace);
	printf("LAS %s\n", physicalAddresSpace);

    printf("%s\n", transformar(logicalAddresSpace));
    printf("%s\n", transformar(physicalAddresSpace));
	//preentacion de resultados
	printf("El archivo %s tiene %d lineas \n",(char *)fileName, lineas);
	fclose(archivo); // cierre del archivo
}

/*
* Implementacion de la funcion de contar palabras que recibe
* un nombre de archivo como argumento
*/
void *contarPalabras (void *fileName){
	//Declaracion de variables
	FILE *archivo;  //variable para el archivo
	char c;  // el caracter que recorrera el archivo
    int  palabras = 0; //contador de palabras iniciado en 0

    //apertura del archivo en modo lectura
	archivo = fopen((char *)fileName,"r"); 

	// Si no se abre el archivo
	if (archivo == NULL){
	    printf("\nError de apertura del archivo. \n\n");
	    exit(0);
	}
	else{
		// Si el archivo abre correctamente se lee
		// caracter por caracter hasta lleagr
		// al final del archivo
		while ((c = getc(archivo)) != EOF){
		    if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
			palabras++;
		}
	}
	//preentacion de resultados
	printf("El archivo %s tiene %d palabras \n",(char *)fileName, palabras);
	fclose(archivo); // cierre del archivo
}

