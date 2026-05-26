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

// Funcao que troca os valores de duas variaveis usando ponteiros.
void trocar(int *a, int *b) {
    // *a acessa o valor armazenado no endereco apontado por a
    *a = *a + *b;

    // *b acessa o valor armazenado no endereco apontado por b
    *b = *a - *b;

    // *a acessa o valor armazenado no endereco apontado por a
    *a = *a - *b;
}

int main() {
    int x = 10;
    int y = 20;

    printf("===== TROCA DE VALORES =====\n\n");
    printf("Antes da troca:\n");
    // &x retorna o endereco de memoria da variavel x
    printf("Endereco de x: %p | Valor: %d\n", (void*)&x, x);

    // &y retorna o endereco de memoria da variavel y
    printf("Endereco de y: %p | Valor: %d\n", (void*)&y, y);

    // &x envia o endereco de x para a funcao
    // &y envia o endereco de y para a funcao
    trocar(&x, &y);

    printf("\nDepois da troca:\n");

    // &x retorna o endereco de memoria da variavel x
    printf("Endereco de x: %p | Valor: %d\n", (void*)&x, x);

    // &y retorna o endereco de memoria da variavel y
    printf("Endereco de y: %p | Valor: %d\n", (void*)&y, y);

    return 0;
}
