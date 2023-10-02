#include "cola.h"

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;

} nodo_t;

struct _cola_t {

	nodo_t *principio;
	nodo_t *final;
	size_t tamanio;

};



cola_t *cola_crear()
{
	cola_t *cola = malloc(sizeof(cola_t));
	if(cola == NULL){
		return NULL;
	}

	cola->final = NULL;
	cola->principio = NULL;
	cola->tamanio = 0;

	return cola;
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	
	if(cola == NULL){
		return NULL;
	}

	nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));

	if(nodo == NULL){
		return NULL;
	}
	nodo->elemento = elemento;
	nodo->siguiente = NULL;


	if(cola->principio == NULL){

		cola->principio = nodo;	
		cola->final = nodo;
		cola->tamanio = 1;
		return cola;
	}

	cola->final->siguiente = nodo;
	cola->final = nodo;	
	cola->tamanio = cola->tamanio + 1;

	return cola;


}

void *cola_desencolar(cola_t *cola)
{	
	if(cola == NULL || cola->principio == NULL){
		return NULL;
	}
	
	nodo_t *auxPrincipio = cola->principio;

	cola->principio = cola->principio->siguiente;
	void *elemento = auxPrincipio->elemento;

	free(auxPrincipio);

	return elemento;
}

void *cola_frente(cola_t *cola)
{	
	if(cola == NULL){
		return NULL;
	}
	return cola->principio->elemento;
}

size_t cola_tamanio(cola_t *cola)
{	
	if(cola == NULL){
		return 0;
	}
	return cola->tamanio;
}

bool cola_vacia(cola_t *cola)
{	
	if(cola == NULL){

		return true;
	}
	return cola->tamanio == 0;
}

void cola_destruir(cola_t *cola)
{
	if(cola == NULL){
		return;
	}

	while (!cola_vacia(cola)) {
		cola_desencolar(cola);
	}
	free(cola);



}
