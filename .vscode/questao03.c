#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, char valor) {
    if (!estaCheia(p)) {
        p->topo++;
        p->dados[p->topo] = valor;
    }
}

char desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        char valor = p->dados[p->topo];
        p->topo--;
        return valor;
    }
    return '\0';
}

int main(){
    Pilha p; 
    inicializar(&p);
    char palavra[MAX];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tam = strlen(palavra);
    int metade = tam / 2; 
    for (int i = 0; i < metade; i ++){
        empilhar(&p, palavra[i]);
    }

    int inicioSegundaMetade = metade;
    if (tam % 2 != 0){
        inicioSegundaMetade = metade + 1;
    }

    int polidromo = 1;
    for (int i = inicioSegundaMetade; i<tam; i++){
        if (palavra[i] != desempilhar(&p)){
            polidromo = 0;
            break;
        }
    }

    if (polidromo){
        printf("A palavra:  %s  e um palindromo!", palavra);
    }else{
        printf("A palavra %s  NAO e um palindromo!", palavra);
    }
    return 0;
}