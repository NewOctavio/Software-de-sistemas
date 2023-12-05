#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct Nodo {
    int valor;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

// Función para crear un nuevo nodo
struct Nodo *nuevoNodo(int valor) {
    struct Nodo *nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodo->valor = valor;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

// Función para insertar un valor en el árbol binario (recursiva)
struct Nodo *insertar(struct Nodo *raiz, int valor) {
    if (raiz == NULL) {
        return nuevoNodo(valor);
    }

    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

// Función para buscar un valor en el árbol binario (recursiva)
struct Nodo *buscar(struct Nodo *raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->izquierda, valor);
    }

    return buscar(raiz->derecha, valor);
}

// Función para recorrido inorden (recursiva)
void inorden(struct Nodo *raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierda);
        printf("%d ", raiz->valor);
        inorden(raiz->derecha);
    }
}

// Función para recorrido preorden (recursiva)
void preorden(struct Nodo *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// Función para recorrido postorden (recursiva)
void postorden(struct Nodo *raiz) {
    if (raiz != NULL) {
        postorden(raiz->izquierda);
        postorden(raiz->derecha);
        printf("%d ", raiz->valor);
    }
}

int validate(struct Nodo *raiz){
    if(raiz != NULL) {
        struct Nodo *l = raiz->izquierda;
        struct Nodo *r = raiz->derecha;
        if (l != NULL) {
            printf("%d %d \n",l->valor, raiz->valor);
            if (l->valor == raiz->valor) {
                printf("ESTE NO ES UN ARBOL BINARIO DE BUSQUEDA VALIDO\n");
                return 0;
            }
        }
        if (r != NULL) {
            printf("%d %d \n",r->valor, raiz->valor);
            if (r->valor == raiz->valor) {
                printf("ESTE NO ES UN ARBOL BINARIO DE BUSQUEDA VALIDO\n");
                return 0;
            }
        }
        if(validate(raiz->izquierda)==0){
            return 0;
        }
        if(validate(raiz->derecha)==0){
            return 0;
        }
    }
    if(raiz == NULL){
        return 1;
    }
    return 1;
}

// Función principal
int main() {
    struct Nodo *raiz = NULL;
    int valor;

    // Ingreso de valores hasta que se ingrese -1
    do {
        printf("Ingrese un valor (o -1 para salir): ");
        if (scanf("%d", &valor) != 1) {
            printf("Entrada invalida. Intente nuevamente.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }

        if (valor == -1) {
            break;
        }

        raiz = insertar(raiz, valor);
    } while (1);
    int a = validate(raiz);
    // Realizar recorridos y búsqueda si el árbol no está vacío
    if (raiz != NULL && a == 1) {
        printf("Recorrido Inorden: ");
        inorden(raiz);
        printf("\n");

        printf("Recorrido Preorden: ");
        preorden(raiz);
        printf("\n");

        printf("Recorrido Postorden: ");
        postorden(raiz);
        printf("\n");

        // Buscar un valor en el árbol
        printf("Ingrese un valor para buscar en el arbol: ");
        if (scanf("%d", &valor) == 1) {
            struct Nodo *nodoEncontrado = buscar(raiz, valor);

            if (nodoEncontrado != NULL) {
                printf("Valor %d encontrado en el arbol.\n", valor);
            } else {
                printf("Valor no encontrado en el arbol.\n");
            }
        } else {
            printf("Entrada invalida para la busqueda.\n");
        }
    } else {
        printf("El arbol esta vacio.\n");
    }

    return 0;
}
