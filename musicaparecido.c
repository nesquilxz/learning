#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct no
{
    char palavra[50];
    struct no *prox;

}Tlista;

int buscapalavra (Tlista *a, char *palavra, Tlista **pre) {

    Tlista *preL, *aux;
    preL = a;
    aux = preL->prox;

    while((aux != NULL) && (strcmp(aux->palavra, palavra) < 0)) {// aux->palavra vier antes da palavra

        preL = aux;
        aux = aux->prox;
    } 

    (*pre) = preL;

    if((aux != NULL) && (strcmp(aux->palavra, palavra) == 0)) {
        return 1;
    }
    else {
        return 0;
    }



}


int inserepalavra (Tlista **a, char *palavra) {
    Tlista *pre;
    if(!buscapalavra(*a, palavra, &pre)) {

        Tlista *el;
        el = (Tlista*) malloc(sizeof(Tlista));
        strcpy(el->palavra, palavra);
        el->prox = pre->prox;
        pre->prox = el;
        return 1;
        
    }

    return 0;
}






// int contapalavras(FILE* a) {
//     char palavra[50];
//     int cont = 0;
//     while(fscanf(a, "%s",palavra)==1) {
//        cont++;
//     }


//     return cont;
// }




int main(void) {

    Tlista *L ;
    L = (Tlista*) malloc(sizeof(Tlista));
    L->prox = NULL;
    FILE *arqEntrada, *arqSaida;

    arqEntrada = fopen("entrada.txt", "r");
    if(arqEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.");
        return 0;
    }

    arqSaida = fopen("saida.txt", "w");
    if(arqSaida == NULL) {
        printf("Erro ao abrir o arquivo de saida.");
        return 0;
    }

    char palavraAtual[50];
 
  
    while(fscanf(arqEntrada, "%s", palavraAtual ) == 1) {

        if(inserepalavra(&L, palavraAtual)) {

            fprintf(arqSaida, "%s \n", palavraAtual);

        }

    }

    fclose(arqEntrada);
    fclose(arqSaida);


    return 0;
}


       // achou = 0;

      //  for(int i = 0; i < Npalavras; i++) {

          //  if(strcmp(palavraAtual, palavrasdiferentes[i]) == 0) {
          //      achou = 1;
           //     diferentes[i]++;
           //     break;

          //  }

         //   if(!achou) {
          //      diferentes[n]++;
          //      strcpy(palavrasdiferentes[n], palavraAtual);
          //      n++;

          //  }

       // }
