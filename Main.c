#include "grafos.h"

int get_indice_vertice(char v, int n_vertices, char *vertices_arr) {
    for (int i = 0; i < n_vertices; i++) {
        if (vertices_arr[i] == v) return i;
    }
    return -1;
}

//Inicializar matriz de adyacencia
void inicializar_adyacencia(int adyacencia[][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            adyacencia[i][j] = 0;
        }
    }
}

void crear_matriz_adyacencia(
    int n_vertices,
    int n_aristas,
    char *vertices_arr,
    Arista *aristas_arr,
    int m_adyacencia[][MAX_VERTICES],
    int dirigido
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
    char *vertices_arr, int *n_vertices,
    int m_adyacencia[][MAX_VERTICES]
) {
    inicializar_adyacencia(m_adyacencia);

    *n_vertices = n_vertices_G;
    memcpy(vertices_arr, vertices_G, n_vertices_G * sizeof(char));

    crear_matriz_adyacencia(
        n_vertices_G,
        n_aristas_G,
        vertices_G,
        aristas_G,
        m_adyacencia,
        0
    );
}

void imprimir_grafo(int n_vertices, char *vertices_arr, int matriz_adyacencia[][MAX_VERTICES]) {
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
            printf("%d  ", matriz_adyacencia[i][j]);
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
    
    if (index_inicial >= 0 && index_inicial < n) {
        distancia[index_inicial] = 0;
    }
}


int main(){
    char vertices[MAX_VERTICES];
    int matriz_adyacencia[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;

    char *vertices_G;
    Arista *aristas_G;
    int n_vertices_G;
    int n_aristas_G;

    set_tipo_grafo(2, &vertices_G, &n_vertices_G, &aristas_G, &n_aristas_G);
    crear_grafo(
        vertices_G, n_vertices_G,
        aristas_G, n_aristas_G,
        vertices, &num_vertices,
        matriz_adyacencia
    );

    imprimir_grafo(num_vertices, vertices, matriz_adyacencia);

    int distancia[MAX_VERTICES];
    bool visto[MAX_VERTICES];

    int s_index = 3;

    inicializar_dijkstra(num_vertices, distancia, visto, s_index);
    algoritmo(num_vertices, visto, distancia, matriz_adyacencia);

    for (int i = 0; i < num_vertices; i++) {
        printf("%c: %d\n", vertices[i], distancia[i]);
    }
    return 0;
}
