#include <stdio.h>
#include "eje4.h"
#include <assert.h>

void test_jugadoresOrdenadosPorCantDePartidos()
{
  struct Jugador equipo[CANT_JUGADORES] = {
      {"Messi", 34, 800},
      {"Ronaldo", 37, 900},
      {"Neymar Jr.", 29, 500},
      {"Mbappe", 22, 200},
      {"Lewandowski", 33, 700},
      {"Salah", 29, 400},
      {"De Bruyne", 30, 600},
      {"van Dijk", 30, 400},
      {"Ramos", 35, 650},
      {"Neuer", 35, 800},
};

  struct Jugador *result = jugadoresOrdenadosPorCantDePartidos(equipo);

  for (int i = 0; i < CANT_JUGADORES - 1; i++)
  {
    assert(result[i].partidosJugados >= result[i + 1].partidosJugados);
  }
}

void test_promedioDePartidosJugados()
{
  struct Jugador equipo[CANT_JUGADORES] = {
      {"Messi", 34, 800},
      {"Ronaldo", 37, 900},
      {"Neymar Jr.", 29, 500},
      {"Mbappe", 22, 200},
      {"Lewandowski", 33, 700},
      {"Salah", 29, 400},
      {"De Bruyne", 30, 600},
      {"van Dijk", 30, 400},
      {"Ramos", 35, 650},
      {"Neuer", 35, 800}};

  float result = promedioDePartidosJugados(equipo, 30);
  assert(result == 500.0);

  result = promedioDePartidosJugados(equipo, 35);
  assert(result == 725.0);
}

void test_jugadoresOrdenadosPorEdad()
{
  struct Jugador equipo[CANT_JUGADORES] = {
      {"Messi", 34, 800},
      {"Ronaldo", 37, 900},
      {"Neymar Jr.", 29, 500},
      {"Mbappe", 22, 200},
      {"Lewandowski", 33, 700},
      {"Salah", 29, 400},
      {"De Bruyne", 30, 600},
      {"van Dijk", 30, 400},
      {"Ramos", 35, 650},
      {"Neuer", 35, 800}};

  struct Jugador *result = jugadoresOrdenadosPorEdad(equipo);

  for (int i = 0; i < CANT_JUGADORES - 1; i++)
  {
    assert(result[i].edad <= result[i + 1].edad);
  }
}

int main()
{
    test_jugadoresOrdenadosPorCantDePartidos();
    test_promedioDePartidosJugados();
    test_jugadoresOrdenadosPorEdad();
    return 0;
}
