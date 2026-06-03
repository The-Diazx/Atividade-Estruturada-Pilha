#include <stdio.h>
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

int main(void) {
    Pilha pilha;
    inicializar(&pilha);

    int numero;
    printf("Digite um numero inteiro maior que zero: ");
    if (scanf("%d", &numero) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    if (numero <= 0) {
        printf("Informe um numero maior que zero.\n");
        return 1;
    }

    int valor = numero;
    while (valor > 0) {
        int bit = valor % 2;
        empilhar(&pilha, bit);
        valor /= 2;
    }

    printf("Binario de %d = ", numero);
    if (estaVazia(&pilha)) {
        printf("0");
    } else {
        while (!estaVazia(&pilha)) {
            printf("%d", desempilhar(&pilha));
        }
    }
    printf("\n");
    return 0;
}
