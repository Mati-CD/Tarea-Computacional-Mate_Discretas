#include "grafos.h"

/**
 * 
 * Grafo Arbol
 * 
 */
static char VERTICES_ARBOL[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'
};
static int N_VERTICES_ARBOL = sizeof(VERTICES_ARBOL) / sizeof(char);

static Arista ARISTAS_ARBOL[] = {
    {'a', 'b'}, {'a', 'c'}, {'b', 'd'}, {'d', 'h'}, {'d', 'i'},
    {'c', 'e'}, {'c', 'f'}, {'c', 'g'}, {'g', 'l'}, {'f', 'j'}, 
    {'f', 'k'}
};
static int N_ARISTAS_ARBOL = sizeof(ARISTAS_ARBOL) / sizeof(Arista);

/**
 * 
 * Grafo Planar
 * 
 */
static char VERTICES_PLANAR[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'
};
static int N_VERTICES_PLANAR = sizeof(VERTICES_PLANAR) / sizeof(char);

static Arista ARISTAS_PLANAR[] = {
    {'a', 'b'}, {'a', 'h'}, {'b', 'h'}, {'b', 'd'}, {'b', 'c'},
    {'c', 'd'}, {'d', 'i'}, {'d', 'f'}, {'d', 'e'}, {'e', 'f'}, 
    {'f', 'i'}, {'f', 'h'}, {'f', 'g'}, {'g', 'h'}
};
static int N_ARISTAS_PLANAR = sizeof(ARISTAS_PLANAR) / sizeof(Arista);

 /**
  * 
  * Grafo Euleriano
  * 
  */
static char VERTICES_EULERIANO[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'
};
static int N_VERTICES_EULERIANO = sizeof(VERTICES_EULERIANO) / sizeof(char);

static Arista ARISTAS_EULERIANO[] = {
    {'a', 'b'}, {'a', 'h'}, {'b', 'c'}, {'b', 'j'}, {'b', 'h'},
    {'c', 'j'}, {'c', 'd'}, {'c', 'e'}, {'d', 'j'}, {'d', 'i'}, 
    {'d', 'e'}, {'e', 'j'}, {'e', 'i'}, {'e', 'f'}, {'e', 'g'},
    {'f', 'i'}, {'f', 'h'}, {'f', 'g'}, {'g', 'i'}, {'g', 'h'},
    {'h', 'i'}, {'h', 'j'}, {'i', 'j'}
};
static int N_ARISTAS_EULERIANO = sizeof(ARISTAS_EULERIANO) / sizeof(Arista);

/**
 * 
 * Grafo Arbol Orientado 1
 * 
 */
static char VERTICES_ARBOL_ORIENTADO_1[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'
};

static int N_VERTICES_ARBOL_ORIENTADO_1 = sizeof(VERTICES_ARBOL_ORIENTADO_1) / sizeof(char);

static Arista ARISTAS_ARBOL_ORIENTADO_1[] = {
    {'a', 'b'}, {'a', 'c'}, {'b', 'd'}, {'d', 'h'}, {'i', 'd'},
    {'c', 'e'}, {'f', 'c'}, {'e', 'g'}, {'l', 'g'}, {'f', 'j'}, 
    {'k', 'f'}
};

static int N_ARISTAS_ARBOL_ORIENTADO_1 = sizeof(ARISTAS_ARBOL_ORIENTADO_1) / sizeof(Arista);

/**
 * 
 * Grafo Planar Orientado 1
 * 
 */
static char VERTICES_PLANAR_ORIENTADO_1[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'
};

static int N_VERTICES_PLANAR_ORIENTADO_1 = sizeof(VERTICES_PLANAR_ORIENTADO_1) / sizeof(char);

static Arista ARISTAS_PLANAR_ORIENTADO_1[] = {
    {'a', 'b'}, {'h', 'a'}, {'b', 'h'}, {'b', 'd'}, {'c', 'b'},
    {'c', 'd'}, {'d', 'i'}, {'d', 'f'}, {'e', 'd'}, {'e', 'f'},
    {'f', 'i'}, {'h', 'f'}, {'f', 'g'}, {'g', 'h'}
};

static int N_ARISTAS_PLANAR_ORIENTADO_1 = sizeof(ARISTAS_PLANAR_ORIENTADO_1) / sizeof(Arista);

/**
 * 
 * Grafo Euleriano Orientado 1
 * 
 */
static char VERTICES_EULERIANO_ORIENTADO_1[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'
};
static int N_VERTICES_EULERIANO_ORIENTADO_1 = sizeof(VERTICES_EULERIANO_ORIENTADO_1) / sizeof(char);

static Arista ARISTAS_EULERIANO_ORIENTADO_1[] = {
    {'a', 'b'}, {'h', 'a'}, {'b', 'c'}, {'b', 'j'}, {'h', 'b'},
    {'c', 'j'}, {'c', 'd'}, {'e', 'c'}, {'d', 'f'}, {'i', 'd'},
    {'d', 'e'}, {'e', 'j'}, {'i', 'e'}, {'e', 'f'}, {'e', 'g'},
    {'f', 'i'}, {'h', 'f'}, {'f', 'g'}, {'g', 'i'}, {'g', 'h'},
    {'h', 'i'}, {'j', 'h'}, {'i', 'j'}
};
static int N_ARISTAS_EULERIANO_ORIENTADO_1 = sizeof(ARISTAS_EULERIANO_ORIENTADO_1) / sizeof(Arista);


/**
 * Funciones
 */

void set_tipo_grafo(
    int tipo,
    char **vertice_arr,
    int *n_vertices,
    Arista **aristas_arr,
    int *n_aristas
) {

    switch (tipo) {
        case 0:
            *vertice_arr = VERTICES_ARBOL;
            *n_vertices = N_VERTICES_ARBOL;
            *aristas_arr = ARISTAS_ARBOL;
            *n_aristas = N_ARISTAS_ARBOL;
            break;

        case 1:
            *vertice_arr = VERTICES_PLANAR;
            *n_vertices = N_VERTICES_PLANAR;
            *aristas_arr = ARISTAS_PLANAR;
            *n_aristas = N_ARISTAS_PLANAR;
            break;

        case 2:
            *vertice_arr = VERTICES_EULERIANO;
            *n_vertices = N_VERTICES_EULERIANO;
            *aristas_arr = ARISTAS_EULERIANO;
            *n_aristas = N_ARISTAS_EULERIANO;
            break;

        case 3:
            *vertice_arr = VERTICES_ARBOL_ORIENTADO_1;
            *n_vertices = N_VERTICES_ARBOL_ORIENTADO_1;
            *aristas_arr = ARISTAS_ARBOL_ORIENTADO_1;
            *n_aristas = N_ARISTAS_ARBOL_ORIENTADO_1;
            break;

        case 4:
            *vertice_arr = VERTICES_PLANAR_ORIENTADO_1;
            *n_vertices = N_VERTICES_PLANAR_ORIENTADO_1;
            *aristas_arr = ARISTAS_PLANAR_ORIENTADO_1;
            *n_aristas = N_ARISTAS_PLANAR_ORIENTADO_1;
            break;

        case 5:
            *vertice_arr = VERTICES_EULERIANO_ORIENTADO_1;
            *n_vertices = N_VERTICES_EULERIANO_ORIENTADO_1;
            *aristas_arr = ARISTAS_EULERIANO_ORIENTADO_1;
            *n_aristas = N_ARISTAS_EULERIANO_ORIENTADO_1;
            break;
        
        default:
            break;
    }
}