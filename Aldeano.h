#ifndef ALDEANO_H_INCLUDED
#define ALDEANO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

typedef struct aldeano{
    char *nombre;
    int edad;
    int salud;
}Aldeano;

Aldeano *Aldeano_init(char *nombre, int edad, int salud){
    Aldeano *aux=(Aldeano*)malloc(sizeof(Aldeano));
    if(aux!=NULL){
        aux->nombre=strdup(nombre);
        aux->edad=edad;
        aux->salud=salud;
    }
    return aux;
}

Aldeano *Aldeano_free(Aldeano *al){
    if(al!=NULL){
        free(al->nombre);
        al->nombre=NULL;
        free(al);
        al=NULL;
    }
    return al;
}

bool Aldeano_mostrar(Aldeano *obj){
    bool suc=true;
    if(obj!=NULL){
        printf("Nombre: %s\n",obj->nombre);
        printf("Edad: %i\n",obj->edad);
        printf("Salud: %i\n",obj->salud);
        return suc;
    }
    suc=false;
    return suc;
}


bool aldeano_fila(Aldeano *al){
    bool suc=false;
    if(al!=NULL){
        printf("%-20s %-10i %-10i\n",al->nombre,al->edad,al->salud);
        suc=true;
    }
    return suc;
}

bool Aldeano_mostrar_fila(Aldeano * a){
    bool suc=true;
    if(a!=NULL){
        printf("%15s %10i %10i",a->nombre,a->edad,a->salud);
    }
    suc=false;
    return suc;
}

Aldeano* Aldeanos_capturar(){
    int edad,salud;
    char *nombre;
    nombre=leerCadena("Nombre: ");
    edad=leerInt("Edad: ");
    salud=leerInt("Salud: ");
    Aldeano *aux=Aldeano_init(nombre,edad,salud);
    return aux;
}


#endif // ALDEANO_H_INCLUDED
