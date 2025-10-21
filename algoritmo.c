#include "grafos.h"

#define INF INT_MAX
#define PESO 1

int minima_distancia(int n, bool *visto, int *distancia) {
    int min_distancia = INF;
    int u = -1;

    for (int i = 0; i < n; i++) {
        if (!visto[i] && distancia[i] < min_distancia) {
            min_distancia = distancia[i];
            u = i;
        }
    }

    return u;
}

bool es_vecino(int index_u, int index_v, int matriz_adyacencia[][MAX_VERTICES]) {
    return matriz_adyacencia[index_u][index_v] == 1;
}

void algoritmo(int n, bool *visto, int *distancia, int matriz_adyacencia[][MAX_VERTICES]) {
    while (true) {
        int u = minima_distancia(n, visto, distancia);
        if (u == -1)
            break;

        visto[u] = true;

        for (int v = 0; v < n; v++) {
            if (es_vecino(u, v, matriz_adyacencia)) {
                if (distancia[v] > distancia[u] + PESO) {
                    distancia[v] = distancia[u] + PESO;
                }
            }
        }
    }
}
