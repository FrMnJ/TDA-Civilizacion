#ifndef PILADEGUERREROS_H_INCLUDED
#define PILADEGUERREROS_H_INCLUDED

#include "Nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Guerrero.h"

typedef struct pila{
    NodoGuerrero* raiz;
    size_t cantidad;
}PilaGuerreros;


bool Pila_vacia(PilaGuerreros* pila){
    if(pila==NULL){
        puts("Pila no tiene memoria");
        exit(1);
    }
    return pila->cantidad==0;
}

PilaGuerreros* Pila_init(){
    PilaGuerreros* aux=(PilaGuerreros*)malloc(sizeof(PilaGuerreros));
    if(aux==NULL){
        puts("No se pudo reservar memoria para lista");
        return aux;
    }
    aux->raiz=NULL;
    aux->cantidad=0;
    return aux;
}

bool Pila_push(PilaGuerreros* pila ,Guerrero *dato){
    bool suc=false;
    if(pila==NULL){
        puts("Pila no tiene memoria");
        return suc;
    }
    NodoGuerrero* nuevo=NodoGuerrero_init(dato);
    if(nuevo==NULL){
        puts("No se pudo hacer push");
        return suc;
    }
    nuevo->siguiente=pila->raiz;
    pila->raiz=nuevo;
    pila->cantidad++;
    suc=true;
    return suc;
}

bool Pila_pop(PilaGuerreros* pila){
    if(pila==NULL){
        puts("Pila no tiene memoria");
        return false;
    }
    if(Pila_vacia(pila)){
        puts("No se puede eliminar en pila vacia");
        return false;
    }
    NodoGuerrero *temp=pila->raiz;
    pila->raiz=pila->raiz->siguiente;
    Guerrero_free(temp);
    pila->cantidad--;
    return true;
}


bool Pila_free(PilaGuerreros* pila){
    while(!Pila_vacia(pila)){
       Pila_pop(pila);
    }
    free(pila);
    return true;
}

Guerrero *Pila_top(PilaGuerreros *pila){
    if(pila==NULL){
        puts("Error tratando top en pila vacia");
    }
    return pila->raiz->guerrero;
}

bool Pila_volcar(PilaGuerreros* pila){
    if(pila==NULL){
        puts("Pila no tiene memoria");
        return false;
    }
    printf("Cantidad: %i\n",pila->cantidad);
    while(!Pila_vacia(pila)){
        Guerrero_mostrar(Pila_top(pila));
        Pila_pop(pila);

    }
    return true;
}






#endif // PILADEGUERREROS_H_INCLUDED
