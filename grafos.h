#ifndef GRAFOS_H
#define GRAFOS_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


#define MAX_VERTICES 20
#define MAX_ARISTAS 50

typedef struct {
    char u;
    char v;
} Arista;

typedef int FilaMatriz[MAX_VERTICES];

void leer_grafo(char *file_name, char *V, int *n_vertices, Arista *E, int *n_aristas);
void leer_vertice(char *line, int *n_vertices, char *V);
void leer_arista(char *line, int *n_aristas, Arista *E);

int get_indice_vertice(char v, int n_vertices, char *vertices_arr);
int minima_distancia(int n, bool *visto, int *distancia);
bool es_vecino(int index_u, int index_v, FilaMatriz *m_adyacencia);
void algoritmo(int n, bool *visto, int *distancia, FilaMatriz *m_adyacencia);

void set_tipo_grafo(
    int tipo,
    char **vertice_arr,
    int *n_vertices,
    Arista **aristas_arr,
    int *n_aristas
);

#endif