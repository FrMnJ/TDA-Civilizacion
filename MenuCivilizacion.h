#ifndef MENUCIVILIZACION_H_INCLUDED
#define MENUCIVILIZACION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Civilizacion.h"




void menuCivilizacion(Civilizacion *civilizacion){
    enum OPCCivilizacion{
        SALIR,
        PUERTO,
        ALDEANOS
    };

    int opc;
    do{
        puts("1) Puerto");
        puts("2) Aldeanos");
        puts("0) Salir");
        opc=leerInt("Opcion: ");
        switch(opc){
        case PUERTO:
            MenuPuerto(civilizacion->puerto);
            break;
        case ALDEANOS:
            lista_menu_aldeanos(civilizacion->aldeanos);
            break;
        case SALIR:
            continue;
            break;
        default:
            puts("Opcion invalida");
            break;
        }

    }while(opc!=SALIR);
}


#endif // MENUCIVILIZACION_H_INCLUDED
