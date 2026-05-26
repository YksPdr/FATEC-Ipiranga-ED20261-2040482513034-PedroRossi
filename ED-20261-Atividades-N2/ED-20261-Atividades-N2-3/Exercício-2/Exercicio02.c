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

// Calcula a media do vetor
float calcularMedia(float *vet, int n) {
    int i;
    float media = 0;

    // Soma todos os elementos
    for(i = 0; i < n; i++, vet++) {
        media += *vet;
    }

    // Calcula a media
    media = media / n;

    return media;
}


// Encontra maior e menor valor
void encontrarExtremos(float *vet, int n, float *maior, float *menor) {
    int i;

    // Percorre o vetor
    for(i = 0; i < n; i++, vet++) {
        // Atualiza o maior valor
        if(*vet > *maior) {
            *maior = *vet;
        }

        // Atualiza o menor valor
        if(*vet < *menor) {
            *menor = *vet;
        }
    }
}

// Normaliza os elementos do vetor
void normalizar(float *vet, int n) {
    int i;

    // Primeiro valor do vetor
    float maior = *vet;

    // Guarda o inicio do vetor
    float *inicio = vet;

    // Procura o maior valor
    for(i = 0; i < n; i++, vet++) {
        if(*vet > maior) {
            maior = *vet;
        }
    }

    // Retorna ao inicio do vetor
    vet = inicio;

    // Divide os elementos pelo maior valor
    for(i = 0; i < n; i++, vet++) {
        *vet = *vet / maior;
    }
}

// Imprime o vetor
void imprimirVetor(float *vet, int n, const char *titulo) {
    int i;

    printf("\n%s\n", titulo);
    printf("Vetor: ");

    // Exibe os elementos
    for (i = 0; i < n; i++, vet++) {
        printf("%.2f ", *vet);
    }

    printf("\n");
}

int main() {
    // Vetor original
    float notas[] = { 7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f };

    // Variaveis de controle
    float maior = notas[0];
    float menor = notas[0];

    // Ponteiro para o vetor
    float *vet = notas;

    // Vetor antes da normalizacao
    imprimirVetor(vet, 6, "ANTES DA NORMALIZACAO");

    // Encontra maior e menor
    encontrarExtremos(vet, 6, &maior, &menor);

    // Exibe resultados
    printf("\nMedia: %.2f\n", calcularMedia(vet, 6));
    printf("Maior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);

    
    // Como o vetor passa por um ponteiro, a funcao altera diretamente os valores originais na memoria
    normalizar(vet, 6);

    // Vetor depois da normalizacao
    imprimirVetor(vet, 6, "DEPOIS DA NORMALIZACAO");

    return 0;
}
