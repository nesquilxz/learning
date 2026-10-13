// 1. Lê os metadados: pega a ordem d, o endereço da raiz em pont e a indicação folha, que informa se a raiz é uma folha. Depois libera m, pois esses valores já foram copiados.
// 2. Abre os arquivos: se a raiz for interna, abre indice.dat. Também abre clientes.dat, onde estão as folhas.
// 3. Desce pelos nós internos: o fseek posiciona a leitura no endereço pont. Depois, le_no_interno lê esse nó e imprime_no_interno o imprime.
//    Aqui escolhemos por qual ponteiro continuar:
//    int i = 0;
//    while (i < no->m && chave >= no->chaves[i]) i++;
   
//    Por exemplo, num nó com 15 e 25:
//    - buscando 10, segue por p[0];
//    - buscando 20, segue por p[1];
//    - buscando 25, segue por p[2].
//    Na B+, igual também segue pela direita, porque o registro está na folha.
// 4. Atualiza o caminho: pont = no->p[i] pega o endereço do próximo nó, e folha = no->aponta_folha informa se ele é uma folha. O nó atual é liberado, e o processo continua.
// 5. Chega à folha: lê e imprime a folha em clientes.dat, fecha os arquivos e retorna seu endereço.
// Ele retorna a folha onde a chave está ou deveria estar, mesmo se a chave não existir. As verificações de erro retornam -1 quando não é possível concluir a busca.


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
    if (!folha) { //nao entendi muito bem esta parte. verifica se nao tem folha? mas isso seria contraditorio em fazer busca. como fazer busca em arv b+ que nao tem folha??
        arq_i = fopen(nome_arquivo_indice, "rb");
        if (arq_i == NULL) return -1;
    }

    FILE *arq_d = fopen(nome_arquivo_dados, "rb");
    if (arq_d == NULL) {
        if (arq_i != NULL) fclose(arq_i);
        return -1;
    }

    while (!folha && pont != -1) { //n entendi aq tbm
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
        while (i < no->m && chave >= no->chaves[i]) i++; //aqui poderia er um if chave == no->chave[i] e ver se é, se for, entao pont = no->p[i] e ai da um return depois, nao?

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
