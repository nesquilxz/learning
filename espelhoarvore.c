Tarvore *espelho(Tarvore *raiz) {
  if (raiz != NULL) {
  Tarvore *temp = raiz->esq;
  raiz->esq = raiz->dir;
  raiz->dir = temp;
  espelho(raiz->esq);
  espelho(raiz->dir);
  }
return raiz;

}
