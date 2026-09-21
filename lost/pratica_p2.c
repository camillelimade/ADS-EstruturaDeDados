/* ==================================================================
   Algoritmos Avancados (ADS26) - 2026.2 - Aula 07 (18/09/2026)
   PRATICA DIRIGIDA DE PREPARACAO PARA A AV2 - PARTE 2 (bloco CD)
   Ordenacao por selecao e ordenacao por insercao

   ESTE ARQUIVO ESTA INCOMPLETO DE PROPOSITO.
   Voce vai preencher os DOIS blocos marcados com TODO e consertar UMA
   linha no bloco marcado com CONSERTE. Nada mais.
   Nao mexa no main: ele ja esta pronto e ja imprime as tabelas.

   Como compilar e rodar (no terminal, na pasta do arquivo):
       gcc -Wall -o p2 pratica_p2.c
       ./p2

   SE VOCE RODAR AGORA, ANTES DE PREENCHER:
   as tabelas saem todas com ZERO e aparecem varias linhas dizendo que o
   vetor nao ficou ordenado. Isso e o esperado: os TODO estao vazios,
   entao nada foi comparado, nada foi movido e nada foi ordenado. O que
   interessa agora e que o programa COMPILOU e RODOU. Se apareceu erro de
   compilacao em vez das tabelas, chame o professor antes de escrever
   qualquer coisa.

   A unica parte que ja funciona desde agora e a QUESTAO 7 - a insercao
   do colega, que compila, roda e mesmo assim estraga o vetor.
   ================================================================== */
#include <stdio.h>

#define MAX 8000            /* o vetor tem espaco para 8000 numeros */

int v[MAX];                 /* O VETOR que vai ser ordenado. Ja esta criado. */
int original[MAX];          /* uma copia intacta, para refazer os testes */

/* OS DOIS CONTADORES GLOBAIS, os mesmos da Atividade 5.
   comparacoes   -> quantas vezes o algoritmo COMPAROU dois numeros do vetor.
   movimentacoes -> na SELECAO conta TROCAS; na INSERCAO conta DESLOCAMENTOS.
   O main zera os dois antes de cada ordenacao. Voce nao precisa zerar. */
long long int comparacoes = 0;
long long int movimentacoes = 0;


/* ==================================================================
   JA ESTA PRONTO - nao mexa. E a mesma funcao da Atividade 5.
   Troca o conteudo de v[i] com o conteudo de v[j], usando o "copo
   vazio" aux. Nao soma nada nos contadores: quem conta a troca e o
   algoritmo que chamou.
   ================================================================== */
void trocar(int i, int j)
{
    int aux;

    aux  = v[i];
    v[i] = v[j];
    v[j] = aux;
}
/* ==================================================================
   TODO 1 - ORDENACAO POR SELECAO, MAS DO MAIOR PARA O MENOR

   ATENCAO: esta NAO e a selecao da Atividade 5. Aqui o vetor tem de
   terminar em ordem DECRESCENTE:  9  8  7  4  3  1

   E a mesma mecanica, virada do avesso: para cada posicao i, ache o
   MAIOR valor do trecho que vai de i ate o fim e traga esse valor para
   a posicao i.

   - o laco de fora anda com i, de 0 ate n-2 (a ultima posicao sobra
     pronta sozinha, por isso "i < n - 1");
   - "maior" guarda o INDICE do maior valor achado ate agora; ele comeca
     valendo i (chute inicial: o maior e o proprio v[i]);
   - o laco de dentro anda com j, de i+1 ate n-1, e a cada volta compara
     v[j] com v[maior];
   - some 1 em 'comparacoes' A CADA comparacao, ANTES do if;
   - terminado o laco de dentro, some 1 em 'movimentacoes' e chame
     trocar(i, maior).
   ================================================================== */
void selectionSortDecrescente(int n){
    int i, j, maior;
    for (i = 0; i < n - 1; i++) {
        maior = i;
        for (j = i + 1; j < n; j++) {
            comparacoes += 1;
            if (v[j] > v[maior])
                maior = j;
        }
        movimentacoes += 1;
        trocar(i, maior);
    }
}


/* ==================================================================
   TODO 2 - ORDENACAO POR INSERCAO (crescente, como na aula)

   A mao de cartas: a parte da esquerda ja esta arrumada. Pegue a
   proxima carta (a "chave"), ande para tras empurrando para a direita
   todo mundo que for maior que ela, e solte a chave no buraco que ficou.

   ONDE SOMAR NOS CONTADORES:
   - dentro do while, some 1 em 'comparacoes' (a pergunta deu SIM) e 1
     em 'movimentacoes' (voce empurrou um numero);
   - DEPOIS do while, a pergunta que FEZ O LACO PARAR tambem foi uma
     comparacao - mas so quando ele parou porque achou o lugar. Se parou
     porque i chegou a -1, nao houve comparacao nenhuma. Por isso o
     "if (i >= 0) comparacoes = comparacoes + 1;".
   ================================================================== */
void insertionSort(int n)
{
    int i, j, chave;
    for (j = 1; j < n; j++) {
        chave = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > chave) {
            comparacoes = comparacoes + 1;
            movimentacoes = movimentacoes + 1;
            v[i + 1] = v[i];
            i = i - 1;
        }
        if (i >= 0) /* parou por achar o lugar */
            comparacoes = comparacoes + 1;
        v[i + 1] = chave;
    }
}
/* ==================================================================
   CONSERTE - QUESTAO 7: a insercao do colega

   Esta funcao esta ESCRITA e FUNCIONANDO: compila sem nenhum aviso e
   roda ate o fim. Mesmo assim ela nao ordena - ela ESTRAGA o vetor.

   Rode o programa PRIMEIRO, sem mexer em nada, e anote o vetor que a
   QUESTAO 7 devolveu. Depois compare esta funcao com a sua insercao do
   TODO 2, linha por linha, ache A UNICA diferenca e conserte.
   ================================================================== */
void insertionSortDoColega(int n)
{
    int i, j, menor;
    for (j = 1; j < n; j++) {
        menor = v[j];
        i = j - 1;
        while (i >= 0 && v[i] > menor) {
            comparacoes += 1;
            movimentacoes += 1;
            v[i + 1] = v[i];
            i -= 1;
        }

        if (i >= 0)
            comparacoes += 1;

        v[i + 1] = menor;
    }
    }



/* ==================================================================
   DAQUI PARA BAIXO ESTA TUDO PRONTO. NAO PRECISA MEXER.
   ================================================================== */

void montaCrescente(int n)
{
    int i;
    for (i = 0; i < n; i++)
        original[i] = i * 2;
}

void montaDecrescente(int n)
{
    int i;
    for (i = 0; i < n; i++)
        original[i] = (n - 1 - i) * 2;
}

void copia(int n)
{
    int i;
    for (i = 0; i < n; i++)
        v[i] = original[i];
}

int estaCrescente(int n)
{
    int i;
    for (i = 1; i < n; i++)
        if (v[i - 1] > v[i])
            return 0;
    return 1;
}

int estaDecrescente(int n)
{
    int i;
    for (i = 1; i < n; i++)
        if (v[i - 1] < v[i])
            return 0;
    return 1;
}

void mostra(int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
}

void bloco(const char *titulo, void (*monta)(int))
{
    int tamanhos[4] = {1000, 2000, 4000, 8000};
    int k, n;
    long long int sc, sm, ic, im;

    printf("\n=== %s ===\n", titulo);
    printf("       n | selecao comp | selecao troc | insercao comp | insercao desl\n");
    printf("---------|--------------|--------------|---------------|--------------\n");

    for (k = 0; k < 4; k++) {
        n = tamanhos[k];
        monta(n);

        copia(n);
        comparacoes = 0; movimentacoes = 0;
        selectionSortDecrescente(n);
        sc = comparacoes; sm = movimentacoes;
        if (!estaDecrescente(n))
            printf("  (a selecao NAO deixou o vetor em ordem decrescente)\n");

        copia(n);
        comparacoes = 0; movimentacoes = 0;
        insertionSort(n);
        ic = comparacoes; im = movimentacoes;
        if (!estaCrescente(n))
            printf("  (a insercao NAO deixou o vetor em ordem crescente)\n");

        printf("%8d | %12lld | %12lld | %13lld | %13lld\n", n, sc, sm, ic, im);
    }
}

int main(void)
{
    int pequeno[6] = {4, 9, 1, 7, 3, 8};
    int i;

    printf("=== QUESTOES 5 e 6: conferindo no vetor pequeno ===\n");
    printf("antes:                  ");
    for (i = 0; i < 6; i++) printf("%d ", pequeno[i]);
    printf("\n");

    for (i = 0; i < 6; i++) v[i] = pequeno[i];
    comparacoes = 0; movimentacoes = 0;
    selectionSortDecrescente(6);
    printf("selecao decrescente ->  ");
    mostra(6);
    printf("  comparacoes: %lld   trocas: %lld\n", comparacoes, movimentacoes);

    for (i = 0; i < 6; i++) v[i] = pequeno[i];
    comparacoes = 0; movimentacoes = 0;
    insertionSort(6);
    printf("insercao crescente  ->  ");
    mostra(6);
    printf("  comparacoes: %lld   deslocamentos: %lld\n", comparacoes, movimentacoes);

    bloco("QUESTAO 8-a: o vetor chega em ordem CRESCENTE", montaCrescente);
    bloco("QUESTAO 8-b: o vetor chega em ordem DECRESCENTE", montaDecrescente);

    printf("\n=== QUESTAO 7: a insercao do colega, no vetor pequeno ===\n");
    printf("antes:                  ");
    for (i = 0; i < 6; i++) printf("%d ", pequeno[i]);
    printf("\n");

    for (i = 0; i < 6; i++) v[i] = pequeno[i];
    comparacoes = 0; movimentacoes = 0;
    insertionSortDoColega(6);
    printf("insercao do colega  ->  ");
    mostra(6);
    printf("  comparacoes: %lld   deslocamentos: %lld\n", comparacoes, movimentacoes);

    return 0;
}
