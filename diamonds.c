#include <stdio.h>
#include <string.h>

int conta_diamantes(char *s) {


int diamantes = 0;
int dAberto = 0;
int tamanho = strlen(s);
int i = 0;


i = 0;

for(i = 0; i < tamanho; i++) {
    if (s[i] == '<') { 
        dAberto++; }


    else if(dAberto> 0) {
        if (s[i] == '>') {
            dAberto--;
            diamantes++;
        }
    }
        


}


return diamantes;


}


int main(void) {

    char s[] = ">>>>><..><<...<<>...<>>>";

    int x = conta_diamantes(s);
    printf("\n%d diamantes no total.", x);


}
