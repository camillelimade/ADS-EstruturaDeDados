/* ==================================================================
   Algoritmos Avancados (ADS26) - 2026.2 - Aula 07 (18/09/2026)
   PRATICA DIRIGIDA DE PREPARACAO PARA A AV2 - PARTE 1 (bloco AB)
   Busca sequencial e busca binaria

   ESTE ARQUIVO ESTA INCOMPLETO DE PROPOSITO.
   Voce vai preencher os DOIS blocos marcados com TODO e consertar UMA
   linha no bloco marcado com CONSERTE. Nada mais.
   Nao mexa no main: ele ja esta pronto e ja imprime as tabelas.

   Como compilar e rodar (no terminal, na pasta do arquivo):
       gcc -Wall -o p1 pratica_p1.c
       ./p1

   SE VOCE RODAR AGORA, ANTES DE PREENCHER:
   as colunas das duas buscas saem com indice -1 e 0 comparacoes, porque
   os dois TODO estao vazios. Isso e o esperado. O que interessa agora e
   que o programa COMPILOU e RODOU. Se apareceu erro de compilacao em vez
   das tabelas, chame o professor antes de escrever qualquer coisa.

   A unica parte que ja funciona desde agora e a QUESTAO 3 - a busca do
   colega, que compila, roda e mesmo assim responde errado.
   ================================================================== */
#include <stdio.h>

#define MAX 1000000        /* o vetor tem espaco para 1 milhao de numeros */

int v[MAX]; /* O VETOR de matriculas. Ja esta criado. */

/* O CONTADOR GLOBAL de comparacoes, o mesmo da Atividade 4: uma variavel
   fora de todas as funcoes, que qualquer funcao pode somar 1. O main zera
   esta variavel antes de cada busca. Voce nao precisa zerar. */
long long int comparacoes = 0;


/* ==================================================================
   JA ESTA PRONTO - nao mexa.

   Preenche o vetor com matriculas ficticias, EM ORDEM CRESCENTE:

       v[0] = 100    v[1] = 105    v[2] = 110    v[3] = 115  ...

   Ou seja: v[i] = 100 + i * 5. Sai ordenado sozinho - e por isso que a
   busca binaria pode ser usada aqui.
   ================================================================== */
void preencheVetor(int n) {
    int i;
    for (i = 0; i < n; i++)
        v[i] = 100 + i * 5;
}


/* ==================================================================
   TODO 1 - BUSCA SEQUENCIAL

   Percorre o vetor da posicao 0 ate a posicao n-1 procurando o numero x.
   - se achar, devolve o INDICE onde achou e para ali mesmo;
   - se chegar ao fim sem achar, devolve -1.

   ANTES de cada teste  v[i] == x  some 1 no contador. O teste acontece
   toda vez que a pergunta e feita, inclusive quando a resposta e NAO.
   ================================================================== */
int buscaSequencial(int n, int x) {
    return -1;
}


/* ==================================================================
   TODO 2 - BUSCA BINARIA

   O jogo de adivinhar o numero: olha o do MEIO do trecho que sobrou e,
   com UMA comparacao, joga fora metade do vetor.

   - lo ("low") e o comeco do trecho que ainda pode conter x;
   - hi ("high") e o fim desse trecho;
   - mid e o meio: (lo + hi) / 2;
   - enquanto o trecho nao acabar (lo <= hi):
         some 1 no contador;
         se v[mid] == x, achou: devolve mid;
         se v[mid] < x, o x so pode estar na metade da DIREITA: lo = mid + 1;
         senao, o x so pode estar na metade da ESQUERDA: hi = mid - 1;
   - se o trecho acabar, devolve -1.
   ================================================================== */
int buscaBinaria(int n, int x) {
    int lo = 0;
    int hi = n - 1;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        comparacoes = comparacoes + 1;
        if (v[mid] == x)
            return mid;
        if (v[mid] < x)
            lo = mid + 1; /* o alvo so pode estar a direita */
        else
            hi = mid - 1; /* o alvo so pode estar a esquerda */
    }
    return -1;
}


/* ==================================================================
   CONSERTE - QUESTAO 3: a busca binaria do colega

   Esta funcao esta ESCRITA e FUNCIONANDO: compila sem nenhum aviso e
   roda ate o fim. Mesmo assim responde errado - e pior: responde certo
   em alguns alvos e errado em outros.

   Rode o programa PRIMEIRO, sem mexer em nada, e anote o que a tabela da
   QUESTAO 3 devolveu. Depois compare esta funcao com a sua busca binaria
   do TODO 2, linha por linha, ache A UNICA linha diferente e conserte.
   Rode de novo e confira que agora as quatro linhas batem.
   ================================================================== */
int buscaBinariaDoColega(int n, int x) {
    int lo = 0;
    int hi = n - 1;
    int mid;

    while (lo < hi) {
        mid = (lo + hi) / 2;
        comparacoes = comparacoes + 1;

        if (v[mid] == x)
            return mid;
        if (v[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}


/* ==================================================================
   DAQUI PARA BAIXO ESTA TUDO PRONTO. NAO PRECISA MEXER.
   ================================================================== */

/* imprime uma linha da tabela: roda as duas buscas e conta separado */
void linha(const char *rotulo, int n, int x) {
    int is, ib;
    long long int cs, cb;

    comparacoes = 0;
    is = buscaSequencial(n, x);
    cs = comparacoes;

    comparacoes = 0;
    ib = buscaBinaria(n, x);
    cb = comparacoes;

    printf("%-16s | %8d | %8d | %9lld | %8d | %9lld\n",
           rotulo, x, is, cs, ib, cb);
}

void cabecalho(void) {
    printf("alvo             |    valor | seq: ind | seq: comp | bin: ind | bin: comp\n");
    printf("-----------------|----------|----------|-----------|----------|----------\n");
}

int main(void) {
    int tamanhos[4] = {1000, 10000, 100000, 1000000};
    int alvos[4];
    int k, n, i, ic;
    long long int cc;
    char rotulo[32];

    /* ---------------- QUESTOES 1 e 2: o vetor pequeno ---------------- */
    n = 9;
    preencheVetor(n);

    printf("=== QUESTOES 1 e 2: conferindo no vetor pequeno (9 matriculas) ===\n");
    printf("vetor:  ");
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\nindice:   ");
    for (i = 0; i < n; i++)
        printf("%-4d", i);
    printf("\n\n");
    cabecalho();
    linha("o primeiro", n, v[0]);
    linha("o do meio", n, v[n / 2]);
    linha("o ultimo", n, v[n - 1]);
    linha("nao existe", n, 102);

    /* ---------------- QUESTAO 4-a: os quatro alvos, n grande --------- */
    n = 100000;
    preencheVetor(n);

    printf("\n=== QUESTAO 4-a: os mesmos quatro alvos, com n = 100.000 ===\n");
    cabecalho();
    linha("o primeiro", n, v[0]);
    linha("o do meio", n, v[n / 2]);
    linha("o ultimo", n, v[n - 1]);
    linha("nao existe", n, 102);

    /* ---------------- QUESTAO 4-b: n crescendo, alvo inexistente ----- */
    printf("\n=== QUESTAO 4-b: o alvo QUE NAO EXISTE, com n crescendo ===\n");
    printf("          n | sequencial: comp | binaria: comp\n");
    printf("------------|------------------|--------------\n");
    for (k = 0; k < 4; k++) {
        n = tamanhos[k];
        preencheVetor(n);

        comparacoes = 0;
        buscaSequencial(n, 102);
        printf("%11d | %16lld |", n, comparacoes);

        comparacoes = 0;
        buscaBinaria(n, 102);
        printf(" %13lld\n", comparacoes);
    }

    /* ---------------- QUESTAO 3: a busca do colega ------------------- */
    n = 9;
    preencheVetor(n);

    printf("\n=== QUESTAO 3: a busca binaria do colega, no vetor de 9 ===\n");
    printf("alvo             |    valor | indice devolvido | comparacoes\n");
    printf("-----------------|----------|------------------|------------\n");
    alvos[0] = v[0];
    alvos[1] = v[n / 2];
    alvos[2] = v[n - 1];
    alvos[3] = 102;

    for (k = 0; k < 4; k++) {
        switch (k) {
            case 0: sprintf(rotulo, "o primeiro");
                break;
            case 1: sprintf(rotulo, "o do meio");
                break;
            case 2: sprintf(rotulo, "o ultimo");
                break;
            default: sprintf(rotulo, "nao existe");
                break;
        }

        comparacoes = 0;
        ic = buscaBinariaDoColega(n, alvos[k]);
        cc = comparacoes;
        printf("%-16s | %8d | %16d | %11lld\n", rotulo, alvos[k], ic, cc);
    }

    return 0;
}
