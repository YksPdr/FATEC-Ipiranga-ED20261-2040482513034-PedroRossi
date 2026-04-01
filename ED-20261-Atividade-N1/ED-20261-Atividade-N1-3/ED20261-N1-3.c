/*----------------------------------------------------------------------------------*/
/*                                FATEC-Ipiranga                                    */        
/*                            ADS - Estrutura de Dados                              */
/*                             ID da Atividade: 3? (n sei prof)                     */
/*             Objetivo: Criar o código com conceitos de Pilha (Stack) e RPN        */
/*                                                                                  */
/*                            Autor: Pedro Rossi Sales Sobrinho                     */
/*                                                                   Data:30/03/2026*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    double X, Y, Z, T;
} Pilha;

void inicializar(Pilha *p) {
    p -> X = p -> Y = p -> Z = p -> T = 0.0;
}

void mostrarPilha(Pilha *p) {
    printf("\n--- Estado da Pilha ---\n");
    printf("T: %.2lf\n", p->T);
    printf("Z: %.2lf\n", p->Z);
    printf("Y: %.2lf\n", p->Y);
    printf("X: %.2lf\n", p->X);
    printf("-----------------------\n");
}

void push(Pilha *p, double valor) {
    p -> T = p -> Z;
    p -> Z = p -> Y;
    p -> Y = p -> X;
    p -> X = valor;
}

int operar(Pilha *p, char op) {
    double a = p -> X;
    double b = p -> Y;
    double resultado;

    switch(op) {
        case '+':
            resultado = b + a;
            break;
        case '-':
            resultado = b - a;
            break;
        case '*':
            resultado = b * a;
            break;
        case '/':
            if (a == 0) {
                printf("Erro: Divisão por zero!\n");
                return 0;
            }
            
            resultado = b / a;
            break;
        default:
            printf("Operador inválido: %c\n", op);
            
            return 0;
    }

    p -> X = resultado;
    p -> Y = p -> Z;
    p -> Z = p -> T;
    p -> T = 0;

    return 1;
}

int verificarNumero(char *token) {
    if (isdigit(token[0]) || 
       (token[0] == '-' && isdigit(token[1])))
        return 1;
    return 0;
}

int main() {
    char expressao[MAX];
    char *token;

    Pilha p;
    inicializar(&p);

    printf("Digite a expressão em RPN:\n");
    fgets(expressao, MAX, stdin);

    token = strtok(expressao, " \n");

    while (token != NULL) {
        if (verificarNumero(token)) {
            double valor = atof(token);
            printf("\nEntrada número: %s\n", token);
            push(&p, valor);
        }
        else if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            printf("\nOperador: %s\n", token);

            if (!operar(&p, token[0])) {
                printf("Erro na operação.\n");
                return 1;
            }
        }
        else {
            printf("Token inválido: %s\n", token);
            return 1;
        }

        mostrarPilha(&p);
        token = strtok(NULL, " \n");
    }

    printf("\nResultado final (X): %.2lf\n", p.X);

    return 0;
}
