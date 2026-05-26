/*                   RA: 2040482513034 - Pedro Rossi Sales Sobrinho                 */
/*----------------------------------------------------------------------------------*/
/*                                FATEC - Ipiranga                                  */
/*                            ADS - Estrutura de Dados                              */
/*                             ID da Atividade: N2-3                                */
/*             Objetivo: Consolidação de Competências em Linguagem C                */
/*                                                                                  */
/*                       Autor: Pedro Rossi Sales Sobrinho                          */
/*                                                                  Data:19/05/2026 */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

// Variavel global usada para contar quantos movimentos foram realizados
long long movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar, int nivel) {
    // Quando existir apenas 1 disco, basta mover diretamente
    if (n == 1) {
        // Cria a indentacao visual baseada na profundidade
        for (int i = 0; i < nivel * 2; i++) {
            printf(" ");
        }

        // Exibe o movimento realizado
        printf("[Nivel %d] Mover disco 1 de %c para %c\n", nivel,origem, destino);

        // Incrementa o contador de movimentos
        movimentos++;

        return;
    }

    // Move n - 1 discos da origem para a haste auxiliar
    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    // Cria a indentacao visual
    for (int i = 0; i < nivel * 2; i++) {
        printf(" ");
    }

    // Move o maior disco atual para a haste destino
    printf("[Nivel %d] Mover disco %d de %c para %c\n", nivel, n, origem, destino);

    // Conta o movimento realizado
    movimentos++;

    // Move os discos da haste auxiliar para a haste destino
    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main() {
    // Teste com 1 disco
    printf("===== TESTE COM N = 1 =====\n\n");

    // Reinicia o contador
    movimentos = 0;

    hanoi(1, 'A', 'C', 'B', 0);

    printf("\nTotal de movimentos: %lld\n\n", movimentos);

    // Teste com 3 discos
    printf("===== TESTE COM N = 3 =====\n\n");

    // Reinicia o contador
    movimentos = 0;

    hanoi(3, 'A', 'C', 'B', 0);

    printf("\nTotal de movimentos: %lld\n\n", movimentos);

    // Teste com 4 discos
    printf("===== TESTE COM N = 4 =====\n\n");

    // Reinicia o contador
    movimentos = 0;

    hanoi(4, 'A', 'C', 'B', 0);

    printf("\nTotal de movimentos: %lld\n\n", movimentos);

    /*
    ========================================================
    TABELA DE COMPLEXIDADE
    ========================================================

    n    |Movimentos (contado)    |2^n - 1 (esperado)
    1    |1                       |1
    2    |3                       |3
    3    |7                       |7
    4    |15                      |15
    5    |31                      |31
    6    |63                      |63
    */

    return 0;
}
