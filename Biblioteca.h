/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: root
 *
 * Created on 15 de outubro de 2019, 16:35
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

    typedef struct {
        int chave;
    } ObjetoLista;

    typedef struct NoLista *PtrNoLista;

    typedef struct NoLista {
        ObjetoLista elemento;
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

    void inserirL(Lista *list, ObjetoLista x) {

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

    void destruir(Lista *list) {
        PtrNoLista aux;
        while (aux != NULL) {
            aux = list->primeiro;
            list->primeiro = list->primeiro->proximo;
            free(aux);
        }
    }

    bool estaVaziaL(Lista *list) {
        return (list->tamanho == 0);
    }

    bool pesquisar(Lista *list, ObjetoLista x) {
        if (estaVaziaL(list)) {
            return false;
        }
        PtrNoLista aux = list->primeiro;
        while (aux != NULL && x.chave > aux->elemento.chave) {
            aux = aux->proximo;
        }
        if (aux == NULL || aux->elemento.chave > x.chave) {
            return false;
        } else {
            return true;
        }
    }

    int tamanhoLista(Lista *list) {
        return (list->tamanho);
    }

    void removePrimeiro(Lista *list, ObjetoLista *item) {

        PtrNoLista aux;
        if (!estaVaziaL(list)) {
            aux = list->primeiro;
            item->chave = aux->elemento.chave;
            list->primeiro = list->primeiro->proximo;
            free(aux);
            list->tamanho--;
            
        } //caso 3
    }

    void removeElemento(Lista *list, int chave, ObjetoLista *item) {
        //casos 1 e 2
        if (estaVaziaL(list) || chave < list->primeiro->elemento.chave) {
            printf("Lista vazia ou não existe o elemento na lista\n");
            return;
        } else{
            //se for o primeiro elemento
            if(chave == list->primeiro->elemento.chave){
                printf("Removendo o primeiro elemento!\n");
                removePrimeiro(list, item);
            } else{
                PtrNoLista aux = list->primeiro;
                while((aux->proximo != NULL) && (chave > aux->proximo->elemento.chave)){
                    aux = aux->proximo;
                }
                if((aux->proximo == NULL) || (chave < aux->proximo->elemento.chave)){
                    printf("O elemento não existe na lista!\n");
                } else{
                    PtrNoLista remove = aux->proximo;
                    aux->proximo = aux->proximo->proximo;
                    list->tamanho--;
                    free(remove);
                }
            }
        }
    }

    ObjetoLista primeiroL(Lista *list) {
        return (list->primeiro->elemento);
    }

    ObjetoLista ultimoL(Lista *list) {
        ObjetoLista x;
        PtrNoLista aux = list->primeiro;
        while (aux != NULL && x.chave > aux->elemento.chave) {
            aux = aux->proximo;
            if (list->primeiro->proximo->elemento.chave < x.chave && list->primeiro->proximo == NULL) {
                return x;
            }
        }
    }

    
    typedef struct {
        char word[30];
    } objetoFila;

    typedef struct NoFila *ptrNoFila;

    typedef struct NoFila {
        objetoFila obj;
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
        printf("Tamanho da fila: %i", fila->contador);
    }

    bool estaVaziaF(filaDin *fila) {
        if (fila->contador == 0) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(filaDin *fila, objetoFila obj) {
        ptrNoFila aux;
        aux = (ptrNoFila) malloc(sizeof (NoFila));

        if (fila->contador == 0) {
            fila->inicio = aux;
            fila->fim = aux;
            aux->proximo = NULL;
            fila->contador += fila->contador;
        } else {
            aux->proximo = NULL;
            fila->fim->proximo = aux;
            fila->fim = fila->fim->proximo;
        }
    }

    objetoFila dequeue(filaDin *fila, objetoFila obj) {
        ptrNoFila aux;
        if (!estaVaziaF(fila)) {
            aux = fila->inicio;
            obj = aux->obj;
            fila->inicio = fila->inicio->proximo;
            free(aux);
            fila->contador -= fila->contador;
            return obj;
        }
    }

    objetoFila primeiroF(filaDin *fila) {
        return fila->inicio->obj;
    }

    objetoFila ultimoF(filaDin *fila) {
        return fila->fim->obj;
    }

    void print(filaDin *fila) {
        ptrNoFila aux;
        printf("[");
        for (aux = fila->inicio; aux != NULL; aux = aux->proximo) {
            printf(" %s\n ", aux->obj.word);
        }
        printf("]");
    }

    /*void destruir(filaDin *fila) {
        ptrNoFila aux;
        for (aux = fila->inicio; aux != NULL; aux = aux->proximo) {
            free(aux);
        }
    }*/

    typedef struct {
        char palavra [30];
        Lista lista;
    } objeto;

    typedef struct NoTree *PtrNoTree;

    typedef struct NoTree {
        objeto elemento;
        PtrNoTree left;
        PtrNoTree right;
    } NoArvore;

    void iniciaArvore(PtrNoTree *arvore) {
        *arvore = NULL;
    }

    bool estaVaziaA(PtrNoTree *arvore) {
        return (*arvore == NULL);
    }

    bool inserirA(PtrNoTree *arvore, objeto x) {
        if (*arvore == NULL) {
            (*arvore) = malloc(sizeof (NoArvore));
            (*arvore)->right = (*arvore)->left = NULL;
            (*arvore)->elemento = x;
            return (true);
        }
        if (strcmp((*arvore)->elemento.palavra, x.palavra) == 0) {
            return (false);
        }
        int a = 0;
        for(a; (*arvore)->elemento.palavra[a] == x.palavra[a]; a++);
        if ((*arvore)->elemento.palavra[a] > x.palavra[a]) {
            return (inserirA(&(*arvore)->left, x));
        } else {
            return (inserirA(&(*arvore)->right, x));
        }

    }

    bool procurar(PtrNoTree *arvore, char *chave , objeto *ret) {
        //nao achou elemento
        if (*arvore == NULL) {

            return (false);
        }
        //achou elemento
        if (strcmp((*arvore)->elemento.palavra, chave) == 0) {

            return (true);
        }
        if (chave[0] < (*arvore)->elemento.palavra[0]) {
            //procurar na subárvore esquerda
            return (procurar(&(*arvore)->left, chave, ret));
        } else { //chave > (*arvore)->elemento.key
            //procurar na subárvore direita
            return (procurar(&(*arvore)->right, chave, ret));
        }
    }

    void preOrdem(PtrNoTree *arvore) {

        if ((*arvore) != NULL) {

            printf("%s\n", (*arvore)->elemento.palavra);
            imprimirLista(&(*arvore)->elemento.lista);
            preOrdem(&(*arvore)->left);
            preOrdem(&(*arvore)->right);
            
        }
    }

    void posOrdem(PtrNoTree *arvore) {

        if ((*arvore) != NULL) {

            posOrdem(&(*arvore)->left);
            posOrdem(&(*arvore)->right);
            printf("%s\n", (*arvore)->elemento.palavra);
            imprimirLista(&(*arvore)->elemento.lista);
        }
    }

    void emOrdem(PtrNoTree *arvore) {

        if ((*arvore) != NULL) {

            emOrdem(&(*arvore)->left);
            printf("%s\n", (*arvore)->elemento.palavra);
            imprimirLista(&(*arvore)->elemento.lista);
            emOrdem(&(*arvore)->right);
        }
    }

    PtrNoTree getMaxAux(PtrNoTree *arvore) {
        PtrNoTree ret;
        if ((*arvore)->right == NULL) {
            ret = (*arvore);
            (*arvore) = (*arvore)->left;
            return (ret);
        }
        return (getMaxAux(&(*arvore)->right));
    }

   
    /*bool remover(PtrNoTree *arvore, char chave, objeto *x) {
        if (*arvore == NULL) { //não existe elemento a ser removido
            return false;
        }
        if ((*arvore)->elemento.palavra == chave) {
            PtrNoTree aux = (*arvore);
            *x = aux->elemento;

            if (aux->left == NULL && aux->right == NULL) {
                *arvore = NULL;
            } else if (aux->right == NULL && aux->left != NULL) {
                *arvore = (*arvore)->left;
            } else if (aux->left == NULL && aux->right != NULL) {
                *arvore = (*arvore)->right;
            } else {
                aux = getMaxAux(&((*arvore)->right));
                (*arvore)->elemento = aux->elemento;
            }
            free(aux);
            return true;
        }else if (chave < (*arvore)->elemento.palavra) {
            return (remover(&(*arvore)->left, chave, x));
        } else { 
            return (remover(&(*arvore)->right, chave, x));
        }
        
        
    }*/
    

#ifdef __cplusplus
}
#endif

#endif /* BIBLIOTECA_H */
