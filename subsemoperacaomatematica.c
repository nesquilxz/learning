#include <stdio.h>

int suc(int x) {
    return x+1;
}

int pred(x) {
    return x-1;
}



int sub(int a, int b) {
// enquanto pred b != 0, a desce e b tbm

    if (b == 0) {
        return a;
    }


    return sub(pred(a), pred(b));


}





int main(void) {

    int a, b, resposta;


  
        printf("Digite dois numeros separados por espaco: ");
        scanf("%d %d", &a, &b);
       

        resposta = sub(a, b);
        printf("A subtracao e': %d\n\n", resposta);
   
  


    return 0;

}
