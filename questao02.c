#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct 
{
char dados[MAX];
int topo;
}pilha;

void inicializar (pilha *p){
    p->topo = -1;
}

int estaVazia(pilha *p){
    return p -> topo == -1;
}

int estaCheia(pilha *p){
    return p-> topo == MAX -1;
}

void empilhar(pilha *p, char c){
if(estaCheia(p)) {
    printf("Erro: Pilha cheia!\n");
    return;
}
p-> topo++;
p-> dados[p->topo] = c;

}

char desempilhar (pilha *p){
    if (estaVazia(p)){
        return '\0';
    }
    char c = p-> dados[p->topo];
    p->topo--;
    return c;
}

int main (){ 
    pilha p;
    inicializar (&p);

    char expressao[MAX];
    printf("Digite um expressao: ");
    fgets(expressao, MAX, stdin);

    int i;
    int erro = 0;


    for (i = 0; i < strlen(expressao); i++){
        if(expressao[i] == '('){
            empilhar(&p, '(');
        }
        else if(expressao[i] == ')'){
            if(estaVazia(&p)){
                erro = 1;
                break;
            }
            desempilhar(&p);
        }
    }
    if (!estaVazia(&p)){
        erro = 1;
    }
    if(erro){
        printf("Os parenteses estao DESBALANCEADOS. \n");
    }else{
        printf("Os parenteses estao BALANCEADOS.\n");
    }
    return 0;
}

