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
void agregar_arista(int adyacencia[][MAX_VERTICES], char vertices[][MAX_LONGITUD_NOMBRE], 
              int num_vertices, int dirigido, char *v1, char *v2) {
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

//Crear arbol no dirigido
void crear_arbol_no_dirigido(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    // Agregar vértices
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l"};
    for (int i = 0; i < 12; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }

    char *aristas[][2] = {
        {"a", "b"}, {"a", "c"}, {"b", "d"}, {"d", "h"}, {"d", "i"},
        {"c", "e"}, {"c", "f"}, {"c", "g"}, {"g", "l"}, {"f", "j"}, 
        {"f", "k"}
    };
    int num_aristas = sizeof(aristas) / sizeof(aristas[0]);

    //Agregar aristas
    for (int i = 0; i < num_aristas; i++) {
        agregar_arista(adyacencia, vertices, *num_vertices, 0, aristas[i][0], aristas[i][1]);
    }
}

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

//Crear grafo planar no dirigido
void crear_planar_no_dirigido(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    for (int i = 0; i < 9; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }
    
    char *aristas[][2] = {
        {"a", "b"}, {"a", "h"}, {"b", "h"}, {"b", "d"}, {"b", "c"},
        {"c", "d"}, {"d", "i"}, {"d", "f"}, {"d", "e"}, {"e", "f"}, 
        {"f", "i"}, {"f", "h"}, {"f", "g"}, {"g", "h"}
    };
    int num_aristas = sizeof(aristas) / sizeof(aristas[0]);
    
    for (int i = 0; i < num_aristas; i++) {
        agregar_arista(adyacencia, vertices, *num_vertices, 0, aristas[i][0], aristas[i][1]);
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

//Crear grafo Euleriano no dirigido
void crear_euleriano_no_dirigido(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i = 0; i < 10; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }

    char *aristas[][2] = {
        {"a", "b"}, {"a", "h"}, {"b", "c"}, {"b", "j"}, {"b", "h"},
        {"c", "j"}, {"c", "d"}, {"c", "e"}, {"d", "f"}, {"d", "i"},
        {"d", "e"}, {"e", "j"}, {"e", "i"}, {"e", "f"}, {"e", "g"},
        {"f", "i"}, {"f", "h"}, {"f", "g"}, {"g", "i"}, {"g", "h"},
        {"h", "i"}, {"h", "j"}, {"i", "j"}
    };
    int num_aristas = sizeof(aristas) / sizeof(aristas[0]);

    // Agregar aristas mediante un bucle
    for (int i = 0; i < num_aristas; i++) {
        agregar_arista(adyacencia, vertices, *num_vertices, 0, aristas[i][0], aristas[i][1]);
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

void imprimir_grafo(int num_vertices, char vertices[][MAX_LONGITUD_NOMBRE], int matriz_adyacencia[][MAX_VERTICES]) {
    printf("\nArbol creado. Los vertices son: %d\n", num_vertices);

    printf("     ");
    for (int j = 0; j < num_vertices; j++) {
        printf("%s  ", vertices[j]);
    }
    printf("\n");
    
    // Imprimir matriz de adyacencia
    for (int i = 0; i < num_vertices; i++) {
        printf("%s |  ", vertices[i]);
        for (int j = 0; j < num_vertices; j++) {
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
    char vertices[MAX_VERTICES][MAX_LONGITUD_NOMBRE];
    int matriz_adyacencia[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;

    crear_arbol_no_dirigido(vertices, &num_vertices, matriz_adyacencia);

    imprimir_grafo(num_vertices, vertices, matriz_adyacencia);

    int *distancia;
    bool *visto;
    distancia = (int *)malloc(num_vertices * sizeof(int));
    visto = (bool *)malloc(num_vertices * sizeof(bool));

    int s = 3;

    inicializar_dijkstra(num_vertices, distancia, visto, s);
    algoritmo(num_vertices, visto, distancia, matriz_adyacencia);

    for (int i = 0; i < num_vertices; i++) {
        printf("%s: %d\n", vertices[i], distancia[i]);
    }

    free(distancia);
    free(visto);

    return 0;
}
