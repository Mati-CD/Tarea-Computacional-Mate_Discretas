#include "grafos.h"

//Funcion para encontrar el índice de un vertice por nombre
int encontrar_indice_vertice(char vertices[][MAX_LONGITUD_NOMBRE], int num_vertices, char *nombre) {
    for (int i = 0; i < num_vertices; i++) {
        if (strcmp(vertices[i], nombre) == 0) {
            return i;
        }
    }
    return -1;
}

int get_indice_vertice(char v, int n_vertices, char *vertices_arr) {
    for (int i = 0; i < n_vertices; i++) {
        if (vertices_arr[i] == v) return i;
    }
    return -1;
}

//Funcion para agregar un vertice al grafo
int agregar_vertice(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, char *nombre) {
    if (encontrar_indice_vertice(vertices, *num_vertices, nombre) == -1) {
        strcpy(vertices[*num_vertices], nombre);
        (*num_vertices)++;
        return 1;
    }
    return 0;
}

//Funcion para agregar una arista al grafo
void agregar_arista(
    int adyacencia[][MAX_VERTICES],
    char vertices[][MAX_LONGITUD_NOMBRE],
    int num_vertices,
    int dirigido,
    char *v1,
    char *v2
) {
    int indice1 = encontrar_indice_vertice(vertices, num_vertices, v1);
    int indice2 = encontrar_indice_vertice(vertices, num_vertices, v2);
    
    if (indice1 != -1 && indice2 != -1) {
        adyacencia[indice1][indice2] = 1;
        if (!dirigido) {
            adyacencia[indice2][indice1] = 1;
        }
    }
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


/*
void crear_arbol_no_dirigido(char *vertices_arr, int *n_vertices, int m_adyacencia[][MAX_VERTICES]) {
    inicializar_adyacencia(m_adyacencia);
    
    // Agregar vértices
    char vertices_G[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
    char aristas_G[][2] = {
        {'a', 'b'}, {'a', 'c'}, {'b', 'd'}, {'d', 'h'}, {'d', 'i'},
        {'c', 'e'}, {'c', 'f'}, {'c', 'g'}, {'g', 'l'}, {'f', 'j'}, 
        {'f', 'k'}
    };

    int num_vertices = sizeof(vertices_G) / sizeof(vertices_G[0]);;
    int num_aristas = sizeof(aristas_G) / sizeof(aristas_G[0]);;
    *n_vertices = num_vertices;
    memcpy(vertices_arr, vertices_G, num_vertices * sizeof(char));

    crear_matriz_adyacencia(
        num_vertices,
        num_aristas,
        vertices_G,
        aristas_G,
        m_adyacencia,
        0
    );
}
*/

//Crear arbol con orientacion 1
void crear_arbol_orientacion1(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k"};
    for (int i = 0; i < 11; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }

    char *aristas_orientadas[][2] = {
        {"a", "b"}, {"a", "c"}, {"b", "d"}, {"d", "h"}, {"i", "d"},
        {"c", "e"}, {"f", "c"}, {"e", "g"}, {"l", "g"}, {"f", "j"}, 
        {"k", "f"}
    };
    int num_aristas = sizeof(aristas_orientadas) / sizeof(aristas_orientadas[0]);

    for (int i = 0; i < num_aristas; i++) {
        agregar_arista(adyacencia, vertices, *num_vertices, 1, aristas_orientadas[i][0], aristas_orientadas[i][1]);
    }
}

//Crear grafo planar con orientacion 1
void crear_planar_orientacion1(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    for (int i = 0; i < 9; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }

    // DEFINICIÓN DE ARISTAS (Arreglo 2D con orientación Origen -> Destino)
    char *aristas_orientadas[][2] = {
        {"a", "b"}, {"h", "a"}, {"b", "h"}, {"b", "d"}, {"c", "b"},
        {"c", "d"}, {"d", "i"}, {"d", "f"}, {"e", "d"}, {"e", "f"},
        {"f", "i"}, {"h", "f"}, {"f", "g"}, {"g", "h"}
    };
    int num_aristas = sizeof(aristas_orientadas) / sizeof(aristas_orientadas[0]);

    // Agregar aristas mediante un bucle
    for (int i = 0; i < num_aristas; i++) {
        agregar_arista(adyacencia, vertices, *num_vertices, 1, aristas_orientadas[i][0], aristas_orientadas[i][1]);
    }
}

//Crear grafo Euleriano con orientacion 1
void crear_euleriano_orientacion1(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i = 0; i < 10; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }

    char *aristas_orientadas[][2] = {
        {"a", "b"}, {"h", "a"}, {"b", "c"}, {"b", "j"}, {"h", "b"},
        {"c", "j"}, {"c", "d"}, {"e", "c"}, {"d", "f"}, {"i", "d"},
        {"d", "e"}, {"e", "j"}, {"i", "e"}, {"e", "f"}, {"e", "g"},
        {"f", "i"}, {"h", "f"}, {"f", "g"}, {"g", "i"}, {"g", "h"},
        {"h", "i"}, {"j", "h"}, {"i", "j"}
    };

    int num_aristas = sizeof(aristas_orientadas) / sizeof(aristas_orientadas[0]);

    for (int i = 0; i < num_aristas; i++) {
        agregar_arista(adyacencia, vertices, *num_vertices, 1, aristas_orientadas[i][0], aristas_orientadas[i][1]);
    }
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

/*
int main() {

}
*/

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

    get_tipo_grafo(1, &vertices_G, &n_vertices_G, &aristas_G, &n_aristas_G);
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
