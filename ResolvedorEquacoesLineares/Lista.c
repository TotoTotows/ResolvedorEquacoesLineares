#include <stdio.h>                                                                                                                                                                                                                                                                                                                                                                                                                                       #include <stdio.h>
#include <stdlib.h>

typedef
    struct No
    {
        void* info;
        struct No* prox;
        void* valor;
    }
    No;


typedef
    struct Lista
    {
        No* inicio;
        int (*compareTo)(void*, void*);
        void (*print)(void*);
    }
    Lista;

typedef
    enum boolean
    {
        false,
        true
    }
    boolean;

void insira(Lista* lis, void* info)
{
    if(lis==NULL)
        return;

    if(lis->inicio==NULL)
    {
        lis->inicio = (No*)malloc(sizeof(No));
        lis->inicio->info = info;
        lis->inicio->valor = NULL;
        lis->inicio->prox = NULL;

        return true;
    }

    No* atual =  lis->inicio;

    while(atual->prox!=NULL)
    {
        atual = atual->prox;
    }

    atual->prox = (No*)(malloc(sizeof(No)));
    atual->prox->info = info;
    atual->prox->valor = NULL;
    atual->prox->prox = NULL;
}

void insiraValor(Lista* lis, void* info, int pos)
{
    int i =0;

    No* atual =  (No*)(malloc(sizeof(No)));
    atual = lis->inicio;

    for(; i<pos; i++)
        if(atual->prox==NULL)
            break;
        else
            atual = atual->prox;

    atual->valor = info;
}

void printeLista(Lista lis)
{
    No* atual =  (No*)(malloc(sizeof(No*)));
    atual = lis.inicio;

    while(atual!=NULL)
    {
        printf(atual->info);
        printf(atual->valor);
        atual = atual->prox;
    }
}

void main()
{
    Lista lis;
    lis.inicio = NULL;

    insira(&lis, "x");

    insira(&lis, "y");

    insira(&lis, "z");

    insiraValor(&lis, "3", 0);

    insiraValor(&lis, "7", 1);

    insiraValor(&lis, "17", 2);

    insiraValor(&lis, "2", 1);

    printeLista(lis);
}

