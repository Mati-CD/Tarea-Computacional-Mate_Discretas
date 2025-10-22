#include "grafos.h"

int get_indice_vertice(char v, int n_vertices, char *V) {
    for (int i = 0; i < n_vertices; i++) {
        if (V[i] == v) return i;
    }
    return -1;
}

void crear_matriz_adyacencia(
    char *V, int n_vertices, Arista *E, int n_aristas,
    FilaMatriz *M_adyacencia, bool dirigido
) {

    // Inicializar matriz de adyacencia
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            M_adyacencia[i][j] = 0;
        }
    }

    // Mapear aristas a la matriz
    for (int i = 0; i < n_aristas; i++) {
        char v1 = E[i].u;
        char v2 = E[i].v;
        
        int v_index1 = get_indice_vertice(v1, n_vertices, V);
        int v_index2 = get_indice_vertice(v2, n_vertices, V);
        
        if (v_index1 != -1 && v_index2 != -1) {
            M_adyacencia[v_index1][v_index2] = 1;
            if (!dirigido) {
                M_adyacencia[v_index2][v_index1] = 1;
            }
        }
    }
}

void imprimir_grafo(char *V, int n_vertices, FilaMatriz *M_adyacencia) {
    printf("\nGrafo creado. Los vertices son: %d\n", n_vertices);

    printf("     ");
    for (int j = 0; j < n_vertices; j++) {
        printf("%c  ", V[j]);
    }
    printf("\n");
    
    // Imprimir matriz de adyacencia
    for (int i = 0; i < n_vertices; i++) {
        printf("%c |  ", V[i]);
        for (int j = 0; j < n_vertices; j++) {
            printf("%d  ", M_adyacencia[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ejecutar_programa(
    char *file_name,
    char *V, int *n_vertices, Arista *E, int *n_aristas,
    FilaMatriz *M_adyacencia, bool dirigido,
    char *v_inicial_c, char *v_final_c
) {

    leer_archivo_grafo(file_name, V, n_vertices, E, n_aristas);
    crear_matriz_adyacencia(V, *n_vertices, E, *n_aristas, M_adyacencia, dirigido);

    int v_inicial = get_indice_vertice(*v_inicial_c, *n_vertices, V);
    int v_final = get_indice_vertice(*v_final_c, *n_vertices, V);

    imprimir_grafo(V, *n_vertices, M_adyacencia);
    dijkstra(V, *n_vertices, v_inicial, v_final, M_adyacencia);
}