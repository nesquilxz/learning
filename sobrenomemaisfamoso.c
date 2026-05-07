//crie um codigo onde estamos lidando com um vetor de string. 
//temos varios nomes junto de sobrenomes. voce precisa criar uma função onde ler qual 
//sobrenome é o mais comum nesse vetor de string (nomes)

//voce precisa ler cada nome e sobrenome tambem em outra função


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void preenchesobrenome(char** sobrenomes, int n) {

    for(int i = 0; i < n; i++) {

        printf("Digite o sobrenome da %d pessoa: \n", i+1);
        scanf("%s", sobrenomes[i]);

    }



}


char* sobrenomemaisfamoso(char** sobrenomes, int n) {

    int apareceumais = 0;
    char* sobrenomefamoso; // pode ser char sobrenomefamoso[50]?
    sobrenomefamoso = (char*) malloc(sizeof(char)* 100);
    

    for (int i = 0; i < n; i++) {
        int apareceu = 0;
        for (int j = 0; j < n; j++) {
            if(strcmp(sobrenomes[j], sobrenomes[i]) == 0) {        //sobrenomes[j] é endereço...
                apareceu++;
            }
        }

        if(apareceu > apareceumais) {
            apareceumais = apareceu;
            strcpy(sobrenomefamoso, sobrenomes[i]);
        }

    }

    return sobrenomefamoso;

}



int main(void) {
    int n;
    printf("Digite quantos sobrenomes sao: ");
    scanf("%d", &n);

    char** sobrenomes;

    sobrenomes = (char**) malloc(sizeof(char*) * n);

    //alocando cada sobrenome.

    for(int i =0; i <n; i++) {

        sobrenomes[i] = (char*) malloc(sizeof(char) * 100);

    }


    printf("Agora vamos preencher cada sobrenome: ");
    preenchesobrenome(sobrenomes, n);

    printf("Agora que preenchemos, vamos ver qual é o sobrenome mais famoso dado!\n\n");

    char sobrenome[100];

     strcpy(sobrenome, sobrenomemaisfamoso(sobrenomes, n)); //aqui nao precisamos colocar &sobrenomes? não, pq é string! (ja vira ponteiro/endereço)

     printf("O sobrenome mais famoso é: %s. \n\n", sobrenome);

}
