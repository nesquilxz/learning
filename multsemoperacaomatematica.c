#include <stdio.h>


int sucessivo(int n) {
    return n + n;
}


int pred(x) {
    return x-1;
}



int mult(int a, int b) {
// 1 * 4 = 1 + 1 + 1 + 1.

    if (b == 1) {
        return a;
    }


    return mult(sucessivo(a), pred(b));


}





int main(void) {

    int a, b, resposta;


  
        printf("Digite dois numeros separados por espaco: ");
        scanf("%d %d", &a, &b);
       

        resposta = mult(a, b);
        printf("A multiplicacao e': %d\n\n", resposta);
   
  


    return 0;

}
