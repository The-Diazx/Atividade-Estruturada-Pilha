#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (!estaCheia(p)) {
        p->dados[++p->topo] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        return 0;
    }
    return p->dados[p->topo--];
}

int aplicarOperador(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
    }
    return 0;
}

int main(void) {
    Pilha pilha;
    inicializar(&pilha);

    char expressao[MAX];
    printf("Digite a expressao em notacao polonesa reversa: ");
    if (fgets(expressao, sizeof(expressao), stdin) == NULL) {
        return 1;
    }

    size_t tamanho = strlen(expressao);
    if (tamanho > 0 && expressao[tamanho - 1] == '\n') {
        expressao[--tamanho] = '\0';
    }

    for (size_t i = 0; i < tamanho; i++) {
        char c = expressao[i];
        if (isspace((unsigned char)c)) {
            continue;
        }

        if (isdigit((unsigned char)c)) {
            empilhar(&pilha, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (pilha.topo < 1) {
                printf("Expressao invalida.\n");
                return 1;
            }
            int b = desempilhar(&pilha);
            int a = desempilhar(&pilha);
            int resultado = aplicarOperador(c, a, b);
            empilhar(&pilha, resultado);
        } else {
            printf("Caractere invalido: %c\n", c);
            return 1;
        }
    }

    if (pilha.topo != 0) {
        printf("Expressao invalida.\n");
        return 1;
    }

    printf("Resultado: %d\n", desempilhar(&pilha));
    return 0;
}
