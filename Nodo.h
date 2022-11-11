    #ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Civilizacion.h"

typedef struct nodo{
    Civilizacion *dato;
    struct nodo* siguiente;
    struct nodo* anterior;
}Nodo;

Nodo* Nodo_init(Civilizacion* dato){
    Nodo* aux=(Nodo*)malloc(sizeof(Nodo));
    if(aux==NULL){
        puts("No se pudo reservar memoria para nodo");
        exit(1);
    }
    aux->dato=dato;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    return aux;
}



#endif // NODO_H_INCLUDED
