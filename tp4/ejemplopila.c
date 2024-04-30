#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "ejemplos.h"
/*
char* inverrtirPalabra(char palabra[]){
    char* inversa = NULL;
    TipoElemento x;
    Pila pila = p_crear();
    int i = 0;
    while(palabra[i] != 0){
        x = te_crear(palabra[i]);
        p_apilar(pila,x);
        i++;
    }
    if (i > 0)
    {
        inversa = (char *)calloc(i + 1, sizeof(char)); //reservo lonigtud + 1, porque son la cantidad de caracteres
        inversa[i] = 0;
        i = 0; //guardo en el ultimo indice 0, porque van a tener la misma cantidad de elementos.
        while (!p_es_vacia(pila))
        {
            x = p_tope(pila);
            p_desapilar(pila);
            inversa[i]= x->clave;
            i++;
        }
    }
    return(inversa);
}
*/

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

void rellenarCola(Cola cola, int cantidadDeElementos)
{
    TipoElemento elemento;
    int clave;
    for (int i = 0; i < cantidadDeElementos; i++)
    {

        printf("Ingrese la clave: ");
        while (scanf("%d", &clave) != 1)
        {
            printf("\nError: Ingresa un número válido: ");
            while (getchar() != '\n')
            {
                // clear input buffer
            }
        }
        elemento = te_crear(clave);
        c_encolar(cola, elemento);
    }
}

// EJEMPLO PARCIAL
// ComplejidadLineal = O(n)
/*
Lista listaInvertida(Lista l1)
{
    if (l_es_vacia(l1))
    {
        printf("la lista esta vacia\n");
        return l1;
    }
    Pila paux = p_crear(); // Pila para invertir elementos;
    Lista resultado = l_crear();
    Iterador itel1 = iterador(l1);
    TipoElemento ele1;
    while (hay_siguiente(itel1))
    {
        ele1 = siguiente(itel1);
        p_apilar(paux, ele1);
    }
    // desapiloPara dar vuelta la lista
    while (!p_es_vacia(paux))
    {
        ele1 = p_desapilar(paux);
        l_agregar(resultado, ele1);
    }
    return resultado;
}

Lista listaInvertida(Lista L)
{
    if (l_es_vacia(L))
    {
        printf("La lista esta vacia\n");
        return L;
    }
    TipoElemento elem_act;
    Lista L1 = l_crear();
    Iterador itL = iterador(L);
    while (hay_siguiente(itL))
    {
        elem_act = siguiente(itL);
        l_insertar(L1, elem_act, 1);
    }
    return L1;
}
// COMPLEJIDAD O(n)
Lista devolverElementos(Lista l1)
{
    if (l_es_vacia(l1))
    {
        printf("La lista esta vacia\n");
        return l1;
    }
    TipoElemento eleMa, eleSac;
    Lista resultado = l_crear();
    Iterador itl1 = iterador(l1);
    bool flag = false;
    while (hay_siguiente(itl1))
    {
        eleSac = siguiente(itl1);
        if (!flag)
        {
            eleMa = eleSac;
            flag = true;
        }
        else
        {
            if (eleSac->clave == eleMa->clave)
            {
                l_agregar(resultado, eleMa);
            }
            else if (eleSac->clave > eleMa->clave)
            {
                l_borrar(resultado, eleMa->clave);
                eleMa = eleSac;
                l_agregar(resultado, eleMa);
            }
        }
    }
    return resultado;
}

*/

TipoElemento c_ej7_atenderclientesAux(TipoElemento ele, int tiempoatencion, int numeroDeCola, int pos)
{
    ele->clave -= tiempoatencion;
    TipoElemento eleCreado = ele;
    if (ele->clave < tiempoatencion)
    {
        eleCreado = te_crear(numeroDeCola);
        eleCreado->valor = (char *)malloc(20 * sizeof(char));
        sprintf(eleCreado->valor, "Cliente:%d Cola:%d",pos, numeroDeCola);
    }
    return eleCreado;
}

Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion)
{
    Cola resu = c_crear();
    TipoElemento ele;
    int pos1 = 1, pos2 = 1, pos3 = 1;
    bool flag = true;
    while (flag)
    {
        if (!c_es_vacia(c1))
        {
            ele = c_ej7_atenderclientesAux(c_recuperar(c1), tiempoatencion, 1, pos1);
            if (ele->clave < tiempoatencion)
            {
                printf("%s\n", (char *)ele->valor);
                c_encolar(resu, ele);
                ele = c_desencolar(c1);
                pos1++;
            }
        }

        if (!c_es_vacia(c2))
        {
            ele = c_ej7_atenderclientesAux(c_recuperar(c2), tiempoatencion, 2, pos2);
            if (ele->clave < tiempoatencion)
            {
                printf("%s\n", (char *)ele->valor);
                c_encolar(resu, ele);
                ele = c_desencolar(c2);
                pos2++;
            }
        }
        
        if (!c_es_vacia(c3))
        {
            ele = c_ej7_atenderclientesAux(c_recuperar(c3), tiempoatencion, 3, pos3);
            if (ele->clave < tiempoatencion)
            {
                printf("%s\n", (char *)ele->valor);
                c_encolar(resu, ele);
                ele = c_desencolar(c3);
                pos3++;
            }
        }

        if (c_es_vacia(c1) && c_es_vacia(c2) && c_es_vacia(c3))
        {
            flag = false;
        }
    }
    return resu;
}


int main()
{
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();
    rellenarCola(c1, 2);
    printf("-----------\n");
    rellenarCola(c2, 2);
    printf("-----------\n");
    rellenarCola(c3, 2);
    printf("-----------\n");
    Cola resu = c_ej7_atenderclientes(c1,c2,c3, 7);
    printf("-----------\n");
    c_mostrar(resu);
    return 0;
}
/*
int main()
{
    Lista l1 = l_crear();
    l1 = rellenarLista(9);
    Lista resultado1 = listaInvertida(l1);
    printf("-------------------------------\n");
    l_mostrar(l1);
    printf("---------RESU1-----------\n");
    l_mostrar(resultado1);
    printf("-------------------------------\n");
    Lista resultado2 = devolverElementos(l1);
    printf("-------------------------------\n");
    l_mostrar(l1);
    printf("------------RESU2----------\n");
    l_mostrar(resultado2);
    printf("-------------------------------\n");

    Cola c1 = c_crear();
    rellenarCola(c1, 10);
    Lista resultado = recur(c1, 1);
    printf("-------------------------------\n");
    c_mostrar(c1);
    printf("-------------------------------\n");
    l_mostrar(resultado);  
    return 0;
}
*/