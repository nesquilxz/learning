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

void salva_departamento(TDepartamento *dept, FILE *out) {
    fprintf(out, "%d", dept->cod_dept);
    fprintf(out, "%c", ';');
    fprintf(out, "%d", dept->sala);
    fprintf(out, "%c", ';');
    fprintf(out, "%s", dept->nome);
    fprintf(out, "%c", ';');
    fprintf(out, "%s", "\n");
}

void salva_funcionario(TFuncionario *func, FILE *out) {
    fprintf(out, "%d", func->cod_func);
    fprintf(out, "%c", ';');
    fprintf(out, "%d", func->cod_dept);
    fprintf(out, "%c", ';');
    fprintf(out, "%s", func->nome);
    fprintf(out, "%c", ';');
    fprintf(out, "%s", "\n");
}

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

    // Separa os campos da linha.
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

    // Separa os campos da linha.
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

void join(char *nome_arq_dept, char *nome_arq_funcionarios,
          char *nome_arq_join) {

    FILE *arquivoDept = fopen(nome_arq_dept, "r");
    FILE *arquivoFunc = fopen(nome_arq_funcionarios, "r");

    // Verifica se os arquivos de entrada foram abertos.
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

    TDepartamento *departamento = le_departamento(arquivoDept);

    // Percorre os departamentos.
    while (departamento != NULL) {

        // Volta ao início do arquivo de funcionários.
        rewind(arquivoFunc);

        TFuncionario *funcionario = le_funcionario(arquivoFunc);

        // Compara o departamento atual com todos os funcionários.
        while (funcionario != NULL) {

            if (departamento->cod_dept == funcionario->cod_dept) {
                fprintf(arquivoJoin, "%d;%d;%s;%d;%s;\n",
                        departamento->cod_dept,
                        departamento->sala,
                        departamento->nome,
                        funcionario->cod_func,
                        funcionario->nome);
            }

            // Libera o funcionário lido e lê o próximo.
            free(funcionario);
            funcionario = le_funcionario(arquivoFunc);
        }

        // Terminou de verificar todos os funcionários.
        // Agora passa para o próximo departamento.
        free(departamento);
        departamento = le_departamento(arquivoDept);
    }

    fclose(arquivoDept);
    fclose(arquivoFunc);
    fclose(arquivoJoin);
}

int main() {
    join("departamentos.txt", "funcionarios.txt", "join.txt");
    imprime_arquivo("join.txt");
}
