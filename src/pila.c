#include "pila.h"

typedef struct nodo {
	void *elemento;
	struct nodo *anterior;

} nodo_t;

struct _pila_t {

	nodo_t *tope;
	size_t tamanio;

};

pila_t *pila_crear()
{
	pila_t *pila = malloc(sizeof(pila_t));

	if(pila == NULL){
		return NULL;
	}

	pila->tope = NULL;
	pila->tamanio = 0;

	return pila;
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	if(pila == NULL){
		return NULL;
	}

	nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));

	if(nodo == NULL){
		return NULL;
	}

	if(pila->tamanio == 0){
		nodo->elemento = elemento;
		nodo->anterior = NULL;
		pila->tamanio = 1;

		return pila;
	}

	nodo->elemento = elemento; 
	nodo->anterior = pila->tope;
	
	pila->tamanio = pila->tamanio + 1;
	pila->tope = nodo;


	return pila;
}

void *pila_desapilar(pila_t *pila)
{
	if(pila == NULL || pila->tope == NULL){
		return NULL;
	}
	nodo_t *auxTope = pila->tope;

	pila->tope = pila->tope->anterior;
	void *elemento = auxTope->elemento;

	free(auxTope);

	return elemento;



}

void *pila_tope(pila_t *pila)
{
	if(pila == NULL){
		return NULL;
	}
	return pila->tope->elemento;
}

size_t pila_tamanio(pila_t *pila)
{	
	if(pila == NULL){
		return 0;
	}
	return pila->tamanio;
}

bool pila_vacia(pila_t *pila)
{	
	if(pila == NULL){
		return true;
	}
	return pila->tamanio == 0;
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
