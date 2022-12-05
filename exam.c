/*Tercera evaluacion parcial
*Miguel Alejandre 
3-D
Universidad de colima
Ingenieria de Software
Estructura de datos
*/


#include<stdio.h>
#include<stdlib.h>

int busquedaEnArbol(int raiz, int busqueda);

struct nodo{
	int dato;
	struct nodo* hijo_izq;
	struct nodo* hijo_der;
};

struct nodo* nuevoNodo(int dato){
	//solicitar memoria
	size_t tam_nodo = sizeof(struct nodo);

	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);	
	//asignar el dato e iniciar hojas
	nuevo_nodo -> dato = dato;
	nuevo_nodo -> hijo_izq = NULL;
	nuevo_nodo -> hijo_der = NULL;

	return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
	// Izquierda o derecha
	//si es mayor va a la derecha
	if (dato> nd -> dato){
		if (nd->hijo_der==NULL){
			nd->hijo_der =nuevoNodo(dato);
		}else{
			//si la derecha ya esta ocupada, recursividad
			insertarNodo(nd -> hijo_der, dato);
		}
	}else{
		// Si no,a la izquierda
		if(nd->hijo_izq==NULL){
		   nd->hijo_izq=nuevoNodo(dato);
		}else{
			//Si la izquierda ya esta ocupada, recursividad
			insertarNodo(nd -> hijo_izq, dato);
		}
	}
}

//recorrido
void inorden(struct nodo *nd) {
    if (nd != NULL) {
        inorden(nd->hijo_izq);
        printf("%d,", nd->dato);
        inorden(nd->hijo_der);
    }
}
/**---------------------------
void imprimirNodo(struct nodo* nd){
	printf("%d", nd);
}***/

int main(){

	struct nodo *raiz=NULL;
	
	raiz = nuevoNodo(8);
	insertarNodo(raiz,3);
	insertarNodo(raiz,20);
	insertarNodo(raiz,10);
	insertarNodo(raiz, 5);
	insertarNodo(raiz,1);
	insertarNodo(raiz,4);
/*...........................*/
   printf("\n Imprimiendo inorden\n");
   inorden(raiz);
/********************/
 	//declaramos el numero a buscar
	int busqueda;
	printf("Ingrese el numero a buscar; ");
	scanf("%d",&busqueda);

    int existe = busquedaEnArbol(raiz, busqueda);

    printf("\nSaliendo...\n");

	printf("Posicion de %d en el arbol: %d", busqueda, existe);
    return 1;
}

int busquedaEnArbol(int raiz, int busqueda){
	for (int x = 0; x<9, x++) {
		if(raiz[x] == busqueda){
			return x;
		} else{
			printf("No existe\n");
		}
	}
	return -1;
}