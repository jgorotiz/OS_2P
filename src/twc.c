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
#include <math.h>

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

int obtenerExponente(int numero){
	int total = 0, base = 2, exponente = 0;
	while(total != numero){

		total = pow (base,exponente);
		exponente ++;
	}

	return exponente-1;

}


int transformar(char * tamano){
	if (strstr(tamano, "G")){
		char *token = strtok(tamano, "G");
		int numero = atoi(token);
		int exponente = obtenerExponente(numero);

		return 30+exponente;
	}else if (strstr(tamano, "K")){
		char *token = strtok(tamano, "K");
		int numero = atoi(token);
		int exponente = obtenerExponente(numero);

		return 10+exponente;
	}else if (strstr(tamano, "M")){
		char *token = strtok(tamano, "M");
		int numero = atoi(token);
		int exponente = obtenerExponente(numero);

		return 20+exponente;
	}
	char *token = strtok(tamano, "M");
	int numero = atoi(token);
	int exponente = obtenerExponente(numero);

	return exponente;
	
}

char * obtenerCaracter(char * string){
	char* otherString = 0;
	otherString = (char*)malloc(1+1);
	memcpy(otherString,string,1);
	return otherString;
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
	char *processMenRef;
	char *pageFrames;
	char linea_2[1024];
	char procesos[100];
    FILE *fich;
 
    fich = fopen((char *)fileName, "r");
    //Lee línea a línea y escribe en pantalla hasta el fin de fichero
    char *save_ptr=NULL;
    while(fgets(linea_2, 1024, (FILE*) fich)) {
    	int n = strlen(linea);
    	linea[n] = '\0';
        //printf("LINEA: %s FIN_DE_LINEA\n", linea_2);
        lineas++;
    	
    	char *token = strtok_r(linea_2, "=", &save_ptr);
    	char *token_2 = strtok_r(NULL, "=", &save_ptr);
    	printf("TOKEN:  %s\n",token_2 );
	    if(token_2 != NULL){
    		if (lineas == 2){
    			logicalAddresSpace = (char *) calloc(strlen(token_2), sizeof(char *));
    			strcpy(logicalAddresSpace , token_2);
    		}else if(lineas == 3){
    			physicalAddresSpace = (char *) calloc(strlen(token_2), sizeof(char *));
    			strcpy(physicalAddresSpace , token_2);
    		}else if(lineas == 4){
    			pageSize = (char *) calloc(strlen(token_2), sizeof(char *));
    			strcpy(pageSize , token_2);
    		}else if(lineas == 6){
    			processName = (char *) calloc(strlen(token_2), sizeof(char *));
    			strcpy(processName , token_2);
    		}else if(lineas == 7){
    			processSize = (char *) calloc(strlen(token_2), sizeof(char *));
    			strcpy(processSize , token_2);
    		}else if(lineas == 8){
    			processMenRef = (char *) calloc(strlen(token_2), sizeof(char *));
    			strcpy(processMenRef , token_2);
    		}else if(lineas == 9){
    			algorithm = (char *) calloc(strlen(token_2), sizeof(char *));
    			strcpy(algorithm , token_2);
    		}else if(lineas == 10){
    			pageFrames = (char *) calloc(strlen(token_2), sizeof(char *));
    			strcpy(pageFrames , token_2);
    		}
        	
		}
		//printf("LAS %s\n",logicalAddresSpace );
    
	    
			    
    }
    fclose(fich);
    int contador = 0;
    char *token_3 = strtok_r(processMenRef, ",", &save_ptr);
    if(token_3 != NULL){
    	
        while(token_3 != NULL){
        	printf("TOKEN; %s\n", token_3);
        	printf("%s\n", obtenerCaracter(token_3));
        	procesos[contador] = obtenerCaracter(token_3);
        	token_3 = strtok_r(NULL, ",", &save_ptr);
        	contador++;
        }
	}
	procesos[contador] = '\0';
	printf("%s\n", procesos);
    

    int bits_offset = transformar(pageSize);
    int bits_LAS = transformar(logicalAddresSpace);
    int bits_PAS = transformar(physicalAddresSpace);
	printf("Logical Address Structure: page bits (%d) and offset bits (%d) \n", (bits_LAS - bits_offset) , bits_offset);
	printf("Physical Address Structure: frame bits (%d) and offset bits (%d) \n ", (bits_PAS - bits_offset) , bits_offset);
	//preentacion de resultados
	//printf("El archivo %s tiene %d lineas \n",(char *)fileName, lineas);
	//fclose(archivo); // cierre del archivo
	free(logicalAddresSpace);
	free(physicalAddresSpace);
	free(pageSize);
	free(processSize);
	free(algorithm);
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

