#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAM_NOME 100

typedef struct Departamento {
    int cod_dept;
    int sala;
    char nome[TAM_NOME];
} TDepartamento;

typedef struct Funcionario {
    int cod_func;
    int cod_dept;
    char nome[TAM_NOME];
} TFuncionario;

TFuncionario *le_funcionario(FILE *in) {
    TFuncionario *func = (TFuncionario *) malloc(sizeof(TFuncionario));
    char linha[150];

    if (fgets(linha, 150, in) == NULL) {
        free(func);
        return NULL;
    }

    char delimitador[] = ";";
    char *ptr;
    int cod;

    ptr = strtok(linha, delimitador);
    cod = atoi(ptr);
    func->cod_func = cod;

    ptr = strtok(NULL, delimitador);
    cod = atoi(ptr);
    func->cod_dept = cod;

    ptr = strtok(NULL, delimitador);
    strcpy(func->nome, ptr);

    return func;
}

TDepartamento *le_departamento(FILE *in) {
    TDepartamento *dept = (TDepartamento *) malloc(sizeof(TDepartamento));
    char linha[150];

    if (fgets(linha, 150, in) == NULL) {
        free(dept);
        return NULL;
    }

    char delimitador[] = ";";
    char *ptr;
    int cod, sala;

    ptr = strtok(linha, delimitador);
    cod = atoi(ptr);
    dept->cod_dept = cod;

    ptr = strtok(NULL, delimitador);
    sala = atoi(ptr);
    dept->sala = sala;

    ptr = strtok(NULL, delimitador);
    strcpy(dept->nome, ptr);

    return dept;
}

void imprime_arquivo(char *name) {
    FILE *arq = fopen(name, "r");

    if (arq != NULL) {
        char linha[150];
        fgets(linha, 150, arq);

        while (!feof(arq)) {
            printf("%s", linha);
            fgets(linha, 150, arq);
        }

        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo\n");
    }
}

void leftOuterJoin(char *nome_arq_dept, char *nome_arq_funcionarios,
                   char *nome_arq_join) {

    FILE *arquivoDept = fopen(nome_arq_dept, "r");
    FILE *arquivoFunc = fopen(nome_arq_funcionarios, "r");

    if (arquivoDept == NULL || arquivoFunc == NULL) {
        if (arquivoDept != NULL) {
            fclose(arquivoDept);
        }

        if (arquivoFunc != NULL) {
            fclose(arquivoFunc);
        }

        return;
    }

    FILE *arquivoJoin = fopen(nome_arq_join, "w");

    if (arquivoJoin == NULL) {
        fclose(arquivoDept);
        fclose(arquivoFunc);
        return;
    }

    // Pula espaços e linhas vazias antes da leitura.
    fscanf(arquivoDept, " ");
    TDepartamento *departamento = le_departamento(arquivoDept);

    while (departamento != NULL) {
        // Começa uma nova verificação para este departamento.
        int encontrouFuncionario = 0;

        // Volta ao início para verificar todos os funcionários.
        rewind(arquivoFunc);

        fscanf(arquivoFunc, " ");
        TFuncionario *funcionario = le_funcionario(arquivoFunc);

        while (funcionario != NULL) {
            if (departamento->cod_dept == funcionario->cod_dept) {
                fprintf(arquivoJoin, "%d;%d;%s;%d;%s;\n",
                        departamento->cod_dept,
                        departamento->sala,
                        departamento->nome,
                        funcionario->cod_func,
                        funcionario->nome);

                encontrouFuncionario = 1;
            }

            // Libera o registro e lê o próximo funcionário.
            free(funcionario);

            fscanf(arquivoFunc, " ");
            funcionario = le_funcionario(arquivoFunc);
        }

        // Já verificou todos os funcionários.
        // Se nenhum pertencer ao departamento, grava com 0 e nome vazio.
        if (encontrouFuncionario == 0) {
            fprintf(arquivoJoin, "%d;%d;%s;0;;\n",
                    departamento->cod_dept,
                    departamento->sala,
                    departamento->nome);
        }

        // Passa para o próximo departamento.
        free(departamento);

        fscanf(arquivoDept, " ");
        departamento = le_departamento(arquivoDept);
    }

    // Linha vazia no final, conforme o enunciado.
    fprintf(arquivoJoin, "\n");

    fclose(arquivoDept);
    fclose(arquivoFunc);
    fclose(arquivoJoin);
}

int main() {
    leftOuterJoin("departamentos.txt", "funcionarios.txt", "join.txt");
    imprime_arquivo("join.txt");
}
