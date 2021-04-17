#include "operacionesMatematicas.h"

int sumar(int operando1, int operando2){

    int resultado;

    resultado = operando1+operando2;

    return resultado;
}

int restar(int operando1,int operando2){

    int resultado;

    resultado = operando1-operando2;

    return resultado;

}

int multiplicar(int operando1, int operando2){

    int resultado;

    resultado = operando1*operando2;

    return resultado;

}

float dividir(int operando1, int operando2){

    float resultado;

    resultado = (float)operando1/operando2;

    return resultado;
}

int factorizar(int operando){

    int resultado=1;

    for(int i=1; i<=operando; i++){

        resultado *= i;
    }
    return resultado;
}
