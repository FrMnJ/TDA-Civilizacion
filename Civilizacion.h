#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED
#include "lista_aldeanos.h"
#include "Puerto.h"
#include "Batalla.h"
struct civilizacion{
    char *nombre;
   AldeanosLista *aldeanos;
    Puerto *puerto;
    Batalla *batalla;
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
    aux->batalla=Batalla_init();
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
    free_Puerto(civ->puerto);
    free_Batalla(civ->batalla);
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

void menuBatalla(Civilizacion* civilizacion)
{
    enum OPCSBATALLA
    {
        SALIR,
        ENCOLAR_EXTRAYENDO_INICIO,
        ENCOLAR_EXTRAYENDO_FINAL,
        MOSTRAR,
        REGRESAR_PUERTO
    };
    int opc,opcRegresar;
    NodoBarco* nuevo;
    do
    {
        printf("%i)Encolar(Extrayendo al inicio)\n",ENCOLAR_EXTRAYENDO_INICIO);
        printf("%i)Encolar(Extrayendo al final)\n",ENCOLAR_EXTRAYENDO_FINAL);
        printf("%i)Regresar barco al puerto\n",REGRESAR_PUERTO);
        printf("%i)Mostrar\n",MOSTRAR);
        printf("%i)Salir\n",SALIR);
        opc=leerInt("Ingrese una opcion: ");
        switch(opc)
    {
    case ENCOLAR_EXTRAYENDO_INICIO:
        nuevo=desligar_inicio_Puerto(civilizacion->puerto);
            if(nuevo==NULL)
            {
                puts("No se pudo extraer ningun barco del puerto");
            }
            else if(nuevo->barco->combustible>0)
            {
                nuevo->barco->velocidad=leerFloat("Ingrese la velocidad: ");
                if(encolar_batalla(civilizacion->batalla,nuevo))
                {
                    puts("Se encolo correctamente");
                }
            }
            else
            {
                Insertar_al_principio_PuertoN(civilizacion->puerto,nuevo);
            }
            break;
        case ENCOLAR_EXTRAYENDO_FINAL:
            nuevo=desligar_final_Puerto(civilizacion->puerto);
            if(nuevo==NULL)
            {
                puts("No se pudo extraer ningun barco del puerto");
            }
            else if(nuevo->barco->combustible>0)
            {
                nuevo->barco->velocidad=leerFloat("Ingrese la velocidad: ");
                if(encolar_batalla(civilizacion->batalla,nuevo))
                {
                    puts("Se encolo correctamente");
                }
            }
            else
            {
                Insertar_al_final_PuertoN(civilizacion->puerto,nuevo);
            }
            break;
        case REGRESAR_PUERTO:
            nuevo=desligar_inicio_Batalla(civilizacion->batalla);
            if(nuevo==NULL)
            {
                puts("No se pudo extraer ningun barco del puerto");
            }
            else
            {
                nuevo->barco->armadura=leerFloat("Armadura: ");
                nuevo->barco->combustible=leerFloat("Combustible: ");
                if(nuevo->barco->armadura>0)
                {
                    puts("1.Insertar al final");
                    puts("2.Insertar al principio");
                    opcRegresar=leerInt("Ingrese una opcion: ");
                    switch(opcRegresar)
                    {
                    case 1:
                        Insertar_al_final_PuertoN(civilizacion->puerto,nuevo);
                        break;
                    case 2:
                        Insertar_al_principio_PuertoN(civilizacion->puerto,nuevo);
                        break;
                    default:
                        puts("Opcion incorrecta");
                        break;
                    }
                }
                else
                {
                    nuevo=NodoBarco_free(nuevo);
                }
            }
            break;
                    case MOSTRAR:
                        mostrar_Batalla(civilizacion->batalla);
                        break;
                    case SALIR:
                        continue;
                        break;
                     default:
                        puts("Opcion incorrecta");
                        break;
        }
    }
    while(opc!=SALIR);

}

#endif // CIVILIZACION_H_INCLUDED
