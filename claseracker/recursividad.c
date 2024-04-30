#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Hay algo que se resuelve inmediatamente y otra parte se delega a  una llamada a la misma funcion.

//Problema: Hacer unafuncionr recursiva que me devuelva verdadero si todas las cifras de un numnero son pares y falso si no. 
// ACCEDER A CADA NUMERO A TRAVES DEL INDICE, HACER % 2, SI DA 0 SIGUE TRUE, SI NO FALSE.

//EJERCICIO 2 sacar potencia a traves de la recursividad.

int multiplicacion(int numero, int exponente) {
    int resultado;   
    if (exponente == 1)
    {
        return numero;
    }
    resultado = numero + multiplicacion(numero, exponente -1);
    return resultado;
}
void mafiaChina(int nivel) {
    if (nivel <= 0) {
        printf("Delegación inválida.\n");
        return;
    }

    // Caso base: dibujar el chino principal
    if (nivel == 1) {
        printf("(-.-)");
        return;
    }

    // Dibujar la parte izquierda de la delegación
    printf("(-.");

    // Llamada recursiva para dibujar la delegación interior
    mafiaChina(nivel - 1);

    // Dibujar la parte derecha de la delegación
    printf(".-)");
}

void hondaHL(char a[]){
    if (a == "L")
    {
        printf("_");
    }
    if (a == "H")
    {
        printf("¯");
    }
    

}


double cociente(int m, int n){
    if (m < n)
    {
        return 0;
    }
    return 1 + cociente(m-n,n);
    
}

int potencia(int base, int exponente) {
    int resultado;
    if (exponente == 0)
    {
        return 1;
    } 
    resultado =  base * potencia(base, exponente - 1);
    return resultado;
}



bool digitosPares(int n){
    bool resultado;
    if (n == 0)
    {
        resultado = true;
    }
    else{
        int n1, n2;
        n2 = n % 2;
        if (n2 == 1)
        {
            resultado = false;
        } else {
            n1 = n/10;
            resultado = digitosPares(n1);
        }
        
    }
    
    return resultado;
}

int main()
{
    int a, b;
    printf("Ingrese un numero:  ");
    scanf("%d", &a);

    mafiaChina(a);
    
    return 0;
}
