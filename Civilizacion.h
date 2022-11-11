#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED
#include "lista_aldeanos.h"
#include "Puerto.h"
struct civilizacion{
    char *nombre;
   AldeanosLista *aldeanos;
    Puerto *puerto;
};

typedef struct civilizacion Civilizacion;

Civilizacion*  Civilizacion_init(char *nombre){
    Civilizacion *aux=(Civilizacion*)malloc(sizeof(Civilizacion));
    if(aux==NULL){
        puts("Error al reservar memoria");
        exit(1);
    }
    aux->nombre=strdup(nombre);
    aux->aldeanos=AldeanosLista_init();
    aux->puerto=Puerto_init();
    if(aux->aldeanos==NULL){
        puts("Error al crear la lista de aldeanos");
    }
    return aux;
}

Civilizacion* Civilizacion_free(Civilizacion* civ){
    if(civ==NULL){
        puts("La civilizacion es nula");
        return civ;
    }
    free(civ->nombre);
    civ->nombre=NULL;
    civ->aldeanos=AldeanosLista_free(civ->aldeanos);
    free(civ);
    return civ;
}

Civilizacion* civilizacion_capturar(){
    char *nombre=leerCadena("Nombre de la civilizacion: ");
    Civilizacion *aux=Civilizacion_init(nombre);
    return aux;
}

bool Civilizacion_mostrar(Civilizacion* aux){
    if(aux==NULL){
        puts("Civilizacion no tiene memoria");
        return false;
    }
    printf("Civilizacion: %s\n", aux->nombre);
    if(AldeanosLista_mostrar(aux->aldeanos)){
            ENDL
        pause cls
        return true;
    }
    else {
        puts("No se pudo imprimir correctamente");
        return false;
    }
}

#endif // CIVILIZACION_H_INCLUDED
