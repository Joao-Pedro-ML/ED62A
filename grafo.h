//
// Created by root on 06/12/2019.
//

#ifndef ATIVIDADE5_GRAF_H
#define ATIVIDADE5_GRAF_H

#ifndef GRAPH_H
#define GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int key;
} obj;

typedef struct NoFila *ptrNoFila;

typedef struct NoFila {
    obj obj;
    ptrNoFila proximo;
} NoFila;

typedef struct {
    ptrNoFila inicio;
    ptrNoFila fim;
    int contador;
} filaDin;

void iniciaFilaDin(filaDin *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->contador = 0;
}

void tamanho(filaDin *fila) {
    printf("Tamanho da fila: %i\n", fila->contador);
}

bool estaVazia(filaDin *fila) {
    if (fila->contador == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueue(filaDin *fila, obj obj) {
    ptrNoFila aux;
    aux = (ptrNoFila) malloc(sizeof (NoFila));
    aux->obj = obj;
    if (estaVazia(fila)) {
        fila->inicio = aux;
        fila->fim = aux;
        aux->proximo = NULL;
        fila->contador++;
    } else {
        aux->proximo = NULL;
        fila->fim->proximo = aux;
        fila->fim = fila->fim->proximo;
        fila->contador++;
    }
}

obj dequeue(filaDin *fila, obj obj) {
    ptrNoFila aux;
    if (!estaVazia(fila)) {
        aux = fila->inicio;
        obj = aux->obj;
        fila->inicio = fila->inicio->proximo;
        free(aux);
        fila->contador--;
        return obj;
    }
}

obj primeiro(filaDin *fila) {
    return fila->inicio->obj;
}

obj ultimo(filaDin *fila) {
    return fila->fim->obj;
}

void print(filaDin *fila) {
    ptrNoFila aux;
    printf("\n[");
    for (aux = fila->inicio; aux != NULL; aux = aux->proximo) {
        printf(" %i ", aux->obj.key);
    }
    printf("]\n");
}

void destruir(filaDin *fila) {
    ptrNoFila aux;
    while(aux!=NULL){
        aux = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(aux);
    }

}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct {
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

void iniciaLista(Lista *list) {
    list->primeiro = NULL;
    list->tamanho = 0;
}

void inserir(Lista *list, Objeto x) {

    PtrNoLista novo;
    novo = (PtrNoLista) malloc(sizeof (NoLista));
    novo->elemento.chave = x.chave;
    if (list->tamanho == 0 || x.chave < list->primeiro->elemento.chave) {
        novo->proximo = list->primeiro;
        list->primeiro = novo;
        list->tamanho++;
    } else {
        PtrNoLista aux;
        aux = list->primeiro;
        while (aux->proximo != NULL && x.chave > aux->proximo->elemento.chave) {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        list->tamanho++;
    }
}

void imprimirLista(Lista *list) {
    PtrNoLista aux;
    printf("\n[");
    for (aux = list->primeiro; aux != NULL; aux = aux->proximo) {
        printf(" %i ", aux->elemento.chave);
    }
    printf("]\n");
}

void destruirLista(Lista *list) {
    PtrNoLista aux;
    while (aux != NULL) {
        aux = list->primeiro;
        list->primeiro = list->primeiro->proximo;
        free(aux);
    }
}

bool estaVaziaLista(Lista *list) {
    return (list->tamanho == 0);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*/
typedef struct {
    char cor;
    int pai;
    int d;
    int valor;
    int f;
} vertice;

void iniciaVertice(vertice *V, int tamanho){
    for(int i = 0; i<tamanho; i++){

        V[i].cor = 'b';
        V[i].d = 999;
        V[i].pai = 0;
        V[i].f = 0;

    }
}

/*void bfsM(vertice *V, int inicial) {
  filaDin f;
  obj obj;
  V = (vertice *)malloc(tamanho * sizeof(vertice));
  int **auxiliar;
  auxiliar = (int **)malloc(tamanho * sizeof(int *))
  for(int i=0;i<tamanho,i++){
    auxiliar[i] = (int*)malloc(tamanho * sizeof(int));
  }
  obj i;
  obj i;
  iniciaVertice(&V, tamanho);
  while(!estavazia(&f)){
    i = dequeue(&f, obj);
    j = dequeue(&f, obj);
    auxiliar[i.key - 1][j.key - 1] = 1;
  }
  V[inicial-1] = s;
  s.cor = 'c';
  s.d = 0;
  s.pai = -1;
  iniciaFilaDin(&f);
  obj.key = inicial;
  enqueue(&f, obj);
  while(!estaVazia(&f)){
    obj.key = dequeue(&f, obj);
    for(obj ver.key = 0; ver.key < tamanho ;ver.key++){
      if(auxiliar[obj.key][vert.key] == 1){
        if(V[ver.key].cor == 'b'){
          V[ver.key].cor = 'c';
          V[ver.key].d = V[obj.key].d + 1;
          V[vert.key].pai = obj.key;
          enqueue(&f, ver);
        }
      }
    }
    V[obj.key].cor = 'p';
  }
}*/


void dfsM(vertice V, FILE *arq) {

}

void bfsL(vertice V, FILE *arq) {

}

void dfsL(vertice V, FILE *arq) {

}



#ifdef __cplusplus
}
#endif

#endif /* GRAPH_H */


#endif //ATIVIDADE5_GRAF_H
