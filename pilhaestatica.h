/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilhaEstatica.h
 * Author: root
 *
 * Created on 3 de setembro de 2019, 14:09
 */

#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#ifdef __cplusplus
extern "C" {
#endif

#define N 50

typedef struct {
    int keyest;

} objetoEst;

typedef struct {
    objetoEst vetor[N];
    int topoEst;
} pilhaEst;

void iniciaPilhaEst(pilhaEst *pilha) {
    pilha->topoEst=  -1;

}

bool estaVaziaEst(pilhaEst *pilha) {
    if (pilha->topoEst == -1) {
        return true;
    } else {
        return false;
    }
}

bool estaCheiaEst(pilhaEst *pilha) {
    if (pilha->topoEst == N - 1) {
        return true;
    } else {
        return false;
    }
}

void pushEst(objetoEst obj, pilhaEst *pilha) {

    if (pilha->topoEst == N - 1) {
        printf("Pilha cheia!\n");
    } else {
        pilha->vetor[pilha->topoEst] = obj;
        pilha->topoEst++;
    }
}

void popEst(pilhaEst *pilha) {

    objetoEst x;
    if (pilha->topoEst == N - 1) {
        printf("A pilha esta vazia!\n");
    } else {
        x.keyest = pilha->vetor[pilha->topoEst].keyest;
        pilha->topoEst--;
    }

}

int sizeEst(pilhaEst *pilha) {

    int y = 0;
    printf("Tamanho da pilha: %i\n", y = pilha->topoEst);
    return (y);

}

objetoEst topEst(pilhaEst *pilha) {

    printf("Topo da pilha: %i", pilha->vetor[pilha->topoEst].keyest);

}

void printEst(pilhaEst *pilha) {

    printf("{");
    for (int i = 0; i < N; i++) {
        printf(" %i ", pilha->vetor[i].keyest);
    }
    printf("}\n");
}


#ifdef __cplusplus
}
#endif

#endif /* PILHAESTATICA_H 
