#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char info;
    int dado;
    struct no *esq;
    struct no *dir;
} Tarvore;

//    A
//  B   C
// E D E F

//possui 3 de altura.

int altura(Tarvore *raiz) {

 if(raiz == NULL) {
    return 0;
 }


 int he = altura(raiz->esq);
 int hd = altura(raiz->dir);

 if (he > hd) {
    return he +1;
 }

 else {
    return hd+1;
 }


}


int contanos(Tarvore *a) {

    if (a == NULL) {return 0;}
    
    int ne = contanos(a->esq);
    int nd = contanos(a->dir);


    return ne + nd +1;

}



int somageral(Tarvore *a) {

    if (a == NULL) {return 0;}

    int ve = somageral(a->esq);
    int vd = somageral(a->dir);

    return (a->dado + ve + vd);


}



//          30
//       10    50
//     15  *  *   43

Tarvore *maior(Tarvore *a) {

    
    if (a == NULL) {
        return NULL;
    }

    Tarvore *maiorEsq = maior(a->esq);
    Tarvore *maiorDir = maior(a->dir);

    Tarvore *maior = a;


    if (maiorEsq > maior) {
        maior = maiorEsq;
    }

    else if(maiorDir > maior) {
        maior = maiorDir;
    }

    return maior;

}
