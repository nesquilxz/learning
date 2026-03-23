#include <stdio.h>

//recursivo

 int fibonacci(int* n2) {

     // caso base:

    if (*n2 == 0) {
        
        return 0;
    }

     if (*n2 == 1) {
       
        return 1;
    }


    int temp1 = *n2 -1;
    int temp2 = *n2 - 2; 

     return fibonacci(&temp1) + fibonacci(&temp2);



 }





int main(void) {

int t1, t2, t3, n;

do {
printf("Digite o valor de N positivo: ");
scanf("%d", &n);
}while (n <= 0);



t1 = 0;
t2 = 1;

printf("Serie de FIB: %d %d ", t1, t2);

t3 = t1 + t2;

while (t3 <= n)
{

    printf("%d ", t3);
    
    t1 = t2;
    t2 = t3;
    t3 = t1 + t2;

}


printf("\n\n");

int pos;
do {
printf("Digite o valor de N positivo (agora recursiva): ");
scanf("%d", &pos);
}while (pos <= 0);


for(int i = 0; i <= pos; i++) {

    printf(" %d ", fibonacci(&i));

}

printf("\n\n");





return 0;






  
}





