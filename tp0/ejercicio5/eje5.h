#include <stdbool.h>
#include <stdio.h>

const CANT_PISOS = 8;

const CANT_DEPTOS = 5;

const CANT_VIVIENDAS = CANT_PISOS * CANT_DEPTOS;

struct Vivienda {
 short piso;
 char depto;
};

int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPTOS]);
int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPTOS]);
float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPTOS]);
struct Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPTOS]); 