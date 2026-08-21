Tarvore *maior(Tarvore *a) {

    
    if (a == NULL) {
        return NULL;
    }

    Tarvore *maiorEsq = maior(a->esq);
    Tarvore *maiorDir = maior(a->dir);

    Tarvore *maior = a;


    if (maiorEsq->info > maior->info) {
        maior = maiorEsq;
    }

    else if(maiorDir->info > maior->info) {
        maior = maiorDir;
    }

    return maior;

}
