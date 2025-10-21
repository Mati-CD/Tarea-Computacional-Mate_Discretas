#ifndef GRAFOS_H
#define GRAFOS_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


#define MAX_VERTICES 20
#define MAX_LONGITUD_NOMBRE 10

typedef struct {
    char u;
    char v;
} Arista;

int minima_distancia(int n, bool *visto, int *distancia);
bool es_vecino(int index_u, int index_v, int matriz_adyacencia[][MAX_VERTICES]);
void algoritmo(int n, bool *visto, int *distancia, int matriz_adyacencia[][MAX_VERTICES]);

void set_tipo_grafo(
    int tipo,
    char **vertice_arr,
    int *n_vertices,
    Arista **aristas_arr,
    int *n_aristas
);

#endif