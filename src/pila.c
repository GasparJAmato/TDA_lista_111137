#include "pila.h"
#include "lista.h"

pila_t *pila_crear()
{
	return lista_crear();
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	return lista_insertar(pila, elemento);
}

void *pila_desapilar(pila_t *pila)
{
	return lista_quitar(pila);
}

void *pila_tope(pila_t *pila)
{
	return lista_ultimo(pila);
}

size_t pila_tamanio(pila_t *pila)
{
	return lista_tamanio(pila);
}

bool pila_vacia(pila_t *pila)
{
	return lista_vacia(pila);
}

void pila_destruir(pila_t *pila)
{
	lista_destruir(pila);
}