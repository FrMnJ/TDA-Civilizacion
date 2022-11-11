#ifndef PUERTO_H_INCLUDED
#define PUERTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Barco.h"

typedef struct puerto{
    NodoBarco* inicio;
    NodoBarco* final;
    size_t cantidad;
}Puerto;


bool vacia_Puerto(Puerto* puerto){
    if(puerto==NULL){
        puts("Puerto no tiene memoria");
        exit(1);
    }
    return puerto->cantidad==0;
}

Puerto* Puerto_init(){
    Puerto* nuevoPuerto=(Puerto*)malloc(sizeof(Puerto));
    if(nuevoPuerto==NULL){
        puts("No se pudo reservar memoria para puerto");
        return nuevoPuerto;
    }
    nuevoPuerto->inicio=NULL;
    nuevoPuerto->final=NULL;
    nuevoPuerto->cantidad=0;
    return nuevoPuerto;
}

bool eliminar_final_Puerto(Puerto *puerto){
    if(puerto==NULL){
        puts("Puerto no tiene memoria");
        return false;
    }
    if(vacia_Puerto(puerto)){
        puts("No se puede eliminar en Puerto vacio");
        return false;
    }
    NodoBarco *temp=puerto->final;
    if(temp->anterior!=NULL){
        temp->anterior->siguiente=temp->siguiente;
        puerto->final=temp->anterior;
    }
    puerto->cantidad--;
    if(vacia_Puerto(puerto)){
        puerto->inicio=NULL;
        puerto->final=NULL;
    }
    NodoBarco_free(temp);
    return true;
}


bool Insertar_al_principio_Puerto(Puerto* puerto ,Barco *dato){
    bool suc=false;
    if(puerto==NULL){
        puts("Puerto no tiene memoria");
        return suc;
    }
    NodoBarco* nuevo=NodoBarco_init(dato);
    if(nuevo==NULL){
        puts("No se pudo insertar al inicio");
        return suc;
    }
    if(vacia_Puerto(puerto)){
        puerto->inicio=nuevo;
        puerto->final=nuevo;
        puerto->cantidad++;
    }
    else{
        nuevo->siguiente=puerto->inicio;
        puerto->inicio->anterior=nuevo;
        puerto->inicio=nuevo;
        puerto->cantidad++;
    }
    suc=true;
    return suc;
}

bool eliminar_inicio_Puerto(Puerto* puerto){
    if(puerto==NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }
    if(vacia_Puerto(puerto)){
        puts("No se puede eliminar en lista vacia");
        return false;
    }
    NodoBarco* temp=puerto->inicio;
    puerto->inicio=temp->siguiente;
    puerto->cantidad--;
    if(vacia_Puerto(puerto)){
        puerto->final=NULL;
    }
    else{
        puerto->inicio->anterior=NULL;
    }
    NodoBarco_free(temp->barco);
    free(temp);
    return true;
}

bool Insertar_al_final_Puerto(Puerto* puerto ,Barco *dato){
    if(puerto==NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }
    if(vacia_Puerto(puerto)){
        return Insertar_al_principio_Puerto(puerto,dato);
    }
    NodoBarco* nuevo=NodoBarco_init(dato);
    nuevo->anterior=puerto->final;
    puerto->final->siguiente=nuevo;
    puerto->final=nuevo;
    puerto->cantidad++;
    return true;
}

bool free_Barco(Puerto* puerto){
    while(puerto->inicio!=NULL){
        eliminar_final_Puerto(puerto);
    }
    free(puerto);
    return true;
}

bool mostrar_Puerto(Puerto* puerto){
    if(puerto==NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }
    NodoBarco *temp=puerto->inicio;
    printf("Cantidad: %i\n",puerto->cantidad);
    while(temp!=NULL){
        Barco_mostrar(temp->barco);
        temp=temp->siguiente;
    }
    return true;
}


Barco *Puerto_buscar(Puerto* puerto, size_t id){
    if(puerto==NULL){
        puts("Civilizaciones no tiene memoria");
        return NULL;
    }
    NodoBarco *temp=puerto->inicio;
    while(temp!=NULL){
        if(id==temp->barco->id){
            return temp->barco;
        }
        temp=temp->siguiente;
    }
    return NULL;
}

#endif // PUERTO_H_INCLUDED
