
#define true 1
#define false 0
typedef int bool;

typedef struct
{
    PONT topo;
} PILHA;

void init_pilha(PILHA *p)
{
    p->topo = NULL;
}

bool esta_vazia(PILHA *p)
{
    if (p->topo == NULL)
        return true;
    return false;
}

bool push(PILHA *p, int data)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->data = data;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool pop(PILHA *p, int *data)
{
    if (esta_vazia(p))
        return false;
    *data = p->topo->data;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

void reiniciar_pilha(PILHA *p)
{
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL)
    {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}