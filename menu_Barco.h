#ifndef MENU_BARCO_H_INCLUDED
#define MENU_BARCO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Barco.h"
#include "Guerrero.h"

void BarcoMenu(Barco *barco){

    enum OPCSBARCO{
        SALIR,
        AGREGAR,
        ELIMINAR,
        MOSTRAR_TOPE,
        MOSTRAR
    };

    int opc;
    Guerrero *guerreroAux;
    do{
        printf("\t\t| MENU BARCO |\n");
    ENDL ENDL
        puts("1) Agregar guerrero");
        puts("2) Eliminar guerrero");
        puts("3) Mostrar el ultimo guerrero");
        puts("4) Mostrar todos los guerreros");
        puts("0) Salir");
        opc=leerInt("Opcion: ");
        cls
        switch(opc){
        case AGREGAR:
            guerreroAux=Guerrero_capturar();
            Pila_push(barco->guerreros,guerreroAux);
            pause cls
            break;
        case ELIMINAR:
            Pila_pop(barco->guerreros);
            break;
        case MOSTRAR_TOPE:
            Guerrero_mostrar(Pila_top(barco->guerreros));
            pause
            cls
            break;
        case MOSTRAR:
            Barco_mostrar(barco);
            ENDL
            puts("Guerreros: ");
            ENDL
            Guerreros_mostrar(barco);
            ENDL
            pause
            cls
        }
    }while(opc!=SALIR);
}

#endif // MENU_BARCO_H_INCLUDED
