#ifndef BATALLA_H_INCLUDED
#define BATALLA_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Barco.h"
#include "Civilizacion.h"

typedef struct batalla
{
    NodoBarco* inicio;
    NodoBarco* final;
    size_t cantidad;
} Batalla;


bool vacia_Batalla(Batalla* batalla)
{
    if(batalla==NULL)
    {
        puts("batalla no tiene memoria");
        exit(1);
    }
    return batalla->cantidad==0;
}

Batalla* Batalla_init()
{
    Batalla* nuevaBatalla=(Batalla*)malloc(sizeof(Batalla));
    if(nuevaBatalla==NULL)
    {
        puts("No se pudo reservar memoria para puerto");
        return nuevaBatalla;
    }
    nuevaBatalla->inicio=NULL;
    nuevaBatalla->final=NULL;
    nuevaBatalla->cantidad=0;
    return nuevaBatalla;
}



bool Insertar_al_principio_Batalla(Batalla* batalla,NodoBarco *nuevo)
{
    bool suc=false;
    if(batalla==NULL)
    {
        puts("Batalla no tiene memoria");
        return suc;
    }
    if(nuevo==NULL)
    {
        puts("No se pudo insertar al inicio");
        return suc;
    }
    if(vacia_Batalla(batalla))
    {
        batalla->inicio=nuevo;
        batalla->final=nuevo;
        batalla->cantidad++;
    }
    else
    {
        nuevo->siguiente=batalla->inicio;
        batalla->inicio->anterior=nuevo;
        batalla->inicio=nuevo;
        batalla->cantidad++;
    }
    suc=true;
    return suc;
}

bool encolar_batalla(Batalla* batalla,NodoBarco *nuevo)
{
    if(batalla==NULL)
    {
        puts("ListaLigada no tiene memoria");
        return false;
    }
    if(vacia_Puerto(batalla))
    {
        return Insertar_al_principio_Batalla(batalla,nuevo);
    }
    nuevo->anterior=batalla->final;
    batalla->final->siguiente=nuevo;
    batalla->final=nuevo;
    batalla->cantidad++;
    return true;
}

NodoBarco *desligar_inicio_Batalla(Batalla* batalla)
{
    if(batalla==NULL)
    {
        puts("Batalla no tiene memoria");
        return false;
    }
    if(vacia_Batalla(batalla))
    {
        puts("No se puede eliminar en Batalla vacia");
        return false;
    }
    NodoBarco* temp=batalla->inicio;
    batalla->inicio=temp->siguiente;
    batalla->cantidad--;
    if(vacia_Puerto(batalla))
    {
        batalla->final=NULL;
    }
    else
    {
        batalla->inicio->anterior=NULL;
    }
    return temp;
}

bool eliminar_inicio_Batalla(Batalla* batalla)
{
    if(batalla==NULL)
    {
        puts("Batalla no tiene memoria");
        return false;
    }
    if(vacia_Batalla(batalla))
    {
        puts("No se puede eliminar en Batalla vacia");
        return false;
    }
    NodoBarco* temp=batalla->inicio;
    batalla->inicio=temp->siguiente;
    batalla->cantidad--;
    if(vacia_Puerto(batalla))
    {
        batalla->final=NULL;
    }
    else
    {
        batalla->inicio->anterior=NULL;
    }
    temp=NodoBarco_free(temp);
    return true;
}


bool free_Batalla(Batalla* batalla)
{
    while(batalla->inicio!=NULL)
    {
        eliminar_inicio_Batalla(batalla);
    }
    free(batalla);
    return true;
}

bool mostrar_Batalla(Batalla* batalla)
{
    if(batalla==NULL)
    {
        puts("ListaLigada no tiene memoria");
        return false;
    }
    NodoBarco *temp=batalla->inicio;
    printf("Cantidad: %i\n",batalla->cantidad);
    while(temp!=NULL)
    {
        Barco_mostrar(temp->barco);
        ENDL ENDL
        temp=temp->siguiente;
    }
    return true;
}


Barco *Batalla_buscar(Batalla* batalla, size_t id)
{
    if(batalla==NULL)
    {
        puts("Civilizaciones no tiene memoria");
        return NULL;
    }
    NodoBarco *temp=batalla->inicio;
    while(temp!=NULL)
    {
        if(id==temp->barco->id)
        {
            return temp->barco;
        }
        temp=temp->siguiente;
    }
    return NULL;
}



#endif // BATALLA_H_INCLUDED
