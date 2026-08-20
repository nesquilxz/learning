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
