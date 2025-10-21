#include "grafos.h"

/**
 * 
 * Grafo Arbol
 * 
 */
static char VERTICES_G_ARBOL[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'
};
static int N_VERTICES_ARBOL = sizeof(VERTICES_G_ARBOL) / sizeof(char);

static Arista ARISTAS_G_ARBOL[] = {
    {'a', 'b'}, {'a', 'c'}, {'b', 'd'}, {'d', 'h'}, {'d', 'i'},
    {'c', 'e'}, {'c', 'f'}, {'c', 'g'}, {'g', 'l'}, {'f', 'j'}, 
    {'f', 'k'}
};
static int N_ARISTAS_ARBOL = sizeof(ARISTAS_G_ARBOL) / sizeof(Arista);

/**
 * 
 * Grafo Planar
 * 
 */
static char VERTICES_G_PLANAR[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'
};
static int N_VERTICES_PLANAR = sizeof(VERTICES_G_PLANAR) / sizeof(char);

static Arista ARISTAS_G_PLANAR[] = {
    {'a', 'b'}, {'a', 'h'}, {'b', 'h'}, {'b', 'd'}, {'b', 'c'},
    {'c', 'd'}, {'d', 'i'}, {'d', 'f'}, {'d', 'e'}, {'e', 'f'}, 
    {'f', 'i'}, {'f', 'h'}, {'f', 'g'}, {'g', 'h'}
};
static int N_ARISTAS_PLANAR = sizeof(ARISTAS_G_PLANAR) / sizeof(Arista);

 /**
  * 
  * Grafo Euleriano
  * 
  */
 static char VERTICES_G_EULERIANO[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'
};
static int N_VERTICES_EULERIANO = sizeof(VERTICES_G_EULERIANO) / sizeof(char);

static Arista ARISTAS_G_EULERIANO[] = {
    {'a', 'b'}, {'a', 'h'}, {'b', 'c'}, {'b', 'j'}, {'b', 'h'},
    {'c', 'j'}, {'c', 'd'}, {'c', 'e'}, {'d', 'j'}, {'d', 'i'}, 
    {'d', 'e'}, {'e', 'j'}, {'e', 'i'}, {'e', 'f'}, {'e', 'g'},
    {'f', 'i'}, {'f', 'h'}, {'f', 'g'}, {'g', 'i'}, {'g', 'h'},
    {'h', 'i'}, {'h', 'j'}, {'i', 'j'}
};
static int N_ARISTAS_EULERIANO = sizeof(ARISTAS_G_EULERIANO) / sizeof(Arista);

/**
 * Funciones
 */

void get_tipo_grafo(
    int tipo,
    char **vertice_arr,
    int *n_vertices,
    Arista **aristas_arr,
    int *n_aristas
) {
    switch (tipo) {
        case 1:
            *vertice_arr = VERTICES_G_ARBOL;
            *n_vertices = N_VERTICES_ARBOL;
            *aristas_arr = ARISTAS_G_ARBOL;
            *n_aristas = N_ARISTAS_ARBOL;
            break;

        case 2:
            *vertice_arr = VERTICES_G_PLANAR;
            *n_vertices = N_VERTICES_PLANAR;
            *aristas_arr = ARISTAS_G_PLANAR;
            *n_aristas = N_ARISTAS_PLANAR;
            break;

        case 3:
            *vertice_arr = VERTICES_G_EULERIANO;
            *n_vertices = N_VERTICES_EULERIANO;
            *aristas_arr = ARISTAS_G_EULERIANO;
            *n_aristas = N_ARISTAS_EULERIANO;
            break;
        
        default:
            break;
    }
}