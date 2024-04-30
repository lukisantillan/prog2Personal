#include <math.h>
#include "eje5.h"


int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPTOS]){
    int cantidadDeHabitantesPiso= 0;
    int piso=0;
    for (int i = 0; i < CANT_PISOS; i++)
    {
        int cantidadDelPiso = 0;
        for (int j = 0; j <CANT_DEPTOS; j++)
        {
            cantidadDelPiso += edificio[i][j];
        }
        if (cantidadDelPiso > cantidadDeHabitantesPiso)
        {
            piso = i+1;
            cantidadDeHabitantesPiso = cantidadDelPiso;
        }
        
    }
    return piso;
}

int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPTOS]){
    int viviendaVacia = 0;
    for (int i = 0; i < CANT_PISOS; i++)
    {
        int cantidadDelPiso = 0;
        for (int j = 0; j <CANT_DEPTOS; j++)
        {
            if (edificio[i][j] == 0)
            {
                viviendaVacia++;
            }
            
        }
    }
    return viviendaVacia;
}

float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPTOS]){
    int cantidadDeHabitantes = 0;
    int cantidadDeViviendas = 0;
    for (int i = 0; i < CANT_PISOS; i++)
    {
        int cantidadDelPiso = 0;
        for (int j = 0; j <CANT_DEPTOS; j++)
        {
            cantidadDeViviendas++;
            cantidadDeHabitantes += edificio[i][j];
        }
    }
    float promedio = cantidadDeViviendas / cantidadDeHabitantes;
    return promedio;
}

struct Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPTOS]){
    struct Vivienda PisoMas;
    int habitantes;
    char deptos[4] = {"A","B","C","D"};
    for (int i = 0; i < CANT_PISOS; i++)
    {
        int actual;
        for (int j = 0; j <CANT_DEPTOS; j++)
        {
            actual = edificio[i][j];
            if (actual > habitantes)
            {
                PisoMas.piso = i+1;
                PisoMas.depto = deptos[j];
            }
        }
    }
    return PisoMas;
}