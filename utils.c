#include "grafos.h"

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

    //imprimir_grafo(V, *n_vertices, M_adyacencia);
    dijkstra(V, *n_vertices, v_inicial, v_final, M_adyacencia);
}

bool leer_args_entrada(int argc, char *argv[], char *file_name, bool *dirigido) {
    // Verificación de los argumentos de entrada
    if (argc < 4) {
        printf("Uso: ./path <v_inicial> <v_final> <nombre_grafo>\n");
        return false;
    }

    // Determinar si el formato de vertices es correcto
    if (strlen(argv[1]) != 1 || strlen(argv[2]) != 1) {
        printf("Error: Formato de vertices incorrecto (ej: a, h).\n");
        return false;
    }

    // Determinar si es orientado
    if (strstr(argv[3], "_o") != NULL) {
        *dirigido = true;
    }

    // Encontrar archivo del grafo ingresado
    snprintf(file_name, MAX_LENGTH, "grafos/%s.txt", argv[3]);

    return true;
}