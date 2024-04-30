#include <stdbool.h>
#include <stdio.h>

// Ejercicio 4

#define TAMANO_STRING 50
#define CANT_JUGADORES 10

struct Jugador {
    char nombre[TAMANO_STRING];
    int edad, partidosJugados;
};

struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[]);

struct Jugador *jugadoresOrdenadosEdad(struct Jugador equipo[]);

float promedioDePartidosJugados(struct Jugador equipo[], int edad);