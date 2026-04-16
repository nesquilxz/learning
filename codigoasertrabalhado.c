#include <stdio.h>
#include <string.h>

// 16/05/2026 --> 16 05 2026

void retornadata(char* data, int *d, int *m, int *a) {

    char datafiltrada[8];

    for(int i = 0; i < strlen(data); i++) {

        if(strcmp(data[i], "/") != 0) {
            datafiltrada[i] = data[i];
        }

    }

    int dataint;

    sprintf(dataint, "%d", datafiltrada);

    

    *d = dataint/1000000
    *m = (dataint/10000)%100
    *a = dataint % 10000
    

    

}




int main(void) {

    char *data;
    int d, m, a;
    printf("Digite a data no formato DD/MM/AAAA: ");
    scanf("%s", data);


  retornadata(data, &d, &m, &a);

    printf("Dia: %02d\n", dia);
    printf("Mes: %02d\n", mes);
    printf("Ano: %04d\n", ano);

    return 0;


   return 0;
}

// 1, 6
