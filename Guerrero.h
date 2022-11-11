#ifndef GUERRERO_H_INCLUDED
#define GUERRERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"

const char *tiposDeGuerreros[5]={"Lancero","Arquero","Paladin","Berserker","Escudero"};

enum TIPOS{
    LANCERO,
    ARQUERO,
    PALADIN,
    BERSERKER,
    ESCUDERO
};


typedef struct guerrero{
    int id;
    int salud;
    int fuerza;
    int escudo;
    int tipo;
}Guerrero;

typedef struct nodoguerrero{
    Guerrero *guerrero;
    struct nodoguerrero* siguiente;

}NodoGuerrero;

NodoGuerrero* NodoGuerrero_init(Guerrero *guerrero){
    NodoGuerrero* aux=(NodoGuerrero*)malloc(sizeof(NodoGuerrero));
    if(aux==NULL){
        puts("No se pudo reservar memoria para nodo");
        exit(1);
    }
    aux->guerrero=guerrero;
    aux->siguiente=NULL;
    return aux;
}

Guerrero* Guerrero_init(int id,int salud, int fuerza , int escudo, int tipo){
    Guerrero *nuevoGuerrero=(Guerrero*)malloc(sizeof(Guerrero));
    if(nuevoGuerrero!=NULL){
        nuevoGuerrero->id=id;
        nuevoGuerrero->salud=salud;
        nuevoGuerrero->fuerza=fuerza;
        nuevoGuerrero->escudo=escudo;
        nuevoGuerrero->tipo=tipo;
    }
    return nuevoGuerrero;
}

NodoGuerrero* Guerrero_free(NodoGuerrero *guerrero){
    if(guerrero!=NULL){
        free(guerrero);
        guerrero=NULL;
    }
    return guerrero;
}


bool Guerrero_mostrar(Guerrero* guerrero){
    if(guerrero!=NULL){
        printf("ID: %i\n",guerrero->id);
        printf("Salud: %i\n",guerrero->salud);
        printf("Fuerza: %i\n",guerrero->fuerza);
        printf("Escudo: %i\n",guerrero->escudo);
        printf("Tipo: %s\n",tiposDeGuerreros[guerrero->tipo]);
        return true;
    }
    return false;
}

Guerrero* Guerrero_capturar(){
    int id,salud,fuerza,escudo,tipo;
    id=leerInt("ID: ");
    salud=leerInt("Salud(0-100): ");
    fuerza=leerInt("Fuerza(0.0 - 60.0): ");
    escudo=leerInt("Escudo(0.0 - 30.0): ");
    printf("%i) %s\n",LANCERO,tiposDeGuerreros[LANCERO]);
    printf("%i) %s\n",ARQUERO,tiposDeGuerreros[ARQUERO]);
    printf("%i) %s\n",PALADIN,tiposDeGuerreros[PALADIN]);
    printf("%i) %s\n",BERSERKER,tiposDeGuerreros[BERSERKER]);
    printf("%i) %s\n",ESCUDERO,tiposDeGuerreros[ESCUDERO]);
    tipo=leerInt("Tipo: ");
    Guerrero *nuevoGuerrero=Guerrero_init(id,salud,fuerza,escudo,tipo);
    return nuevoGuerrero;
}
#endif // GUERRERO_H_INCLUDED
