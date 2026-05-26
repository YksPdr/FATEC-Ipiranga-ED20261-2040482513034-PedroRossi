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

void hanoi(int n, char origem, char destino, char auxiliar) {
    // Quando existir apenas 1 disco
    if (n == 1) {

        printf("Mover disco 1 de %c para %c\n", origem, destino);

        return;
    }

    // Move os discos para a haste auxiliar
    hanoi(n - 1, origem, auxiliar, destino);

    // Move o maior disco
    printf("Mover disco %d de %c para %c\n", n, origem, destino);

    // Move os discos para a haste destino
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    printf("===== TESTE COM N = 1 =====\n\n");
    hanoi(1, 'A', 'C', 'B');

    printf("\n===== TESTE COM N = 3 =====\n\n");
    hanoi(3, 'A', 'C', 'B');

    printf("\n===== TESTE COM N = 4 =====\n\n");
    hanoi(4, 'A', 'C', 'B');

    return 0;
}
