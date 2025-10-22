#include "grafos.h"

void leer_archivo_grafo(char *file_name, char *V, int *n_vertices, Arista *E, int *n_aristas) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    char line[256];
    int vertice_line = 1;

    while (fgets(line, 256, file) != NULL) {
        if (strspn(line, " \t\n\r") == strlen(line)) continue;

        if (vertice_line) {
            leer_vertice(line, n_vertices, V);
            vertice_line = 0;
        }
        else {
            leer_arista(line, n_aristas, E);
        }
    }

    fclose(file);
}

void leer_vertice(char *line, int *n_vertices, char *V) {
    line[strcspn(line, "\n")] = 0;
    char *token = strtok(line, ", ");

    while (token != NULL) {
        if (strlen(token) == 1) {
            V[*n_vertices] = token[0];
            //printf("Guardando vertice: %c\n", V[*n_vertices]);
            (*n_vertices)++;
        }
        token = strtok(NULL, ", ");
    }
}

void leer_arista(char *line, int *n_aristas, Arista *E) {
    char u, v;
    int leidos = sscanf(line, " %c , %c ", &u, &v);

    if (leidos == 2) {
        E[*n_aristas].u = u;
        E[*n_aristas].v = v;
        //printf("Guardando Arista: {%c, %c}\n", u, v);
        (*n_aristas)++;
    }
}