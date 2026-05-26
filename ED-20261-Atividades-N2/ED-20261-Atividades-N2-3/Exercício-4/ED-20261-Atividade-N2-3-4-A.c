#include <stdio.h>

// Contador de chamadas recursivas
int cont = 0;

int buscaBinaria(int *vet, int inicio, int fim, int alvo) {
    // Conta a chamada atual
    cont++;

    // Caso base
    if(inicio > fim) 
        return -1;

    // Calcula o indice do meio
    int meio = (inicio + fim) / 2;

    // Valor encontrado
    if(*(vet + meio) == alvo) 
        return meio;

    // Busca na esquerda
    if(alvo < *(vet + meio)) 
        return buscaBinaria(vet, inicio, meio - 1, alvo);

    // Busca na direita
    return buscaBinaria(vet, meio + 1, fim, alvo);
}

int main() {
    int dados[] = { 2, 5, 8, 12, 16, 23, 38, 45, 72, 91 };
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int resultado;

    // Busca por valor presente
    cont = 0;

    resultado =
        buscaBinaria(dados, 0, tamanho - 1, 23);

    printf("Busca por 23:\n");
    printf("Indice: %d\n", resultado);
    printf("Chamadas: %d\n\n", cont);

    // Busca por valor ausente
    cont = 0;

    resultado = buscaBinaria(dados, 0, tamanho - 1, 50);

    printf("Busca por 50:\n");
    printf("Indice: %d\n", resultado);
    printf("Chamadas: %d\n\n", cont);

    // Busca pelo primeiro valor
    cont = 0;

    resultado = buscaBinaria(dados, 0, tamanho - 1, 2);

    printf("Busca por 2:\n");
    printf("Indice: %d\n", resultado);
    printf("Chamadas: %d\n", cont);

    return 0;
}