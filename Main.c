#include "grafos.h"

int get_indice_vertice(char v, int n_vertices, char *vertices_arr) {
    for (int i = 0; i < n_vertices; i++) {
        if (vertices_arr[i] == v) return i;
    }
    return -1;
}

//Inicializar matriz de adyacencia
void inicializar_matriz_adyacencia(FilaMatriz *m_adyacencia) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            m_adyacencia[i][j] = 0;
        }
    }
}

void crear_matriz_adyacencia(
    char *vertices_arr, int n_vertices,
    Arista *aristas_arr, int n_aristas,
    FilaMatriz *m_adyacencia, int dirigido
) {

    for (int i = 0; i < n_aristas; i++) {
        char v1 = aristas_arr[i].u;
        char v2 = aristas_arr[i].v;
        
        int v_index1 = get_indice_vertice(v1, n_vertices, vertices_arr);
        int v_index2 = get_indice_vertice(v2, n_vertices, vertices_arr);
        
        if (v_index1 != -1 && v_index2 != -1) {
            m_adyacencia[v_index1][v_index2] = 1;
            if (!dirigido) {
                m_adyacencia[v_index2][v_index1] = 1;
            }
        }
    }
}

void crear_grafo(
    char *vertices_G, int n_vertices_G,
    Arista *aristas_G, int n_aristas_G,
    FilaMatriz *m_adyacencia
) {

    inicializar_matriz_adyacencia(m_adyacencia);

    crear_matriz_adyacencia(
        vertices_G, n_vertices_G,
        aristas_G, n_aristas_G,
        m_adyacencia, 0
    );
}

void imprimir_grafo(int n_vertices, char *vertices_arr, FilaMatriz *m_adyacencia) {
    printf("\nGrafo creado. Los vertices son: %d\n", n_vertices);

    printf("     ");
    for (int j = 0; j < n_vertices; j++) {
        printf("%c  ", vertices_arr[j]);
    }
    printf("\n");
    
    // Imprimir matriz de adyacencia
    for (int i = 0; i < n_vertices; i++) {
        printf("%c |  ", vertices_arr[i]);
        for (int j = 0; j < n_vertices; j++) {
            printf("%d  ", m_adyacencia[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void inicializar_dijkstra(int n, int *distancia, bool *visto, int index_inicial) {
    for (int i = 0; i < n; i++) {
        distancia[i] = INT_MAX; 
        visto[i] = false;
    }
    distancia[index_inicial] = 0;
}



int main() {
    char V[MAX_VERTICES];
    Arista E[MAX_ARISTAS];
    int n_vertices_G = 0;
    int n_aristas_G = 0;

    leer_grafo("grafos/euleriano.txt", V, &n_vertices_G, E, &n_aristas_G);

    int matriz_adyacencia[MAX_VERTICES][MAX_VERTICES];

    crear_grafo(
        V, n_vertices_G,
        E, n_aristas_G,
        matriz_adyacencia
    );

    imprimir_grafo(n_vertices_G, V, matriz_adyacencia);

    int distancia[MAX_VERTICES];
    bool visto[MAX_VERTICES];
    int s_index = 3;

    inicializar_dijkstra(n_vertices_G, distancia, visto, s_index);
    algoritmo(n_vertices_G, visto, distancia, matriz_adyacencia);

    for (int i = 0; i < n_vertices_G; i++) {
        printf("%c: %d\n", V[i], distancia[i]);
    }

    return 0;
}