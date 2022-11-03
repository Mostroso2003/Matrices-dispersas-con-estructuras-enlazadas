#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int main(void)
{
    srand(time(NULL));
    int n,m,x,elec;
    slist* matriz1 = NULL;
    slist* matriz2 = NULL;

    printf("\n    ***MENU PROYECTO***\n\n");
    /* Opciones para el programa */
    printf("Que operacion desea efectuar con matrices usando listas enlazadas?\n");
    printf("(1) Obtener elemento de la matriz\n");
    printf("(2) Asignar un elemento a la matriz\n");
    printf("(3) Sumar\n");
    printf("(4) Producto por escalar\n");
    printf("(5) Producto\n");
    printf("(6) Transponer\n");
    printf("\n");
    printf("(x) SALIR");
    printf("\n\n");
    printf("Opcion? ");
    scanf("%d",&elec);
    /* Creacion de la matriz */
    printf("Ingrese las dimensiones de la matriz que quiere crear\n");
    printf("Columnas: ");
    scanf("%d",&m);
    printf("Filas: ");
    scanf("%d",&n);
    matriz1 = new_matrix(matriz1,n,m);
    print_matrix(matriz1);

    switch (elec){
        case 1: {
            /* Buscar elementos en la matriz */
            printf("\nNo se pueden buscar elementos en posiciones negativas\n");
            printf("o que sean mayores que las filas y/o las columnas de la matriz\n");
            printf("Ingrese la posicion x: ");
            scanf("%d",&m);
            printf("Ingrese la posicion y: ");
            scanf("%d",&n);
            printf("Se consiguio el valor %d en la posicion %dx%d\n",search(n,m,matriz1),m,n);
            break;
        }
        case 2: {
            /* Asignar elementos en la matriz */
            printf("\nNo se pueden asignar elementos en posiciones negativas,\n");
            printf("que sean mayores que las filas y/o las columnas de la matriz\n");
            printf("o que no contengan nada\n");
            printf("Ingrese la posicion x: ");
            scanf("%d",&m);
            printf("Ingrese la posicion y: ");
            scanf("%d",&n);
            printf("Ingrese el valor que quiere asignar: ");
            scanf("%d",&x);
            set_value(n,m,x,matriz1);
            print_matrix(matriz1);
            break;
        }
        case 3: {
            /* Sumar matrices */
            printf("La matriz2 tiene que tener las mismas dimensiones que la matriz1\n");
            printf("Ingrese las dimensiones de la matriz2 que quiere crear\n");
            printf("Columnas: ");
            scanf("%d",&m);
            printf("Filas: ");
            scanf("%d",&n);
            matriz2 = new_matrix(matriz2,n,m);
            print_matrix(matriz2);
            if (matriz1->tam_x != matriz2->tam_x || matriz1->tam_y != matriz2->tam_y)
                printf("No se pueden sumar matrices con dimensiones desiguales\n");
            else 
                print_matrix(suma_matrix(matriz1, matriz2));
            break;
        }
        case 4: {
            /* Producto por escalar */
            printf("Ingrese el numero por el que quiere multiplicar la matriz");
            scanf("%d",&x);
            slist* matriz_esc = prod_esc(x,matriz1);
            print_matrix(matriz_esc);
            break;
        }
        case 5: {
            /* Multiplicar matrices */
            printf("La matriz2 tiene que tener la cantidad de filas igual a la cantidad de columnas de la matriz1\n");
            printf("Ingrese las dimensiones de la matriz2 que quiere crear\n");
            printf("Columnas: ");
            scanf("%d",&m);
            printf("Filas: ");
            scanf("%d",&n);
            matriz2 = new_matrix(matriz2,n,m);
            print_matrix(matriz2);
            if (matriz1->tam_x != matriz2->tam_y)
                printf("No se pueden multiplicar las matrices que coloco\n");
            else
                print_matrix(mult_mat(matriz1,matriz2));
            break;
        }
        case 6: {
            /* Transponer */
            slist* matriz_trans = transpose(matriz1);
            printf("\n");
            print_matrix(matriz_trans);
            break;
        }
    }
    return 0;
}
