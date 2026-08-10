int somanos(Tarv *a) {
  if (a != NULL) {

  noesq = somanos(a->esq);
  nodir = somanos(a->dir);

return (a->info + noesq + nodir);
  }

return 0;
}
