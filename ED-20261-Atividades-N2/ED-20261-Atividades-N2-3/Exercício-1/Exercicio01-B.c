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

int main() {
    int v[] = {10, 20, 30, 40, 50};

    // Ponteiro para o inicio do vetor
    int *inicio = v;

    // Ponteiro para o final do vetor
    int *fim = v + 4;

    // Variavel para armazenar a soma
    int soma = 0;

    printf("===== ELEMENTOS DO VETOR =====\n\n");

    // Percorre o vetor usando ponteiros
    for (int *ptr = v; ptr < v + 5; ptr++) {
        printf("Valor: %d | Endereco: %p\n", *ptr, (void*)ptr);

        // Soma os elementos
        soma += *ptr;
    }

    printf("\nSoma dos elementos: %d\n", soma);
    printf("\n===== INVERTENDO O VETOR =====\n\n");

    // Inverte o vetor
    while (inicio < fim) {
        // Troca os valores, usando aritmética de inteiros
        *inicio = *inicio + *fim;
        *fim = *inicio - *fim;
        *inicio = *inicio - *fim;

        // Avanca no inicio
        inicio++;

        // Retrocede no final
        fim--;
    }

    printf("Vetor invertido:\n");

    // Exibe o vetor invertido
    for (int *ptr = v; ptr < v + 5; ptr++) {
        printf("%d ", *ptr);
    }

    printf("\n");

    return 0;
}
