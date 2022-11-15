#ifndef MENUCIVILIZACION_H_INCLUDED
#define MENUCIVILIZACION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Civilizacion.h"
#include "MenuPuerto.h"
#include "lista_aldeanos_menu.h"


void menuCivilizacion(Civilizacion *civilizacion){
    enum OPCCivilizacion{
        SALIR,
        PUERTO,
        ALDEANOS,
        BATALLA
    };

    int opc;
    do{
        printf("\t\t| MENU DE CIVILIZACION: %s |\n",civilizacion->nombre);
    ENDL ENDL
        puts("1) Puerto");
        puts("2) Aldeanos");
        puts("3) Batalla");
        puts("0) Salir");
        opc=leerInt("Opcion: ");
        cls
        switch(opc){
        case PUERTO:
            MenuPuerto(civilizacion->puerto);
            break;
        case ALDEANOS:
            lista_menu_aldeanos(civilizacion->aldeanos);
            break;
        case BATALLA:
            menuBatalla(civilizacion);
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
