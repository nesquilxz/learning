#include <stdio.h>

int suc(int x) {
    return x+1;
}

int pred(x) {
    return x-1;
}



int soma(int a, int b) {
// enquanto pred a != 0, suc b 

    if (a == 0) {
        return b;
    }


    return soma(pred(a), suc(b));


}





int main(void) {

    int a, b, resposta;


  
        printf("Digite dois numeros separados por espaco: ");
        scanf("%d %d", &a, &b);
       

        resposta = soma(a, b);
        printf("A soma e': %d\n\n", resposta);
   
  


    return 0;

}
