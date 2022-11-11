#ifndef BARCO_H_INCLUDED
#define BARCO_H_INCLUDED
#include "PiladeGuerreros.h"

struct barco {
	size_t id;
	float combustible;
	float velocidad;
	float armadura;
	PilaGuerreros *guerreros;
};
typedef struct barco Barco;

struct NodoBarco(){
    Barco *barco;
    struct NodoBarco* siguiente;
    struct NodoBarco* anterior;
};

Barco* Barco_init(size_t id, float combustible, float velocidad, float armadura){
    Barco *nuevoBarco=(Barco*)malloc(sizeof(Barco));
    if(nuevoBarco!=NULL){
        nuevoBarco->guerreros=Pila_init();
        nuevoBarco->id=id;
        nuevoBarco->combustible=combustible;
        nuevoBarco->velocidad=velocidad;
        nuevoBarco->armadura=armadura;
    }
    return nuevoBarco;
}

NodoBarco* NodoBarco_init(Barco *barco){
    NodoBarco nuevoNodoBarco=(NodoBarco*)malloc(sizeof(NodoBarco));
    if(nuevoNodoBarco!=NULL){
        nuevoNodoBarco->barco=barco;
        nuevoNodoBarco->siguiente=NULL;
        nuevoNodoBarco->anterior=NULL;
    }
    return nuevoNodoBarco;
}

Barco* Barco_capturar(){
    size_t id;
    float combustible,velocidad,armadura;
    id=leerPos("ID: ");
    combustible=leerFloat("Combustible: ");
    velocidad=leerFloat("Velocidad: ");
    armadura=leerFloat("Armadura: ");
    return Barco* nuevoBarco=Barco_init(id,combustible.velocidad,armadura);
}

Barco *Barco_free(Barco *barco){
    if(barco!=NULL){
        barco->guerreros=Pila_free(barco->guerreros);
        free(barco);
    }
    return barco;
}

NodoBarco *NodoBarco_free(NodoBarco *nodobarco){
    if(barco!=NULL){
        Barco_free(nodobarco->barco);
    }
    free(nodobarco);
    return barco;
}

bool Barco_mostrar(Barco *barco){
    if(barco!=NULL){
        printf("ID: %i\n",barco->id);
        printf("Combustible: %i\n",barco->combustible);
        printf("Velocidad: %i\n",barco->velocidad);
        printf("Armadura: %i\n",barco->armadura);
        printf("Numero de guerreros: %i\n",barco->guerreros->cantidad);
        return true;
    }
    return false;
}

#endif // BARCO_H_INCLUDED
