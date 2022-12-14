#ifndef MENUPUERTO_H_INCLUDED
#define MENUPUERTO_H_INCLUDED
#include "Barco.h"
#include "Puerto.h"

void MenuPuerto(Puerto *puerto){
    enum OPCSPuerto{
        SALIR,
        AGREGAR_FINAL,
        AGREGAR_INICIO,
        MOSTRAR,
        ELIMINAR_FINAL,
        ELIMINAR_INICIO,
        BUSCAR_BARCO
    };
    int opc;
    Barco *aux;
    size_t auxBuscar;
    do{
            printf("\t\t| MENU PUERTO |\n");
    ENDL ENDL
        printf("%i)Agregar al final\n",AGREGAR_FINAL);
        printf("%i)Agregar al inicio\n",AGREGAR_INICIO);
        printf("%i)Mostrar\n",MOSTRAR);
        printf("%i)Eliminar final\n",ELIMINAR_FINAL);
        printf("%i)Eliminar inicio\n",ELIMINAR_INICIO);
        printf("%i)Buscar barco\n",BUSCAR_BARCO);
        puts("0) Salir");
        opc=leerInt("Ingresa una opcion: ");
        switch(opc){
        case AGREGAR_INICIO:
            aux=Barco_capturar();
            pause
            cls
           Insertar_al_principio_Puerto(puerto,aux);
            break;
        case AGREGAR_FINAL:
            aux=Barco_capturar();
            pause
            cls
           Insertar_al_final_Puerto(puerto,aux);
            break;
        case MOSTRAR:
            cls
            mostrar_Puerto(puerto);
            pause
            cls
            break;
        case ELIMINAR_INICIO:
            eliminar_inicio_Puerto(puerto);
            pause
            cls
            break;
         case ELIMINAR_FINAL:
            eliminar_final_Puerto(puerto);
            pause
            cls
            break;
        case BUSCAR_BARCO:
            auxBuscar=leerPos("ID: ");
            aux=Puerto_buscar(puerto,auxBuscar);
            cls;
            if(aux==NULL){
                puts("No se encontraron resultados");
            }
            else{
                BarcoMenu(aux);
                cls
            }
            break;
        case SALIR:
            cls
            return;
            break;
        default:
            puts("Opcion invalida");
            pause
            cls
            break;
        }
    }while(opc!=SALIR);
}


#endif // MENUPUERTO_H_INCLUDED
