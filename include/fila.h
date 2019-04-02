typedef struct
{
    PONT inicio;
    PONT fim;
} FILA;

void initFila(FILA *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

int tamanho(FILA *fila)
{
    PONT end = fila->inicio;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
}

void exibirFila(FILA *fila)
{
    PONT end = fila->inicio;
    printf("Fila: \" ");
    while (end != NULL)
    {
        printf("%i ", end->data);
    }
    printf("\"\n");
}

int enqueue(FILA *f, int data)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->data = data;
    novo->prox = NULL;
    if (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return 1;
}

int dequeue(FILA *f, int *data)
{
    if (f->inicio == NULL)
        return 0;
    *data = f->inicio->data;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
     if (f->inicio == NULL)
        f->fim = NULL;
    return 1;
}