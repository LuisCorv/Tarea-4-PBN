
//este archivo es basicamente para revisar que todo funcione en c++, una vez echo eso, eliminarlo y arreglar nuevamente el makefile

//- En Windows: mingw32-make
#include "grafos.h"


int main(){
    grafos grafitos(2);
    grafitos.add_nodo();
    grafitos.add_arco(0,1);
    grafitos.add_arco(1,2);
    grafitos.add_arco(0,3);
    grafitos.imprimir_nodos();
    grafitos.imprimir_arcos();
    grafitos.imprimir_si_hay_arco(0,1);
    grafitos.imprimir_si_hay_arco(0,3);
    grafitos.imprimir_si_hay_camino(0,2);
    return 0;
}