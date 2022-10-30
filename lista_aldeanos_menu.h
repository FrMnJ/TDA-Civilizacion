#ifndef LISTA_ALDEANOS_MENU_H_INCLUDED
#define LISTA_ALDEANOS_MENU_H_INCLUDED
#include "lista_aldeanos.h"
#include "Util.h"
#define cls system("cls");
#define pause system("pause");
enum MENU_LISTA_ALDEANOS{
    SALIR,
    AGREGAR_FINAL,
    AGREGAR_INICIO,
    MOSTRAR,
    INSERTAR,
    ELIMINAR_FINAL,
    ELIMINAR_INICIO,
    ELIMINAR,
    FREE,
    LLENA,
    VACIA
};

void lista_menu_aldeanos(AldeanosLista* lista){
    if(lista==NULL){
        puts("Lista_aldeanos: Error menu.");
        return;
    }
    int opc;
    size_t pos;
    Aldeano* aux;
    do{
        printf("%i)Agregar al final\n",AGREGAR_FINAL);
        printf("%i)Agregar al inicio\n",AGREGAR_INICIO);
        printf("%i)Mostrar\n",MOSTRAR);
        printf("%i)Insertar\n",INSERTAR);
        printf("%i)Eliminar final\n",ELIMINAR_FINAL);
        printf("%i)Eliminar inicio\n",ELIMINAR_INICIO);
        printf("%i)Eliminar\n",ELIMINAR);
        printf("%i)Free\n",FREE);
        printf("%i)Llena\n",LLENA);
        printf("%i)Vacia\n",VACIA);
        printf("%i)Salir\n",SALIR);
        opc=leerInt("Ingresa una opcion: ");
        cls
        switch(opc){
        case AGREGAR_INICIO:
            aux=Aldeanos_capturar();
            pause
            cls
            AldeanosLista_agregar_inicio(lista,aux);
            break;
        case AGREGAR_FINAL:
            aux=Aldeanos_capturar();
            pause
            cls
            AldeanosLista_agregar_final(lista,aux);
            break;
        case MOSTRAR:
            AldeanosLista_mostrar(lista);
            pause
            cls
            break;
        case INSERTAR:
            pos=leerPos("Posicion: ");
            cls
            aux=Aldeanos_capturar();
            pause
            cls
            AldeanosLista_insertar(lista,pos,aux);
            pause
            cls
            break;
        case ELIMINAR_INICIO:
            AldeanosLista_eliminar_inicio(lista);
            pause
            cls
            break;
         case ELIMINAR_FINAL:
            AldeanosLista_eliminar_final(lista);
            pause
            cls
            break;
         case ELIMINAR:
            pos=leerPos("Posicion: ");
            cls
            AldeanosLista_eliminar(lista,pos);
            pause
            cls
            break;
         case FREE:
            AldeanosLista_free(lista);
            pause
            cls
            break;
         case LLENA:
            if(AldeanosLista_llena(lista)) puts("Lista llena");
            else puts("No esta llena");
            pause
            cls
            break;
        case VACIA:
            if(AldeanosLista_vacia(lista)) puts("Lista vacia");
            else puts("No esta vacia");
            pause
            cls
            break;
        case SALIR:
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

#endif // LISTA_ALDEANOS_MENU_H_INCLUDED
