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

// Variavel global para contar os movimentos
long long movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {
    // Quando existir apenas 1 disco
    if (n == 1) {

        printf("Mover disco 1 de %c para %c\n", origem, destino);

        movimentos++;

        return;
    }

    // Move os discos para a haste auxiliar
    hanoi(n - 1, origem, auxiliar, destino);

    // Move o maior disco
    printf("Mover disco %d de %c para %c\n", n, origem, destino);

    movimentos++;

    // Move os discos para a haste destino
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    printf("===== TESTE COM N = 1 =====\n\n");
    movimentos = 0;
    hanoi(1, 'A', 'C', 'B');
    printf("\nTotal de movimentos: %lld\n\n", movimentos);

    printf("===== TESTE COM N = 3 =====\n\n");
    movimentos = 0;
    hanoi(3, 'A', 'C', 'B');
    printf("\nTotal de movimentos: %lld\n\n", movimentos);

    printf("===== TESTE COM N = 4 =====\n\n");
    movimentos = 0;
    hanoi(4, 'A', 'C', 'B');
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
