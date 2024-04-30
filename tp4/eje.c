#include <stdio.h>
#include <stdlib.h>
#include "./libs/colas/colas.h"
#include "./libs/pilas/pilas.h"
#include "./libs/listas/listas.h"
#include <stdbool.h>


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

TipoElemento c_ej7_atenderclientesAux(TipoElemento ele, int tiempoatencion, int numeroDeCola, int pos)
{
    ele->clave -= tiempoatencion;
    TipoElemento eleCreado = ele;
    if (ele->clave < tiempoatencion)
    {
        ele = te_crear(numeroDeCola);
        ele->valor = (char *)malloc(20 * sizeof(char));
        sprintf(ele->valor, "Cliente :%d Cola:%d",pos, numeroDeCola);
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
                ele = c_desencolar(c1);
                c_encolar(resu, ele);
                printf("Cola 1, Cliente %d\n", pos1);
                pos1++;
            }
        }

        if (!c_es_vacia(c2))
        {
            ele = c_ej7_atenderclientesAux(c_recuperar(c2), tiempoatencion, 2, pos2);
            if (ele->clave < tiempoatencion)
            {
                ele = c_desencolar(c2);
                c_encolar(resu, ele);
                printf("Cola 1, Cliente %d\n", pos2);
                pos2++;
            }
        }
        
        if (!c_es_vacia(c3))
        {
            ele = c_ej7_atenderclientesAux(c_recuperar(c3), tiempoatencion, 2, pos2);
            if (ele->clave < tiempoatencion)
            {
                ele = c_desencolar(c3);
                c_encolar(resu, ele);
                printf("Cola 1, Cliente %d\n", pos3);
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
    rellenarCola(c1, 3);
    printf("-----------\n");
    rellenarCola(c2, 2);
    printf("-----------\n");
    rellenarCola(c3, 4);
    printf("-----------\n");
    Cola resu = c_ej7_atenderclientes(c1,c2,c3, 5);

    return 0;
}
