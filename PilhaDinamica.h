/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilhaDinamica.h
 * Author: root
 *
 * Created on 3 de setembro de 2019, 14:19
 */

#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int chave;
} objetoDin;

typedef struct NoPilha *ponteiroNoPilha;

typedef struct NoPilha {
    objetoDin obj;
    ponteiroNoPilha proximo;
} NoPilha;

typedef struct {
    ponteiroNoPilha topo;
    int tamanho;
} pilhadim;

void iniciaPilhaDin(pilhadim *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

void tamanhoDin(pilhadim *pilha) {
    printf("Tamanho: %i\n", pilha->tamanho); 
}

bool estaVaziaDin(pilhadim *pilha) {

    if(pilha->tamanho == 0)
        return true;
    
    return false;
    

}

void pushDin(objetoDin obj, pilhadim *pilha) {
    ponteiroNoPilha aux;
    aux = (ponteiroNoPilha) malloc(sizeof (NoPilha));
    aux->obj = obj;
    aux->proximo = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho = pilha->tamanho + 1;
    
}

void popDin(pilhadim *pilha, objetoDin *item) {

    if (!estaVaziaDin(pilha)) {
        *item = pilha->topo->obj;
        ponteiroNoPilha aux;
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux);
        pilha->tamanho = pilha->tamanho - 1;
    }
}

void topoDin(pilhadim *pilha, objetoDin obj) {
    
    printf("Topo da pilha: %i\n", obj.chave);

}

void printDin(pilhadim *pilha) {
    printf("{");
    ponteiroNoPilha p;
    for (p = pilha->topo; p != NULL; p = p->proximo) {
        printf("%i ", p->obj.chave);
    }
    printf("}\n");
}


#ifdef __cplusplus
}
#endif

#endif /* PILHADINAMICA_H */

