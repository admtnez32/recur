/****************************
*    LABORATORIO            *
*    TP 1  en C             *
*    IDE ECLIPSE            *
*                           *
*    MARTINEZ ALEXIS        *
*    DIV 1G                 *
****************************/

#include <stdio.h>
#include <stdlib.h>
#include "operacionesMatematicas.h"
#include "menuOpciones.h"

int main()
{
	setbuf(stdout, NULL);
    //DECLARACION DE VARIABLES
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int resultadoFactorialA;
    int resultadoFactorialB;
    float resultadoDivision;

    int primerOperando;
    int segundoOperando;
    int opcion;

    int flag1 = 1;
    int flag2 = 1;
    int flagPrimerOperando = 0;
    int flagSegundoOperando = 0;
    int flagCalculos = 0;

    char respuestaUsuario;

    do      //INICIO DEL BUCLE, SE UTILIZA DO...WHILE PARA INGRESAR MINIMO 1 VEZ
    {
        system("cls");  //LIMPIEZA DE CONSOLA

        mostrarMenuOpciones(&primerOperando, &segundoOperando, &flag1, &flag2);    //LLAMADA A LA FUNCION PARA MOSTRAR EL MENU DE OPCIONES

        printf("Ingrese opcion: ");
        scanf("%d", &opcion);       //SOLICITUD DE OPCION ELEGIDA

        switch(opcion)      //INICIO SENTENCIA, SE UTILIZA SWITCH PARA EVALUAR MULTIPLES CASOS
        {

        case 1:             //SOLICITO PRIMER OPERANDO

            system("cls");

            printf("Ingrese primer primerOperando: ");
            scanf("%d", &primerOperando);
            printf("\n\n");

            flagPrimerOperando = 1;         //BANDERA UTILIZADA PARA VALIDAR QUE SE INGRESO EL PRIMER OPERANDO
            flag1 = 0;                      //BANDERA UTILZADA PARA MOSTRAR EL OPERANDO INGRESADO EN EL MENU DE OPCIONES
            break;

        case 2:         //SOLICITO SEGUNDO OPERANDO

            system("cls");

            if(flagPrimerOperando)
            {

                printf("Ingrese segundo primerOperando: ");
                scanf("%d", &segundoOperando);
                printf("\n\n");

                flagSegundoOperando = 1;    //BANDERA UTILIZADA PARA VALIDAR QUE SE INGRESO EL SEGUNDO OPERANDO
                flag2 = 0;                  //BANDERA UTILZADA PARA MOSTRAR EL OPERANDO INGRESADO EN EL MENU DE OPCIONES
            }
            else
            {
                printf("Primero debe ingresar el primer primerOperando.\n\n");
            }
            break;

        case 3:         //LLAMADO A FUNCIONES MATEMATICAS

            system("cls");

            if(flagSegundoOperando)
            {

                resultadoSuma = sumar(primerOperando, segundoOperando);
                resultadoResta = restar(primerOperando, segundoOperando);
                resultadoMultiplicacion = multiplicar(primerOperando, segundoOperando);
                resultadoDivision = dividir(primerOperando, segundoOperando);
                resultadoFactorialA = factorizar(primerOperando);
                resultadoFactorialB = factorizar(segundoOperando);

                printf("\nSe calcularon todas las operaciones.\n\n");

                flagCalculos = 1;           //BANDERA UTILIZADA PARA VALIDAR QUE SE CALCULARON LAS OPERACIONES
            }
            else
            {
                printf("Primero debe ingresar el segundo primerOperando.\n\n");
            }
            break;

        case 4:         //MUESTRA DE RESULTADOS

            system("cls");

            if(flagCalculos)
            {
                printf("\nLuego de mostrar los resultados, la calculadora se reiniciara. \n\nDesea continuar? (s-n): ");
                fflush(stdin);
                scanf("%c", &respuestaUsuario);

                while(respuestaUsuario != 's' && respuestaUsuario != 'n')
                {
                    printf("\nRespuesta invalida. Ingrese 's' para continuar o 'n' para abortar.\n\nRespuesta: ");
                    fflush(stdin);
                    scanf("%c", &respuestaUsuario);
                }

                if(respuestaUsuario == 's')
                {

                    system("cls");
                    printf("Los resultados son: \n\n");
                    printf("    Suma (%d + %d) = %d\n\n", primerOperando, segundoOperando, resultadoSuma);
                    printf("    Resta (%d - %d) = %d\n\n", primerOperando, segundoOperando, resultadoResta);
                    printf("    Multiplicacion (%d * %d) = %d\n\n", primerOperando, segundoOperando, resultadoMultiplicacion);

                    if(segundoOperando != 0){
                        printf("    Division (%d / %d) = %.2f\n\n", primerOperando, segundoOperando, resultadoDivision);
                    }
                    else
                    {
                        printf("    No se puede dividir por cero\n\n");
                    }

                    if(primerOperando > 0 && primerOperando < 13){
                        printf("    Factorial A (!%d) = %d\n\n", primerOperando, resultadoFactorialA);
                    }
                    else
                    {
                        printf("    No se puede calcular el factorial debido a que es un numero negativo o es un numero mayor a 12\n\n");
                    }

                    if(segundoOperando >= 0 && segundoOperando < 13){
                        printf("    Factorial B (!%d) = %d\n\n", segundoOperando, resultadoFactorialB);
                    }
                    else
                    {
                        printf("    No se puede calcular el factorial debido a que es un numero negativo o es un numero mayor a 12\n\n");
                    }

                    printf("\n\n      ***Reiniciando calculadora***\n\n\n");

                    //RESET DE FLAGS
                    flagPrimerOperando=0;
                    flagSegundoOperando=0;
                    flagCalculos=0;
                    flag1 = 1;
                    flag2 = 1;
                }
                else
                {
                    printf("\nVolviendo al menu inicial\n\n");
                }
            }
            else
            {
                printf("Primero debe calcular las operaciones.\n\n");
            }
            break;

        case 5:         //SALIR DE LA CALCULADORA

            system("cls");
            printf("\n*** Adios ***\n\n");
            break;

        default:

            printf("\nERROR. Ingrese una opcion valida.\n\n");      //AVISO DE INGRESO OPCION INVALIDA
            break;

        }
        system("pause");
    }
    while(opcion != 5);

    return 0;
}
