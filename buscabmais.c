    //A leitura não segue ordem específica -- os nós são lidos na ordem em que foram gravados no arquivo
    FILE *arq_d = fopen("clientes.dat", "rb");
    printf("\n*** Arquivo de Dados ***\n");
    i = 0;
    TNoFolha *nf = le_no_folha(m->d, arq_d);
    while (nf != NULL) {
        printf("(((Endereco %d)))\n", i * tamanho_no_folha(m->d));
        imprime_no_folha(m->d, nf);
        nf = le_no_folha(m->d, arq_d);
        i += 1;
    }
    fclose(arq_d);
}

/*
 * Executa busca em Arquivos utilizando Arvore B+
 * Assumir que ponteiros para NULL têm valor -1
 *
 * chave: chave do cliente que esta sendo buscado
 * nome_arquivo_metadados: nome do arquivo binário que contem os metadados
 * nome_arquivo_indice: nome do arquivo binário de indice (que contem os nohs internos da arvore B+)
 * nome_arquivo_dados: nome do arquivo binário de dados (que contem as folhas da arvore B+)
 *
 * Retorna ponteiro para nó em que a chave está ou deveria estar
 */
int busca(int chave, char *nome_arquivo_metadados, char *nome_arquivo_indice, char *nome_arquivo_dados)
{
	//TODO: Implementar essa função
    FILE *arq_m = fopen(nome_arquivo_metadados, "rb");
    if (arq_m == NULL) return -1;

    TMetadados *m = le_metadados(arq_m);
    fclose(arq_m);
    if (m == NULL) return -1;

    int d = m->d;
    int pont = m->pont_raiz;
    int folha = m->raiz_folha;
    free(m);

    if (pont == -1) return -1;

    FILE *arq_i = NULL;
    if (!folha) {
        arq_i = fopen(nome_arquivo_indice, "rb");
        if (arq_i == NULL) return -1;
    }

    FILE *arq_d = fopen(nome_arquivo_dados, "rb");
    if (arq_d == NULL) {
        if (arq_i != NULL) fclose(arq_i);
        return -1;
    }

    while (!folha && pont != -1) {
        if (fseek(arq_i, pont, SEEK_SET) != 0) {
            pont = -1;
            break;
        }

        TNoInterno *no = le_no_interno(d, arq_i);
        if (no == NULL) {
            pont = -1;
            break;
        }

        imprime_no_interno(d, no);

        int i = 0;
        while (i < no->m && chave >= no->chaves[i]) i++;

        pont = no->p[i];
        folha = no->aponta_folha;
        libera_no_interno(no);
    }

    if (pont != -1 && fseek(arq_d, pont, SEEK_SET) == 0) {
        TNoFolha *no = le_no_folha(d, arq_d);
        if (no != NULL) {
            imprime_no_folha(d, no);
            libera_no_folha(d, no);
        } else {
            pont = -1;
        }
    } else {
        pont = -1;
    }

    if (arq_i != NULL) fclose(arq_i);
    fclose(arq_d);

    return pont;
}

int main () {
    //Descomente essa linha de código caso deseje imprimir o conteúdo dos arquivos de entrada para analisar
    //o comportamento da sua implementação

    //imprime_arquivos();

    /* Le chave a ser buscada */
    int chave;

    scanf("%d", &chave);

    //Chama função de busca
    int pont = busca(chave, "metadados.dat", "indice.dat", "clientes.dat");

    //Imprime resultado da função
    printf("RESULTADO DA BUSCA: %d\n", pont);
}
