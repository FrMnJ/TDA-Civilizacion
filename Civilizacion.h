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

bool Civilizacion_respaldar(Civilizacion *civilizacion,FILE *archivo){
    if(civilizacion==NULL){
        puts("Civilizacion no tiene memoria");
        return false;
    }
    if(archivo==NULL){
        puts("No se pudo abrir el archivo");
        return true;
    }
    fprintf(archivo,"%s\n",civilizacion->nombre);
    char nombre[100];
    strcpy(nombre,civilizacion->nombre);
    strcat(nombre,".txt");
    FILE *archivoLista=fopen(nombre,"w");
    if(archivoLista==NULL){
        puts("No se pudo abrir archivo lista");
        return false;
    }
    for(size_t i=0;i<civilizacion->aldeanos->cantidad;i++){
            fprintf(archivoLista,"%s\n",civilizacion->aldeanos->aldeanos[i]->nombre);
            fprintf(archivoLista,"%i\n",civilizacion->aldeanos->aldeanos[i]->edad);
            fprintf(archivoLista,"%i\n",civilizacion->aldeanos->aldeanos[i]->salud);
    }
    fclose(archivoLista);
    return true;

}

Civilizacion* recuperar_Civilizacion(FILE *archivo){
    if(archivo==NULL){
        puts("No se pudo abrir el archivo");
        return NULL;
    }
    char buffer[100];
    fgets(buffer,100,archivo);
    if(feof(archivo)) return NULL;
    buffer[strlen(buffer)-1]='\0';
    Civilizacion *nueva=Civilizacion_init(buffer);
    if(nueva==NULL){
        puts("Error al crear civilizacion");
        return NULL;
    }
    char nombre_archivo[100];
    strcpy(nombre_archivo,buffer);
    strcat(nombre_archivo,".txt");
    FILE *archivoLista=fopen(nombre_archivo,"r");
    recuperar_ListaAldeanos(nueva->aldeanos,archivoLista);
    return nueva;
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
        printf("%i)Mostrar\n",MOSTRAR);
        printf("%i)Regresar barco al puerto\n",REGRESAR_PUERTO);
        printf("%i)Salir\n",SALIR);
        opc=leerInt("Ingrese una opcion: ");
        cls
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
            pause cls
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
            pause cls
            break;
        case REGRESAR_PUERTO:
            nuevo=desligar_inicio_Batalla(civilizacion->batalla);
            if(nuevo==NULL)
            {
                puts("No se pudo extraer ningun barco de la batalla");
            }
            else
            {

                nuevo->barco->armadura=leerFloat("Armadura: ");
                nuevo->barco->combustible=leerFloat("Combustible: ");
                nuevo->barco->velocidad=0;
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
            pause cls
            break;
                    case MOSTRAR:
                        mostrar_Batalla(civilizacion->batalla);
                        pause cls
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
