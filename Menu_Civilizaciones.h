#ifndef MENU_CIVILIZACIONES_H_INCLUDED
#define MENU_CIVILIZACIONES_H_INCLUDED
#include "ListaLigada.h"
#include "MenuCivilizacion.h"



void menu_civilizaciones(Civilizaciones* lista){
    enum opciones_civi{
    SALIR,
    INSERTAR_INICIO,
    INSERTAR_FINAL,
    MOSTRAR,
    ELIMINAR_INICIO,
    ELIMINAR_FINAL,
    BUSCAR
};
    int opc;
    char *nombre;
    Civilizacion *civ;
    do{
        puts("\t\t| MENU DE CIVILIZACIONES |");
    ENDL ENDL
        puts("1.Insertar inicio");
        puts("2.Insertar final");
        puts("3.Mostrar");
        puts("4.Eliminar al inicio");
        puts("5.Eliminar al final");
        puts("6.Buscar");
        puts("0.Salir");
        opc=leerInt("Ingresa una opcion: ");
        switch(opc){
        case INSERTAR_INICIO:
            cls
            civ=civilizacion_capturar();
            if(civ==NULL){
                puts("Civilizacion no tiene memoria");
                continue;
            }
            if(Civilizaciones_insertar_al_inicio(lista,civ)){
                puts("Civilizacion se inserto al inicio correctamente");

            }
            else puts("Error al insertar al inicio");
            pause cls

            break;
        case INSERTAR_FINAL:
            cls
            civ=civilizacion_capturar();
            if(civ==NULL){
                puts("Civilizacion no tiene memoria");
                continue;
            }
            if(Civilizaciones_insertar_al_final(lista,civ)){
                puts("Civilizacion se inserto al final correctamente");
            }
            else puts("Error al insertar al inicio");
            pause cls
            break;
        case MOSTRAR:
            cls
            if(Civilizaciones_mostrar(lista)){
                puts("Civilizaciones: Se mostraron correctamente");
            }
            else{
                puts("Civilizaciones: No se mostro correctamente");
            }
            ENDL
             pause cls
            break;
        case ELIMINAR_INICIO:
            cls
            if(Civilizaciones_eliminar_al_inicio(lista))
                puts("Civilizaciones: Se libero correctamente");
            else
                puts("Civilizaciones: No se pudo liberar correctamente");
                pause cls
            break;
        case ELIMINAR_FINAL:
            cls
            if(Civilizaciones_eliminar_al_final(lista))
                puts("Civilizaciones: Se libero correctamente");
            else
                puts("Civilizaciones: No se pudo liberar correctamente");
                pause cls
            break;
        case BUSCAR:
            nombre=strdup(leerCadena("Nombre: "));
            civ=Civilizaciones_buscar(lista,nombre);
            if(civ==NULL){
                puts("No se encontro la civilizacion ingresada.");
                pause cls
                continue;
            }
            free(nombre);
            cls
            menuCivilizacion(civ);
            break;
        }
    }while(opc!=SALIR);
}


#endif // MENU_CIVILIZACIONES_H_INCLUDED
