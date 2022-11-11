#include <stdio.h>
#include <stdlib.h>
#define cls system("cls");
#define pause system("pause");
#define ENDL puts("");
#include "Guerrero.h"
#include "PiladeGuerreros.h"
#include "Menu_Civilizaciones.h"
#include "menu_Barco.h"

int main() {

    Civilizaciones *civi=Civilizaciones_init();
    menu_civilizaciones(civi);
    Civilizaciones_free(civi);


 return 0;
}
