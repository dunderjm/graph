#include <stdio.h>
#include <stdlib.h>
#include "include/auxiliar.h"
#include "include/fila.h"
#include "include/pilha.h"
#include "include/grafo.h"

bool busca_largura(GRAFO *gr, int inicial, int num){
    FILA *fila_pesquisa = (FILA *)malloc(sizeof(FILA));
    initFila(fila_pesquisa);
    int verificados[gr->vertices];
    for(int i = 0; i< gr->vertices; i++){
        verificados[i] = 0;
    }
    enqueue(fila_pesquisa, inicial);
    while(fila_pesquisa->inicio != NULL){
        int atual;
        dequeue(fila_pesquisa, &atual);
        if (verificados[atual] != 1){
            if (atual == num){
                return true;
            } else{
                verificados[atual] = 1;
                ADJACENCIA *ad = gr->adj[atual].cab;
                while (ad){
                    enqueue(fila_pesquisa, ad->vertice);
                    ad = ad->prox;
                }
            }
        }
    }
    return false;
}

bool busca_profundidade(GRAFO *gr, int inicial, int num){
    PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));
    int verificados[gr->vertices];
    for (int i = 0; i < gr->vertices; i++)
    {
        verificados[i] = 0;
    }
    push(pilha, inicial);

    while (!esta_vazia(pilha))
    {
        int atual;
        pop(pilha, &atual);
        if (verificados[atual] != 1)
        {
            if (atual == num)
            {
                return true;
            }
            else
            {
                verificados[atual] = 1;
                ADJACENCIA *ad = gr->adj[atual].cab;
                while (ad)
                {
                    push(pilha, ad->vertice);
                    ad = ad->prox;
                }
            }
        }
    }
    return false;
}


int main(){
    GRAFO *gr = cria_grafo(5); //Numero de arestas
    criaAresta(gr, 0, 2, 1); //(grafo, vertice, vertice_adjacente, peso)
    criaAresta(gr, 0, 1, 1);
    criaAresta(gr, 2, 3, 1);
    criaAresta(gr, 2, 4, 1);
    if(busca_profundidade(gr, 0, 4)) //vertice inicial, vertice procurado
        printf("Achou!\n"); 
    else
        printf("Não achou!\n");
    
}