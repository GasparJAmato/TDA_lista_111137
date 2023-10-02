#include "pila.h"
#include <stdbool.h>
#include <stddef.h>



typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;

} nodo_t;

struct _pila_t{
	
	nodo_t *nodo_inicio;
	nodo_t *nodo_final;
	size_t tamanio;
};

pila_t *pila_crear()
{
	pila_t *pila = malloc(sizeof(pila_t));

	if(pila == NULL){

		
		return NULL;
		
	}

	pila->nodo_inicio = NULL;
	
	return pila;;
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	if(pila == NULL ){
		return NULL;
	}

	nodo_t *NuevoNodo = (nodo_t *)malloc(sizeof(nodo_t));

	if(NuevoNodo == NULL){
		
		return NULL;
	}

	NuevoNodo->elemento = elemento;
	NuevoNodo->siguiente = NULL;


        NuevoNodo->siguiente = pila->nodo_inicio;
        pila->nodo_inicio = NuevoNodo;
        return pila;
 
}

void *pila_desapilar(pila_t *pila)
{
		if(pila == NULL || pila->nodo_inicio == NULL){
		
		return NULL;
	}

	nodo_t *nodoActual = pila->nodo_inicio;
	nodo_t *anterior = NULL;

	if (pila->nodo_inicio->siguiente == NULL) {
		
	    void *elemento = pila->nodo_inicio->elemento;
    	free(pila->nodo_inicio);
    	pila->nodo_inicio = NULL;
    	return elemento;	
	}

	while(nodoActual->siguiente != NULL){
		anterior = nodoActual;
		nodoActual = nodoActual->siguiente;
	}

	void *elemento = nodoActual->elemento;

	free(nodoActual);
	
    
    anterior->siguiente = NULL;
 
    


	return elemento;
}

void *pila_tope(pila_t *pila)
{
	if(pila == NULL || pila->nodo_inicio == NULL){
		return NULL;
	}

	nodo_t *nodoActual = pila->nodo_inicio;

    while (nodoActual->siguiente != NULL) {
        nodoActual = nodoActual->siguiente;
    }
	return nodoActual->elemento;
}

size_t pila_tamanio(pila_t *pila)
{
	
	if(pila == NULL){
		return 0;
	}

	nodo_t *nodoActual = pila->nodo_inicio;
	size_t tamanio = 0;

	while(nodoActual != NULL){
		tamanio++;
		nodoActual = nodoActual->siguiente;
	}
	return tamanio;
}

bool pila_vacia(pila_t *pila)
{
	if(pila == NULL || pila->nodo_inicio == NULL){
		return true;
	}else{
		return false;
	}
}

void pila_destruir(pila_t *pila)
{
	if(pila == NULL){
		return;
	}

	while (!pila_vacia(pila)) {
		pila_desapilar(pila);
	}
	free(pila);
}