#ifndef LISTA_ALDEANOS_H_INCLUDED
#define LISTA_ALDEANOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Aldeano.h"

#define CAPACIDAD 5

struct lista_aldeanos
{
    Aldeano **aldeanos;
    size_t capacidad;
    size_t cantidad;
};

typedef struct lista_aldeanos AldeanosLista;

bool expandir_lista(AldeanosLista* lista)
{
    bool suc=false;
    if(lista!=NULL)
    {
        puts("Expandiendo lista...");
        size_t nwCap=lista->cantidad+CAPACIDAD;
        Aldeano **temp=(Aldeano**)realloc(lista->aldeanos,sizeof(Aldeano*)*nwCap);
        if(temp!=NULL)
        {
            puts("Se expandio la lista");
            lista->aldeanos=temp;
            lista->capacidad=nwCap;
            suc=true;
        }
        else
        {
            puts("No fue posible expandir");
        }
    }
    return suc;
}


AldeanosLista* AldeanosLista_init()
{
    AldeanosLista *aux=(AldeanosLista*)malloc(sizeof(AldeanosLista));
    if(aux!=NULL)
    {
        aux->aldeanos=(Aldeano**)malloc(sizeof(Aldeano*)*CAPACIDAD);
        if(aux->aldeanos==NULL)
        {
            puts("No se pudo crear la lista de Aldeanos");
            exit(1);
        }
        aux->cantidad=0;
        aux->capacidad=CAPACIDAD;
    }
    return aux;
}


AldeanosLista* AldeanosLista_free(AldeanosLista* l)
{
    if(l!=NULL)
    {
        for(int i=0; i<l->cantidad; i++)
        {
            if(l->aldeanos[i]!=NULL)
            {
                Aldeano_free(l->aldeanos[i]);
            }
        }
        free(l->aldeanos);
        l->aldeanos=NULL;
        free(l);
        l=NULL;
    }
    return l;
}


bool AldeanosLista_llena(AldeanosLista* lista)
{
    if(lista==NULL)
    {
        puts("No existe la lista");
        exit(1);
    }
    return lista->cantidad == lista->capacidad;
}


bool AldeanosLista_vacia(AldeanosLista* lista)
{
    if(lista==NULL)
    {
        puts("No existe la lista");
        exit(1);
    }
    return lista->cantidad == 0;
}


bool AldeanosLista_agregar_final(AldeanosLista* lista,Aldeano *aldeano)
{
    if(lista!=NULL)
    {
        if(AldeanosLista_llena(lista)) expandir_lista(lista);
        lista->aldeanos[lista->cantidad]=aldeano;
        lista->cantidad++;
        return true;
    }
    return false;
}


bool AldeanosLista_mostrar(AldeanosLista* lista)
{
    bool success=false;
    if(lista!=NULL)
    {

        printf("Cantidad: %zu Capacidad: %zu\n",lista->cantidad,lista->capacidad);
        ENDL
        printf("%-20s %-10s %-10s\n","Nombre","Edad","Salud");
        for(size_t i=0; i<lista->cantidad; i++)
        {
            aldeano_fila(lista->aldeanos[i]);
        }
        success=true;
    }

    return success;
}


bool AldeanosLista_agregar_inicio(AldeanosLista* lista,Aldeano *al)
{
    bool success=false;
    if(AldeanosLista_llena(lista))  expandir_lista(lista);
    for(size_t i=lista->cantidad; i>0; i--)
    {
        lista->aldeanos[i]=lista->aldeanos[i-1];
    }
    lista->aldeanos[0]=al;
    success=true;
    lista->cantidad++;
    return success;
}


bool AldeanosLista_insertar(AldeanosLista *lista,size_t pos, Aldeano *aldeano)
{
    bool success=false;
    if(AldeanosLista_llena(lista)) expandir_lista(lista);
    if(pos>=lista->cantidad)
    {
        puts("Rango invalido");
        return success;
    }
    for(size_t i=lista->cantidad; i>pos; i--)
    {
        lista->aldeanos[i]=lista->aldeanos[i-1];
    }
    lista->aldeanos[pos]=aldeano;
    lista->cantidad++;
    success=true;
    return success;
}


bool AldeanosLista_eliminar_final(AldeanosLista *lista)
{
    bool suc=false;
    if(lista!=NULL)
    {
        if(!AldeanosLista_vacia(lista))
        {
            lista->aldeanos[lista->cantidad-1]=Aldeano_free(lista->aldeanos[lista->cantidad-1]);
            if(lista->aldeanos[lista->cantidad-1]==NULL)
            {
                puts("Se libero la memoria del aldeano");
                lista->cantidad--;
                suc=true;
            }
        }
    }
    return suc;

}


bool AldeanosLista_eliminar_inicio(AldeanosLista *lista)
{
    if(AldeanosLista_vacia(lista)){
        puts("Tratando de eliminar en lista vacia");
        return false;
    }
    Aldeano_free(lista->aldeanos[0]);
    for(size_t i=0;i<lista->cantidad-1;i++){
        lista->aldeanos[i]=lista->aldeanos[i+1];
    }
    lista->aldeanos[lista->cantidad-1]=NULL;
    lista->cantidad--;
    return true;
}


bool AldeanosLista_eliminar(AldeanosLista *lista, size_t pos)
{
    if(AldeanosLista_vacia(lista)){
        puts("Tratando de eliminar en lista vacia");
        return false;
    }
    if(pos==0){
        AldeanosLista_eliminar_inicio(lista);
        return true;
    }
    if(pos==lista->cantidad-1){
        AldeanosLista_eliminar_final(lista);
        return true;
    }
    Aldeano_free(lista->aldeanos[pos]);
    for(size_t i=pos;i<lista->cantidad-1;i++){
        lista->aldeanos[i]=lista->aldeanos[i+1];
    }
    lista->aldeanos[lista->cantidad-1]=NULL;
    lista->cantidad--;
    return true;
}


#endif // LISTA_ALDEANOS_H_INCLUDED
