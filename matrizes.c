#include <stdio.h>

#define l 3
#define c 4


void preenchematriz(int (*matriz)[4]) {

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("Digite o numero da linha %d, coluna %d", i+1 , j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

}

void printarmatriz(int (*matriz)[4]) {

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

}


main() {
    int mat[3][4];
    preenchematriz(mat);
    printarmatriz(mat);
    return 0;
}

