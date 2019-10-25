/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: root
 *
 * Created on 22 de outubro de 2019, 14:31
 */

#ifndef AVL_H
#define AVL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

    typedef struct {
        int key;
    } objeto;

    typedef struct NoAVL *PtrNoAVL;

    typedef struct NoAVL {
        objeto elemento;
        PtrNoAVL left;
        PtrNoAVL right;
        int fator_balanceamento;
        int altura;
    } NoAVL;

    void iniciaAVL(PtrNoAVL *avl) {
        (*avl) = NULL;
    }

    bool estaVaziaAVL(PtrNoAVL *avl) {
        return (*avl = NULL);
    }

    void preOrdem(PtrNoAVL *avl) {

        if ((*avl) != NULL) {

            printf("%i\n", (*avl)->elemento.key);
            preOrdem(&(*avl)->left);
            preOrdem(&(*avl)->right);
        }
    }

    void posOrdem(PtrNoAVL *avl) {

        if ((*avl) != NULL) {

            posOrdem(&(*avl)->left);
            posOrdem(&(*avl)->right);
            printf("%i\n", (*avl)->elemento.key);
        }
    }

    void emOrdem(PtrNoAVL *avl) {

        if ((*avl) != NULL) {

            emOrdem(&(*avl)->left);
            printf("%i\n", (*avl)->elemento.key);
            emOrdem(&(*avl)->right);
        }
    }

    int alturaAVL(PtrNoAVL *avl) {
        int h1 = 0, h2 = 0;
        if (*avl == NULL) {
            return 0;
        }
        if ((*avl)->right != NULL) {
            h1++;
            h1 += alturaAVL(&(*avl)->right);
            
        }
        if ((*avl)->left != NULL) {
            h2++;
            h2 += alturaAVL(&(*avl)->left);
    
        }
        if (h1 > h2) {
            
            return h1;
        } else {
            
            return h2;
        }
    }

    
    bool procurarAVL(PtrNoAVL *avl, int chave, objeto *ret) {
        //nao achou elemento
        if (*avl == NULL) {

            return (false);
        }
        //achou elemento
        if ((*avl)->elemento.key == chave) {

            return (true);
        }
        if (chave < (*avl)->elemento.key) {
            //procurar na subárvore esquerda
            return (procurarAVL(&(*avl)->left, chave, ret));
        } else { //chave > (*arvore)->elemento.key
            //procurar na subárvore direita
            return (procurarAVL(&(*avl)->right, chave, ret));
        }
    }

    void liberaNo(PtrNoAVL *avl) {
        if ((*avl) != NULL) {
            liberaNo(&(*avl)->left);
            liberaNo(&(*avl)->right);
            free((*avl));
            (*avl) = NULL;
        }
    }

    void liberaAVL(PtrNoAVL *avl) {
        if ((*avl) != NULL) {
            liberaNo(&(*avl));
            free(*avl);
        }
    }

    void rotacaoSimplesEsquerda(PtrNoAVL *avl) {
        PtrNoAVL u;
        u = (*avl)->right;
        (*avl)->right = u->left;
        u->left = (*avl);
        (*avl)->fator_balanceamento = 0;
        (*avl) = u;
    }

    void rotacaoSimplesDireita(PtrNoAVL *avl) {
        PtrNoAVL u;
        u = (*avl)->left;
        (*avl)->left = u->right;
        u->right = (*avl);
        (*avl)->fator_balanceamento = 0;
        (*avl) = u;
    }

    void rotacaoDuplaEsquerda(PtrNoAVL *avl) {
        PtrNoAVL u, v;
        u = (*avl)->right;
        v = u->left;
        (*avl)->right = v->left;
        u->left = v->right;
        v->right = u;
        v->left = (*avl);
        (*avl) = v;
        //recalcular o fator
    }

    void rotacaoDuplaDireita(PtrNoAVL *avl) {
        PtrNoAVL u, v;
        u = (*avl)->left;
        v = u->right;
        (*avl)->left = v->right;
        u->right = v->left;
        v->right = (*avl);
        v->left = u;
        (*avl) = v;
        //recalcular o fator
    }

    void aplicarRotacoes(PtrNoAVL *avl) {
        if (alturaAVL(&(*avl)->left) > alturaAVL(&(*avl)->right)) {
            PtrNoAVL x = (*avl)->left;
            if (alturaAVL(&(x->left)) >= alturaAVL(&(x->right))) {
                printf("Rotação Simples para a Direita\n");
                rotacaoSimplesDireita(&(*avl));
            } else {
                printf("Rotação Dupla para Direita\n");
                rotacaoDuplaDireita(&(*avl));
            }
        } else {
            PtrNoAVL y = (*avl)->right;
            if (alturaAVL(&(y->right)) > alturaAVL(&(y->left))) {
                printf("Rotação Simples para Esquerda\n");
                rotacaoSimplesEsquerda(&(*avl));
            } else {
                printf("Rotação Dupla para Esquerda\n");
                rotacaoDuplaEsquerda(&(*avl));

            }
        }

    }

    bool inserirAVL(PtrNoAVL *avl, objeto obj) {
        if (*avl == NULL) {
            (*avl) = malloc(sizeof (NoAVL));
            (*avl)->right = (*avl)->left = NULL;
            (*avl)->elemento = obj;
            return (true);
        }
        if ((*avl)->elemento.key == obj.key) {
            return (false);
        }
        bool x;
        if ((*avl)->elemento.key > obj.key) {
            x = (inserirAVL(&(*avl)->left, obj));
            return true;
        } else {
            x = (inserirAVL(&(*avl)->right, obj));
            return true;
        }
        if (x == false) {
            return false;
        }
        int ae, ad;
        ae = alturaAVL(&(*avl)->left);
        ad = alturaAVL(&(*avl)->right);
        if ((ad - ae == -2) || (ad - ae == 2)) {
            printf("A árvore está desbalanceada!\n");
            aplicarRotacoes(&(*avl));
        }
        (*avl)->altura = alturaAVL(&(*avl));
    }

#ifdef __cplusplus
}
#endif

#endif /* AVL_H */

