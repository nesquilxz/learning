#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char info;
    struct no *esq;
    struct no *dir;
} Tarvore;


//iterativa.
Tarvore *busca(Tarvore * raiz, char info) {


    while (raiz != NULL)
    {
        
        if (raiz->info == info) {return raiz;}
        else if(raiz->info < info) {
            raiz = raiz->esq;
        }

        else if(raiz->info > info) {
            raiz = raiz->dir;
        }


    }
    

    
     return NULL;
        
}

// perceba que na versao iterativa do código de busca em uma abb nós temos um while que sempre aparece para ir andando com o nó raiz.


//recursivo.

Tarvore *busca(Tarvore *raiz, char info) {


    if (raiz == NULL) {
        return NULL;
    }

    else if (raiz->info == info) {
        return raiz;
    }


    else if (raiz->info > info) {
        busca(raiz->dir, info);
    }

   else if (raiz->info < info) {
        busca(raiz->esq, info);
    }


}
