#include "libs/arboles/arbol-binario.h"
#include "libs/arboles/arbol-binario-busqueda.h"
#include "libs/arboles/arbol-avl.h"
#include "libs/colas/colas.h"
#include "libs/elementos/tipo_elemento.h"
#include "libs/listas/listas.h"
#include "libs/nodos/nodo.h"
#include "libs/pilas/pilas.h"
#include "libs/hash/tabla_hash.h"
#include "libs/conjuntos/conjuntos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

//Parcial1
Lista rellenarLista(int elementos)
{
    Lista l = l_crear();
    TipoElemento x;
    bool blAg = true;
    for (int i = 0; i < elementos; i++)
    {
        int numero_aleatorio;
        printf("\nIngrese el numero a agregar en la lista: ");

        while (scanf("%d", &numero_aleatorio) != 1)
        {
            printf("\nError: Ingresa un número válido para el elemento: ");
            while (getchar() != '\n')
            {
                // clear input buffer
            }
        }

        x = te_crear(numero_aleatorio);
        blAg = blAg && l_agregar(l, x);
    }
    if (!blAg)
    {
        l = l_crear();
    }
    return l;
}

Pila rellenarPila(int cantidad)
{
    Pila pila = p_crear();
    for (int i = 0; i < cantidad; i++)
    {
        int valor;
        printf("| Ingresa el valor para el elemento %d: ", i + 1);
        while (scanf("%d", &valor) != 1)
        {
            printf("\nError: Ingresa un número válido para el valor: ");
            while (getchar() != '\n')
            {
                // clear input buffer
            }
        }

        p_apilar(pila, te_crear(valor));
    }

    return pila;
}

//COMPLEJIDAD CON LISTAS CON ARREGLOS ES O(n), CON LAS DEMAS IMPLEMENTACIONES DE LISTAS O(N^2), Si no usaramos una lista para devolver el resultado
// y usaramos por ejemplo una pila, la complejidad seria siempre de O(n)
Lista claveEnPila(Pila p, int clave)
{
    Pila aux = p_crear();
    Lista resultado = l_crear();
    while (!p_es_vacia(p))
    {
        TipoElemento ele = p_desapilar(p);
        if (ele->clave == clave)
        {
            l_agregar(resultado, ele);
        }
        p_apilar(aux, ele);
    }

    // REAPILO EN PILA ORIGINAL PARA NO PERDERLA
    while (!p_es_vacia(aux))
    {
        TipoElemento ele = p_desapilar(aux);
        p_apilar(p, ele);
    }
    return resultado;
}

//COMPLEJIDAD O(n) en las implementaciones de cursores y punteros, y O(1) en implementaciones de listas con arreglos. 
void listaConPosAux(Lista l, Lista resultado, int clave, int pos, Iterador ite)
{
    if (!hay_siguiente(ite))
    {
        return;
    }
    TipoElemento ele = siguiente(ite);
    if (ele->clave == clave)
    {
        l_agregar(resultado, te_crear(pos));
    }
    listaConPosAux(l, resultado, clave, pos += 1, ite);
}

Lista posiciones(Lista l, int clave)
{
    Iterador ite = iterador(l);
    Lista resultado = l_crear();
    listaConPosAux(l, resultado, clave, 1, ite);
    return resultado;
}

//Parcial2
Cola rellenarCola(int cantidad)
{
    Cola cola = c_crear();
    for (int i = 0; i < cantidad; i++)
    {
        int valor;
        printf("| Ingresa el valor para el elemento %d: ", i + 1);
        while (scanf("%d", &valor) != 1)
        {
            printf("\nError: Ingresa un número válido para el valor: ");
            while (getchar() != '\n')
            {
                // clear input buffer
            }
        }
        c_encolar(cola, te_crear(valor));
    }

    return cola;
}

Lista claveEnCola(Cola c, int clave){
    Lista resultado = l_crear();
    Cola aux = c_crear();
    TipoElemento ele;
    while (!c_es_vacia(c))
    {
        ele = c_desencolar(c);
        if (ele->clave == clave)
        {
            l_agregar(resultado, ele);
        }
        c_encolar(aux, ele);
    }
    
    //REENCOLO
    while (!c_es_vacia(aux))
    {
        ele = c_desencolar(aux);
        c_encolar(c, ele);
    }
    return resultado;
}

void posicionesEnColaAux(Cola c,int clave,Lista resultado, Cola aux){
    if (c_es_vacia(c))
    {
        return;
    }
    TipoElemento ele = c_desencolar(c);
    if (ele->clave == clave)
    {
        l_agregar(resultado,ele);
    }
    c_encolar(aux,ele);
    posicionesEnColaAux(c,clave,resultado,aux);
}

void reencolar(Cola c, Cola aux){
    if (c_es_vacia(aux))
    {
        return;
    }
    TipoElemento ele = c_desencolar(aux);
    c_encolar(c,ele);
    reencolar(c,aux);
}

Lista posicionesEnCola(Cola c, int clave){
    Lista resultado = l_crear();
    Cola aux = c_crear();
    posicionesEnColaAux(c,clave,resultado,aux);
    reencolar(c,aux);
    return resultado;

}

int main()
{
    // Pila pilaElementos = rellenarPila(9);
    // int clave = 1;
    // printf("--------PILA ANTES DEL PROCESO------\n");
    // p_mostrar(pilaElementos);
    // printf("--------------------------------\n");
    // Lista resultadop1 = claveEnPila(pilaElementos,clave);
    // l_mostrar(resultadop1);
    // printf("--------PILA DESPUES DEL PROCESO------\n");
    // p_mostrar(pilaElementos);
    // printf("--------------------------------\n");
    // Lista listaEle = rellenarLista(5);
    // printf("--------LISTA Antes DEL PROCESO------\n");
    // l_mostrar(listaEle);
    // printf("--------------------------------\n");
    // Lista resultado = posiciones(listaEle, 1);
    // l_mostrar(resultado);
    // printf("--------LISTA DESPUES DEL PROCESO------\n");
    // l_mostrar(listaEle);
    // printf("--------------------------------\n");

    // Cola colaElementos = rellenarCola(9);
    // int clave = 1;
    // printf("--------COLA ANTES DEL PROCESO------\n");
    // c_mostrar(colaElementos);
    // printf("--------------------------------\n");
    // Lista resultadop1 = claveEnCola(colaElementos,clave);
    // l_mostrar(resultadop1);
    // printf("--------COLA DESPUES DEL PROCESO------\n");
    // c_mostrar(colaElementos);
    // printf("--------------------------------\n");

    Cola colaElementos = rellenarCola(9);
    int clave = 1;
    printf("--------COLA ANTES DEL PROCESO------\n");
    c_mostrar(colaElementos);
    printf("--------------------------------\n");
    Lista resultadop2b = posicionesEnCola(colaElementos,clave);
    l_mostrar(resultadop2b);
    printf("--------COLA DESPUES DEL PROCESO------\n");
    c_mostrar(colaElementos);
    printf("--------------------------------\n");

    
    return 0;
}
