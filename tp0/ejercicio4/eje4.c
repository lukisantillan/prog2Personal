#include <math.h>
#include "eje4.h"
/*
// ORDENAMIENTO BURBUJA
struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[]){
    struct Jugador aux;
    for (int i = 0; i < CANT_JUGADORES; i++)
    {
        for (int j = 0; j < CANT_JUGADORES-1; j++)
        {
            if (equipo[j].partidosJugados < equipo[j+1].partidosJugados)
            {
                aux = equipo[j];
                equipo[j] = equipo[j + 1];
                equipo[j + 1]= aux;
            }
        }
    }
    return equipo;
}
*/
struct Jugador *  copiaEquipo(struct Jugador equipo[]){

    struct Jugador* eqCopia = (struct Jugador*) malloc(11 * sizeof(struct Jugador));

    int i;
    for (i = 0; i < 11; i++)
    {
        (eqCopia + i)->edad = equipo[i].edad; // es equivalente a eqCopia[i].edad = equipo[i].edad
        strcpy((eqCopia + i)->nombre, equipo[i].nombre);
        (eqCopia + i)->partidosJugados = equipo[i].partidosJugados;
    }
    
}

int CompararCantPartidos(const void * vj1, const void * vj2){
    struct Jugador* pj1 = (struct jugador *) vj1;    //Casting : interpretar un parametro generico como puntero
    struct Jugador* pj2 = (struct Jugador *) vj2;

    return ((*pj1).partidosJugados - (*pj2).partidosJugados);
}

struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[]){
    struct Jugador* eqOrdenado;

    eqOrdenado = copiaEquipo(equipo);
    qsort(eqOrdenado,11, sizeof(struct Jugador), CompararCantPartidos);
}

// B


struct Jugador *jugadoresOrdenadosEdad(struct Jugador equipo[]){

    struct Jugador aux;
    
    for (int i = 0; i < CANT_JUGADORES; i++)
    {
        for (int j = 0; j < CANT_JUGADORES-1; j++)
        {
            if (equipo[j].edad > equipo[j+1].edad)
            {
                aux = equipo[j+1];
                equipo[j+1] = equipo[j];
                equipo[j]= aux;
            }
        }
    }
    return equipo;
}

float promedioDePartidosJugados(struct Jugador equipo[], int edad){
    int cantidadDePartidos = 0;
    int cantidadDeJugadores = 0;
    for (int i = 0; i <= CANT_JUGADORES; i++)
    {
        if (equipo[i].edad == edad)
        {
            cantidadDePartidos += equipo[i].partidosJugados;
            cantidadDeJugadores++;
        }
    }
    float resultado = cantidadDePartidos / cantidadDeJugadores;
    return resultado;
}

/*
qsort recibe el arreglo a ser ordenado, la cantidad de elementos,  cantidad de bytes de cada elemento del array, funcion que es la que define el criterio
de ordenamiento,

int CompararCantPartidos(const void * vj1, const void * vj2){
    struct Jugador* pj1 = (struct jugador *) vj1;    //Casting : interpretar un parametro generico como puntero
    struct Jugador* pj2 = (struct Jugador *) vj2;

    return ((*pj1).partidosJugados - (*pj2).partidosJugados);
}


malloc sirve para pedirle al sistema operativo que reserve un area de memoria para 
un nuevo arreglo de estructura jugador, como lo hace? malloc es una funcion que le pide 
reservar el area de memoria y el sistema devuelve el puntero al primer byte de esa area
de memoria
*/