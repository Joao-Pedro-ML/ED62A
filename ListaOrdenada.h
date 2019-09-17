
#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  {
  int chave;
} Objeto;

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    Objeto elemento;
    PtrNoLista proximo;
} NoLista;

typedef struct {
    PtrNoLista primeiro;
    int tamanho;
} Lista;

void iniciaLista(Lista *list){
    list->primeiro = NULL;
    list->tamanho = 0;
}

void inserir(Lista *list, Objeto x){
    
    PtrNoLista novo;
    novo = (PtrNoLista) malloc(sizeof (NoLista));
    novo->elemento.chave = x.chave;
    if(list->tamanho == 0 || x.chave < list->primeiro->elemento.chave){
        novo->proximo = list->primeiro;
        list->primeiro = novo;
        list->tamanho++;
    } else{
        PtrNoLista aux;
        aux = list->primeiro;
        while(aux->proximo != NULL && x.chave > aux->proximo->elemento.chave){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo =novo;
        list->tamanho++;
    }
}

void imprimirLista(Lista *list){
    PtrNoLista aux;
    printf("\n[");
    printf("%i", list->primeiro->elemento.chave);
    for(aux = list->primeiro; aux != NULL; aux = aux->proximo){
        printf(" %i ", aux->elemento.chave);
    }
    printf("]\n");
}

void destruir(Lista *list){
    PtrNoLista aux;
    while(aux!=NULL){
        aux = list->primeiro;
        list->primeiro = list->primeiro->proximo;
        free(aux);
    }
}

bool estaVazia(Lista *list){
    return(list->tamanho ==0);
}

bool pesquisar(Lista *list, Objeto x){
    if(list->tamanho == 0){
        return false;
    }
    PtrNoLista aux;
    aux = list->primeiro;
    while(aux != NULL && x.chave > aux->elemento.chave){
        aux = aux->proximo;
        if(aux == NULL || aux->elemento.chave > x.chave){
            return false;
        }
        return true;
    }
    
}

int tamanhoLista(Lista *list){
    return(list->tamanho);
}

void removeElemento(Lista *list, int chave, Objeto *item){
    if(list->tamanho == 0 && item->chave < list->primeiro->elemento.chave){
        printf("Lista vazia!!!\n");
    } //casos 1 e 2
    PtrNoLista aux;
    aux = list->primeiro;
    while(aux != NULL && item->chave > aux->elemento.chave){
        aux = aux->proximo;
       
    } //casos 4 e 5
    if(aux == NULL || aux->elemento.chave > item->chave){
            item->chave = aux->elemento.chave;
            list->tamanho--;
        } else{
            printf("O valor solicitado não existe!!!\n");
        }
}

void removePrimeiro(Lista *list, Objeto *item){
    Objeto x;
    if(item->chave == list->primeiro->elemento.chave){
        item->chave = list->primeiro->elemento.chave;
        list->tamanho--;
    } //caso 3
}

void removeUltimo(Lista *list, Objeto *item){
    PtrNoLista aux;
    aux = list->primeiro;
    while(aux != NULL){
        aux = aux->proximo;
    }
    item->chave = aux->elemento.chave;
    list->tamanho--;
    free(aux);
}

Objeto primeiro(Lista *list){
    return(list->primeiro->elemento);
}

Objeto ultimo(Lista *list){
    Objeto x;
    if(list->primeiro->proximo->elemento.chave < x.chave && list->primeiro->proximo == NULL){
        return x;
    }
}



#ifdef __cplusplus
}
#endif

#endif /* LISTAORDENADA_H */
