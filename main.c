#include <stdio.h>
#include <stdlib.h>
#define cls system("cls");
#define pause system("pause");
#define ENDL puts("");
#include "Menu_Civilizaciones.h"

int main() {
 Civilizaciones *civi=Civilizaciones_init();
    menu_civilizaciones(civi);
    Civilizaciones_free(civi);

 return 0;
}
