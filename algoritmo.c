#include "grafos.h"

int minima_distancia(int n_vertices, bool *visto, int *distancia) {
    int min_distancia = INF;
    int u = -1;

    for (int i = 0; i < n_vertices; i++) {
        if (!visto[i] && distancia[i] < min_distancia) {
            min_distancia = distancia[i];
            u = i;
        }
    }

    return u;
}

bool es_vecino(int index_u, int index_v, FilaMatriz *m_adyacencia) {
    return m_adyacencia[index_u][index_v] == 1;
}

void imprimir_camino(int index_i, int index_f, int *padre, char *V) {
    // Caso: Vertice inicial
    if (index_f == index_i) {
        printf("%c", V[index_i]);
        return;
    }

    // Llamada recursiva
    imprimir_camino(index_i, padre[index_f], padre, V);

    // Printear vertice actual
    printf(" -> %c", V[index_f]);
}

void dijkstra(char *V, int n_vertices, int index_i, int index_f, FilaMatriz *m_adyacencia) {
    int distancia[MAX_VERTICES];
    bool visto[MAX_VERTICES];
    int padre[MAX_VERTICES];
    
    for (int i = 0; i < n_vertices; i++) {
        distancia[i] = INT_MAX; 
        visto[i] = false;
        padre[i] = -1;
    }
    distancia[index_i] = 0;
    
    while (true) {
        int u = minima_distancia(n_vertices, visto, distancia);
        if (u == -1) break;

        visto[u] = true;

        for (int v = 0; v < n_vertices; v++) {
            if (es_vecino(u, v, m_adyacencia)) {
                if (distancia[v] > distancia[u] + PESO) {
                    distancia[v] = distancia[u] + PESO;
                    padre[v] = u;
                }
            }
        }
    }

    // Printear distancias
    for (int i = 0; i < n_vertices; i++) {
        printf("%c: %d\n", V[i], distancia[i]);
    }

    // Printear camino más corto
    printf("Camino más corto desde '%c' hasta '%c':\n", V[index_i], V[index_f]);
    imprimir_camino(index_i, index_f, padre, V);
    printf("\n");
}
