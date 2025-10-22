#include "grafos.h"

int main(int argc, char *argv[]) {
    char V[MAX_VERTICES];
    Arista E[MAX_ARISTAS];
    int n_vertices_G = 0;
    int n_aristas_G = 0;
    int matriz_adyacencia[MAX_VERTICES][MAX_VERTICES];
    bool dirigido = false;

    if (argc < 4) {
        printf("Uso: ./path <v_inicial> <v_final> <nombre_grafo>\n");
        return 1;
    }

    // Determinar si es orientado
    if (strstr(argv[3], "orientado") != NULL) {
        dirigido = true;
    }

    // Nombre del grafo
    char file_name[MAX_LENGTH];
    snprintf(file_name, MAX_LENGTH, "grafos/%s.txt", argv[3]);

    ejecutar_programa(
        file_name,
        V, &n_vertices_G, E, &n_aristas_G,
        matriz_adyacencia, dirigido,
        argv[1], argv[2]
    );

    return 0;
}