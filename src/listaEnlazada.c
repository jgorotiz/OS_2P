
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct ElementoLista {
	int  valor;
	struct ElementoLista *siguiente;
}Elemento;

typedef struct ListaIdentificar {
	Elemento *inicio;
	Elemento *fin;
}Lista;


int ins_fin_lista (Lista *lista, Elemento *actual, int valor);
void visualizacion (Lista * lista);


/*inserción al final de la lista */
int ins_fin_lista (Lista * lista, Elemento * actual, int valor){
	Elemento *nuevo_elemento;
	if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
		return -1;
	if ((nuevo_elemento->valor = (int) malloc (50 * sizeof (int)))== NULL)
		return -1;
	
	nuevo_elemento->valor = valor;
	lista->fin->siguiente = nuevo_elemento;
	//actual->siguiente = nuevo_elemento;
	nuevo_elemento->siguiente = NULL;

	
	lista->fin = nuevo_elemento;

	
	return 0;
}


int buscar (Lista * lista, int valor){
	Elemento *actual;
	actual = lista->inicio;
	while (actual != NULL){
		if (actual->valor == valor)
		{
			return 1;
		}
		actual = (Elemento *) actual->siguiente;
	}
	return 0;
}

int eliminar (Lista * lista, int valor){
	Elemento *actual;
	if(lista->inicio->valor == valor){
		lista->inicio = lista->inicio->siguiente;
		
		return 1;
	}
	actual = lista->inicio;
	while (actual != NULL){
		if (actual->siguiente->valor == valor)
		{
			if (actual->siguiente->siguiente == NULL)
			{
				lista->fin = actual->siguiente;
			}
			actual->siguiente->siguiente = NULL;
			actual->siguiente = actual->siguiente->siguiente;
			return 1;
		}
		actual = (Elemento *) actual->siguiente;
	}
	return 0;
}


int actualizar (Lista * lista, int valor, int nuevo_valor){
	Elemento *actual;
	//printf("EN ACTUALIZAR %d\n", lista->fin->valor);
	actual = lista->inicio;
	while (actual != NULL){
		if (actual->valor == valor)
		{
			actual->valor = nuevo_valor;
			return 2;
		}
		actual = (Elemento *) actual->siguiente;
	}
	return 0;
}
/* visualización de la lista */
void visualizacion (Lista * lista){
	Elemento *actual;
	actual = lista->inicio;
	while (actual != NULL){
		printf ("%d\t",  actual->valor);
		actual = (Elemento *) actual->siguiente;
	}
	printf("\n");
}


int ins_en_lista_vacia (Lista * lista, int valor){
	Elemento *nuevo_elemento;
	if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
		return -1;
	if ((nuevo_elemento->valor = (int) malloc (50 * sizeof (int)))== NULL)
		return -1;
	nuevo_elemento->valor = valor;

	nuevo_elemento->siguiente = NULL;
	lista->inicio = nuevo_elemento;
	lista->fin = nuevo_elemento;
	return 0;
	}



int main(int argc, char* argv[]){
	
	Lista *lista;
	lista->inicio = NULL;
	lista->fin = NULL;
	
	int a = ins_en_lista_vacia (lista, 5);
	//printf("FIN %d\n", lista->fin->valor );
	//printf("INICIO %d\n", lista->inicio->valor );
	ins_fin_lista(lista, &(lista->fin),4 );
	ins_fin_lista(lista, &(lista->fin),5 );
	ins_fin_lista(lista, &(lista->fin),1 );
	ins_fin_lista(lista, &(lista->fin),5 );
	ins_fin_lista(lista, &(lista->fin),6 );
	ins_fin_lista(lista, &(lista->fin),7 );

	int encontro = buscar(&lista, 8);
	//printf("%d\n",encontro );
	visualizacion(&lista);
	actualizar (lista, 5, 20);
	visualizacion(lista);
	ins_fin_lista(lista, (lista->fin),50 );
	visualizacion(lista);
	eliminar (lista, 7);
	visualizacion(lista);
	//printf("EN MAIN %d\n", lista->fin->valor);
	return 1;
}
