#ifndef LISTALIGADA_H_INCLUDED
#define LISTALIGADA_H_INCLUDED
#include "Nodo.h"
#include "Civilizacion.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct listaligada{
    Nodo* inicio;
    Nodo* final;
    size_t cantidad;
}ListaLigada;


bool vacia_ListaLigada(ListaLigada* lista){
    if(lista==NULL){
        puts("ListaLigada no tiene memoria");
        exit(1);
    }
    return lista->cantidad==0;
}

ListaLigada* ListaLigada_init(){
    ListaLigada* aux=(ListaLigada*)malloc(sizeof(ListaLigada));
    if(aux==NULL){
        puts("No se pudo reservar memoria para lista");
        return aux;
    }
    aux->inicio=NULL;
    aux->final=NULL;
    aux->cantidad=0;
    return aux;
}

bool Insertar_al_principio_ListaLigada(ListaLigada* lista ,Civilizacion *dato){
    bool suc=false;
    if(lista==NULL){
        puts("ListaLigada no tiene memoria");
        return suc;
    }
    Nodo* nuevo=Nodo_init(dato);
    if(nuevo==NULL){
        puts("No se pudo insertar al inicio");
        return suc;
    }
    if(vacia_ListaLigada(lista)){
        lista->inicio=nuevo;
        lista->final=nuevo;
        lista->cantidad++;
    }
    else{
        nuevo->siguiente=lista->inicio;
        lista->inicio->anterior=nuevo;
        lista->inicio=nuevo;
        lista->cantidad++;
    }
    suc=true;
    return suc;
}

bool eliminar_inicio_ListaLigada(ListaLigada* lista){
    if(lista==NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }
    if(vacia_ListaLigada(lista)){
        puts("No se puede eliminar en lista vacia");
        return false;
    }
    Nodo* temp=lista->inicio;
    lista->inicio=temp->siguiente;
    lista->cantidad--;
    if(vacia_ListaLigada(lista)){
        lista->final=NULL;
    }
    else{
        lista->inicio->anterior=NULL;
    }
    Civilizacion_free(temp->dato);
    free(temp);
    return true;
}

bool Insertar_al_final_ListaLigada(ListaLigada* lista ,Civilizacion *dato){
    if(lista==NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }
    if(vacia_ListaLigada(lista)){
        return Insertar_al_principio_ListaLigada(lista,dato);
    }
    Nodo* nuevo=Nodo_init(dato);
    nuevo->anterior=lista->final;
    lista->final->siguiente=nuevo;
    lista->final=nuevo;
    lista->cantidad++;
    return true;
}

bool Civilizaciones_respaldar(ListaLigada *civilizaciones){
    if(civilizaciones==NULL){
        puts("No hay memoria en civilizacion");
        return false;
    }
    if(civilizaciones->cantidad==0){
        puts("No hay civilizaciones");
        return false;
    }
    FILE *archivo=fopen("civilizaciones.txt","w");
    if(archivo==NULL){
        puts("No se pudo abrir archivo");
        return false;
    }
    Nodo *temp=civilizaciones->inicio;
    while(temp!=NULL){
        Civilizacion_respaldar(temp->dato,archivo);
        temp=temp->siguiente;
    }
    fclose(archivo);
    return true;
}

bool recuperar_civilizaciones(ListaLigada *civilizaciones){
    FILE *archivo=fopen("civilizaciones.txt","r");
    if(archivo==NULL){
        puts("No se pudo abrir el archivo");
    }
    while(true){
          char *nuevo=recuperar_Civilizacion(archivo);
        if(nuevo==NULL) break;
        Insertar_al_final_ListaLigada(civilizaciones,nuevo);
    }
    fclose(archivo);
    return true;
}

bool free_ListaLigada(ListaLigada* lista){
    while(lista->inicio!=NULL){
        eliminar_inicio_ListaLigada(lista);
    }
    free(lista);
    return true;
}

bool mostrar_ListaLigada(ListaLigada* lista){
    if(lista==NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }
    Nodo *temp=lista->inicio;
    printf("Cantidad: %i\n",lista->cantidad);
    while(temp!=NULL){
        Civilizacion_mostrar(temp->dato);
        temp=temp->siguiente;
    }
    return true;
}

bool eliminar_final_ListaLigada(ListaLigada* lista){
    if(lista==NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }
    if(vacia_ListaLigada(lista)){
        puts("No se puede eliminar en lista vacia");
        return false;
    }
    Nodo* temp=lista->final;
    if(temp->anterior!=NULL){
        temp->anterior->siguiente=NULL;
        lista->final=temp->anterior;
    }
    lista->cantidad--;
    if(vacia_ListaLigada(lista)){
        lista->inicio=NULL;
        lista->final=NULL;
    }

    Civilizacion_free(temp->dato);
    return true;
}

Civilizacion *Civilizaciones_buscar(ListaLigada* civ, char *nombre){
    if(civ==NULL){
        puts("Civilizaciones no tiene memoria");
        return NULL;
    }
    Nodo *temp=civ->inicio;
    while(temp!=NULL){
        if(strcmp(nombre,temp->dato->nombre)==0){
            return temp->dato;
        }
        temp=temp->siguiente;
    }
    return NULL;
}

typedef ListaLigada Civilizaciones;
#define Civilizaciones_init ListaLigada_init
#define Civilizaciones_respa Civilizaciones_respaldar
#define Civilizaciones_free free_ListaLigada
#define Civilizaciones_insertar_al_inicio Insertar_al_principio_ListaLigada
#define Civilizaciones_insertar_al_final Insertar_al_final_ListaLigada
#define Civilizaciones_mostrar  mostrar_ListaLigada
#define Civilizaciones_eliminar_al_inicio  eliminar_inicio_ListaLigada
#define Civilizaciones_eliminar_al_final  eliminar_final_ListaLigada

#endif // LISTALIGADA_H_INCLUDED
