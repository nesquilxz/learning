#include <stdio.h>
#include <string.h>

int main() {
    char *resultados[] = {
        "vitoria", "vitoria", "derrota",
        "vitoria", "vitoria", "vitoria",
        "derrota"
    };

    int n = sizeof(resultados) / sizeof(resultados[0]);
    int max_vitorias = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(resultados[i], "vitoria") == 0) {

            int cont = 0;

            for (int j = i; j < n; j++) {
                if (strcmp(resultados[j], "vitoria") == 0)
                    cont++;
                else
                    break;
            }

            if (cont > max_vitorias)
                max_vitorias = cont;
        }
    }

    printf("Maior quantidade de vitorias seguidas: %d\n", max_vitorias);
    return 0;
}
