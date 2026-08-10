#include <stdio.h>
#include <stdlib.h>


typedef struct no {
  int info;
  struct no *esq;
  struct no *dir;
}Tarv;


int altura(Tarv *a) {
  if (a == NULL) {
  return -1;}

int he = altura(a->esq);
int hd = altura(a->dir);

if(he>hd){
  return (he+1);}

else return (hd+1);
