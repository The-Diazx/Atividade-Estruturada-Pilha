#include <stdio.h>
#include <stdlib.h>


#define MAX 50 

typedef struct{

    int dados[MAX];
    int topo;
}pilha;

void inicializar(pilha *p){

    p -> topo = -1;
}

int estaCheia(pilha *p){
   return p->topo == MAX -1;
}

int estaVazia(pilha *p){
    return p-> topo == -1;
}

void empilhar(pilha *p, int valor){
    if (estaCheia(p)){
        printf("Erro: Pilha cheia!\n");
        return; 
    }
    p-> topo++;
    p->dados[ p-> topo] = valor;
}

int desempilhar(pilha *p){
    if(estaVazia(p)){
        printf("Erro: Pilha Vazia!\n");
        return -1;
    }
    int valor = p-> dados[p->topo];
    p->topo--;
    return valor;
}

int main (){
    pilha p;
    inicializar(&p);
    int numero, aux;

    do{
        printf("Digite um numero inteiro maior que zero: ");
        scanf("%d", &numero);
        if(numero <= 0){
            printf("Erro: numero invalido.");
        }
    }while (numero <= 0);

        aux = numero;

     while (aux  > 0){
        
            int resto = aux % 2;
            empilhar(&p, resto);
            aux = aux / 2;
        }
        printf("O numero %d em binario é: ", numero);
        while(!estaVazia(&p)){
            printf("%d", desempilhar(&p));
        }
        printf("\n");
        return 0;
}