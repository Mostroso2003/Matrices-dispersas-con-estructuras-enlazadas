#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int main(void)
{
    srand(time(NULL));
    int n,m,x,elec,elec2;
    slist* matriz1 = NULL;
    slist* matriz2 = NULL;

        printf("\n    ***MENU PROYECTO***\n\n");
        printf("Que operacion desea efectuar con matrices usando listas enlazadas?\n");
        printf("(1) Obtener elemento de la matriz\n");
        printf("(2) Asignar un elemento a la matriz\n");
        printf("(3) Sumar\n");
        printf("(4) Producto por escalar\n");
        printf("(5) Producto\n");
        printf("(6) Transponer\n");
        printf("(7) Imprimir\n");
        printf("\n");
        printf("(8) Salir\n\n");
        printf("Opcion? ");
        scanf("%d",&elec);
        if (elec < 1 || elec > 7) return(0);
        /* Creacion de la matriz */
        printf("Ingrese las dimensiones de la matriz que quiere crear\n");
        printf("Columnas: ");
        scanf("%d",&m);
        printf("Filas: ");
        scanf("%d",&n);
        do{
            printf("Como desea crear la matriz\n");
            printf("(1) De forma manual\n");
            printf("(2) De forma automatica con valores 0 y 1\n");
            printf("Opcion? ");
            scanf("%d",&elec2);
            if (elec2 == 1)
                matriz1 = new_matrix(matriz1,n,m);
            else if(elec2 == 2)
                matriz1 = new_matrix_auto(matriz1,n,m);
        } while (elec2 < 1 || elec2 > 2);

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
            printf("La matriz2 tiene que tener las mismas dimensiones que la matriz1\n");
            printf("Ingrese las dimensiones de la matriz2 que quiere crear\n");
            printf("Columnas: ");
            scanf("%d",&m);
            printf("Filas: ");
            scanf("%d",&n);
            do{
                printf("Como desea crear la matriz\n");
                printf("(1) De forma manual\n");
                printf("(2) De forma automatica con valores 0 y 1\n");
                printf("Eleccion: ");
                scanf("%d",&elec);
                if (elec == 1)
                    matriz2 = new_matrix(matriz2,n,m);
                else if(elec == 2)
                    matriz2 = new_matrix_auto(matriz2,n,m);
            } while (elec < 1 || elec > 2);
            slist* matriz_suma = suma_matrix(matriz1,matriz2);
            print_matrix(suma_matrix(matriz1, matriz2));
        }
        case 4: {
            /* Multiplicar la matriz por un escalar */
            printf("Valor para multiplicar la matriz: ");
            scanf("%d",&x);
            printf("\n");
            print_matrix(prod_esc(x,matriz1));
            break;
        }
        case 5: {
            int x;
            printf("Ingrese el numero por el que quiere multiplicar la matriz");
            scanf("%d",&x);
            slist* matriz_esc = prod_esc(x,matriz1);
            print_matrix(matriz_esc);
            break;
        }
        case 6: {
            /* Transponer */
            slist* matriz_trans = transpose(matriz1);
            printf("\n");
            print_matrix(matriz_trans);
            break;
        }
        case 7: {
            printf("La matriz2 tiene que tener la cantidad de filas igual a la cantidad de columnas de la matriz1\n");
            printf("Ingrese las dimensiones de la matriz2 que quiere crear\n");
            printf("Columnas: ");
            scanf("%d",&m);
            printf("Filas: ");
            scanf("%d",&n);
            do{
                printf("Como desea crear la matriz\n");
                printf("(1) De forma manual\n");
                printf("(2) De forma automatica con valores 0 y 1\n");
                printf("Eleccion: ");
                scanf("%d",&elec);
                if (elec == 1)
                    matriz2 = new_matrix(matriz2,n,m);
                else if(elec == 2)
                matriz2 = new_matrix_auto(matriz2,n,m);
            } while (elec < 1 || elec > 2);
            print_matrix(matriz2);
            break;
        }
    }
    return 0;
}
