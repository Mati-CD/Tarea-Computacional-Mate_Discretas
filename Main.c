#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 20
#define MAX_LONGITUD_NOMBRE 10

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
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k"};
    for (int i = 0; i < 11; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }
    
    //Agregar aristas
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "a", "b");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "a", "c");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "b", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "d", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "d", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "c", "e");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "c", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "e", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "g", "l");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "f", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "f", "k");
}

//Crear arbol con orientacion 1
void crear_arbol_orientacion1(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k"};
    for (int i = 0; i < 11; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }
    
    //Orientación arbitraria
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "a", "b");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "a", "c");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "b", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "d", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "i", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "c", "e");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "f", "c");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "e", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "l", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "f", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "k", "f");
}

//Crear grafo planar no dirigido
void crear_planar_no_dirigido(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    for (int i = 0; i < 9; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }
    
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "a", "b");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "a", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "b", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "b", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "b", "c");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "c", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "d", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "d", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "d", "e");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "e", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "f", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "f", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "f", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "g", "h");
}

//Crear grafo planar con orientacion 1
void crear_planar_orientacion1(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    for (int i = 0; i < 9; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }
    
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "a", "b");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "h", "a");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "b", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "b", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "c", "b");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "c", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "d", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "d", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "e", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "e", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "f", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "h", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "f", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "g", "h");
}

//Crear grafo Euleriano no dirigido
void crear_euleriano_no_dirigido(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i = 0; i < 10; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }
    
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "a", "b");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "a", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "b", "c");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "b", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "b", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "c", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "c", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "c", "e");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "d", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "d", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "d", "e");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "e", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "e", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "e", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "e", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "f", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "f", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "f", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "g", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "g", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "h", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "h", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 0, "i", "j");
}

//Crear grafo Euleriano con orientacion 1
void crear_euleriano_orientacion1(char vertices[][MAX_LONGITUD_NOMBRE], int *num_vertices, int adyacencia[][MAX_VERTICES]) {
    *num_vertices = 0;
    inicializar_adyacencia(adyacencia);
    
    char *nombres_vertices[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i = 0; i < 10; i++) {
        agregar_vertice(vertices, num_vertices, nombres_vertices[i]);
    }
    
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "a", "b");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "h", "a");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "b", "c");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "b", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "h", "b");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "c", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "c", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "e", "c");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "d", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "i", "d");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "d", "e");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "e", "j");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "i", "e");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "e", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "e", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "f", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "h", "f");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "f", "g");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "g", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "g", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "h", "i");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "j", "h");
    agregar_arista(adyacencia, vertices, *num_vertices, 1, "i", "j");
}

int main(){
    
}