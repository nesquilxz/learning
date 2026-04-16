#include <stdio.h>
#include <string.h>

// 16/05/2026 --> 16 05 2026

int retornadata(char* data) {

    char *datafiltrada;
    
    for(int i = 0; i < strlen(data); i++) {

        if(strcmp(data[i], "/") != 0) {
            datafiltrada[i] = data[i];
        }

    }

    int dataint;

    sprintf(dataint, "%d", datafiltrada);

    return dataint;

}




int main(void) {

    char *data;
    printf("Digite a data no formato DD/MM/AAAA: ");
    scanf("%s", data);

    int datanumero;
   
   
   datanumero =  retornadata(data);

   printf("Data: %d", data);


   return 0;
}

// 1, 6
