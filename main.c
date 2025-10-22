#include "grafos.h"

int main(int argc, char *argv[]) {
    char file_name[MAX_LENGTH];
    char V[MAX_VERTICES];
    Arista E[MAX_ARISTAS];
    int matriz_adyacencia[MAX_VERTICES][MAX_VERTICES];
    int n_vertices_G = 0;
    int n_aristas_G = 0;
    bool dirigido = false;

    if (!leer_args_entrada(argc, argv, file_name, &dirigido)) {
        return 1;
    }

    ejecutar_programa(
        file_name,
        V, &n_vertices_G, E, &n_aristas_G,
        matriz_adyacencia, dirigido,
        argv[1], argv[2]
    );

    return 0;
}