#include <stdio.h>
#include <stdlib.h>
#include "menuOpciones.h"

void mostrarMenuOpciones(int *primerOperando, int *segundoOperando, int *bandera1, int *bandera2)
{

    printf("    ***MENU DE OPCIONES***\n\n");

    if(*bandera1)
    {
        printf("    1-Ingresar 1er operando (A=x)\n");
    }
    else
    {
        printf("    1-Ingresar 1er operando (A=%d)\n", *primerOperando);
    }

    if(*bandera2)
    {
        printf("    2-Ingresar 2do operando (B=y)\n");

    }
    else
    {
        printf("    2-Ingresar 2do operando (B=%d)\n", *segundoOperando);
    }

    printf("    3-Calcular todas las operaciones:\n");
    printf("\n      a)Calcular la suma (A+B)");
    printf("\n      b)Calcular la resta (A-B)");
    printf("\n      d)Calcular la multiplicacion (A*B)");
    printf("\n      c)Calcular la division (A/B)");
    printf("\n      e)Calcular el factorial (A!) (B!)\n");
    printf("\n    4-Informar resultados.\n");
    printf("    5-Salir.\n\n");

}
