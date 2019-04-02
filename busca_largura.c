#include <stdio.h>
#include <stdlib.h>
#include "include/auxiliar.h"
#include "include/fila.h"
#include "include/grafo.h"


void busca_largura(GRAFO *gr, int inicial, int *verificados){
    FILA *f = (FILA *)malloc(sizeof(FILA));
    initFila(f);
    int profundidade = 1;
    for(int i = 0;i < gr->vertices; i++){
        verificados[i] = 0;
    }
    verificados[inicial] = profundidade;
    profundidade += 1;
    enqueue(f, inicial);
    while(f->inicio != NULL){
        int data;
        dequeue(f, &data);
        ADJACENCIA *ad = gr->adj[data].cab;
        while (ad){        
            if(verificados[ad->vertice] == 0){
                verificados[ad->vertice] = profundidade;
                enqueue(f, ad->vertice);
            }
            ad = ad->prox;
        }
        profundidade++;
    }

}


int main(){
    GRAFO *gr = cria_grafo(5); //Numero de arestas
    criaAresta(gr, 0, 1, 1);
    criaAresta(gr, 1, 3, 1);
    criaAresta(gr, 1, 2, 1);
    criaAresta(gr, 2, 4, 1);
    criaAresta(gr, 3, 0, 1);
    criaAresta(gr, 3, 4, 1);
    criaAresta(gr, 4, 1, 1);

    int* distancia = (int*) malloc(gr->vertices*sizeof(int));

    busca_largura(gr, 0, distancia);
    printf("\nVertices:  ");
    for(int i = 0; i< gr->vertices; i++){
        printf("%d ", i);
    } 
    printf("\nDistancia: ");
    for (int i = 0; i < gr->vertices; i++){
        printf("%d ", distancia[i]);
    }
    printf("\n");
}