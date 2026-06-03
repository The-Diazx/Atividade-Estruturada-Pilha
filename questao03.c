#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dados[MAX];
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

void empilhar(Pilha *p, char c) {
    if (estaCheia(p)) {
        return;
    }
    p->dados[++p->topo] = c;
}

char desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        return '\0';
    }
    return p->dados[p->topo--];
}

int main(void) {
    Pilha p;
    inicializar(&p);

    char palavra[MAX];
    printf("Digite uma palavra: ");
    if (fgets(palavra, sizeof(palavra), stdin) == NULL) {
        return 1;
    }

    size_t tamanho = strlen(palavra);
    if (tamanho > 0 && palavra[tamanho - 1] == '\n') {
        palavra[--tamanho] = '\0';
    }

    if (tamanho == 0) {
        printf("Nenhuma palavra informada.\n");
        return 0;
    }

    size_t meio = tamanho / 2;
    for (size_t i = 0; i < meio; i++) {
        empilhar(&p, palavra[i]);
    }

    size_t inicioSegundaMetade = (tamanho % 2 == 0) ? meio : meio + 1;
    int palindromo = 1;

    for (size_t i = inicioSegundaMetade; i < tamanho; i++) {
        char topo = desempilhar(&p);
        if (topo != palavra[i]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo) {
        printf("A palavra '%s' e um palindromo.\n", palavra);
    } else {
        printf("A palavra '%s' nao e um palindromo.\n", palavra);
    }

    return 0;
}
