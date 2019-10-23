#include <stdio.h>
#include <stdlib.h>

int main() {

    int numeros = 0;
    int primo = 0;

    scanf("%d\n",&primo);
    fprintf(stderr, "Primo: %d\n", primo);

    while(numeros >= 0) {
        scanf("%d\n",&numeros);

        if(numeros % primo != 0){
            printf("%d\n",numeros);
        }
    }
    printf("%d\n",numeros);
}