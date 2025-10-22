#ifndef GRAFOS_H
#define GRAFOS_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 20
#define MAX_ARISTAS 50
#define INF INT_MAX
#define PESO 1

typedef struct {
    char u;
    char v;
} Arista;

typedef int FilaMatriz[MAX_VERTICES];

void leer_archivo_grafo(char *file_name, char *V, int *n_vertices, Arista *E, int *n_aristas);
void leer_vertice(char *line, int *n_vertices, char *V);
void leer_arista(char *line, int *n_aristas, Arista *E);

int get_indice_vertice(char v, int n_vertices, char *vertices_arr);

void imprimir_camino(int index_i, int index_f, int *padre, char *V);
int minima_distancia(int n_vertices, bool *visto, int *distancia);
bool es_vecino(int index_u, int index_v, FilaMatriz *m_adyacencia);
void dijkstra(char *V, int n_vertices, int index_i, int index_f, FilaMatriz *m_adyacencia);

#endif