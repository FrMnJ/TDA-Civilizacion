#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



char buffer[100];

char *leerCadena(char *mensaje){
    char *cadena;
    printf("%s",mensaje);
    fflush(stdin);
    cadena = fgets(buffer,sizeof(buffer),stdin);
    if(cadena != NULL){
        buffer[strlen(buffer)-1] = '\0';
        cadena = &buffer;
    }
    puts("");
    return cadena;

}


int leerInt(char *mensaje){
    int entero;
    printf("%s",mensaje);
    scanf("%i",&entero);
    puts("");
    return entero;
}

int leerFloat(char *mensaje){
    float entero;
    printf("%s",mensaje);
    scanf("%f",&entero);
    puts("");
    return entero;
}


size_t leerPos(char *mensaje){
    size_t entero;
    printf("%s",mensaje);
    scanf("%zu",&entero);
    puts("");
    return entero;
}


#endif // UTIL_H_INCLUDED
