#include <stdio.h>

// Calcula potencia usando recursao e divisao do expoente pela metade
long long potenciaRapida(long long base, int expoente) {
    // Caso base
    if(expoente == 0)
        return 1;

    // Caso base
    if(expoente == 1)
        return base;

    // Expoente impar
    if(expoente % 2 != 0) 
        return base * potenciaRapida(base, expoente - 1);

    // Expoente par
    long long metade = potenciaRapida(base, expoente / 2);

    return metade * metade;
}

int main() {
    long long base = 28;
    int expoente = 6;
    long long resultado;

    // Chama a funcao potenciaRapida e armazena o valor em resultado
    resultado = potenciaRapida(base, expoente);

    printf("Base: %lld\n", base);
    printf("Expoente: %d\n", expoente);
    printf("Resultado: %lld\n", resultado);

    return 0;
}
