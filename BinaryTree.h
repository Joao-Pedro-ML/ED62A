
#ifndef BINARYTREE_H
#define BINARYTREE_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    typedef struct {
        int key;
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

    bool estaVazia(PtrNoTree *arvore) {
        return (*arvore == NULL);
    }

    bool inserir(PtrNoTree *arvore, objeto x) {
        if (*arvore == NULL) {
            (*arvore) = malloc(sizeof (NoArvore));
            (*arvore)->right = (*arvore)->left = NULL;
            (*arvore)->elemento = x;
            return (true);
        }
        if ((*arvore)->elemento.key == x.key) {
            return (false);
        }
        if ((*arvore)->elemento.key > x.key) {
            return (inserir(&(*arvore)->left, x));
        } else {
            return (inserir(&(*arvore)->right, x));
        }

    }

    bool procurar(PtrNoTree *arvore, int chave, objeto *ret) {
        //nao achou elemento
        if (*arvore == NULL) {
            printf("0\n");
            return (false);
        }
        //achou elemento
        if ((*arvore)->elemento.key == chave) {
            printf("1\n");
            return (true);
        }
        if (chave < (*arvore)->elemento.key) {
            //procurar na subárvore esquerda
            return (procurar(&(*arvore)->left, chave, ret));
        } else { //chave > (*arvore)->elemento.key
            //procurar na subárvore direita
            return (procurar(&(*arvore)->right, chave, ret));
        }
    }

    void preOrdem(PtrNoTree *arvore) {
        
        if ((*arvore) != NULL) {
            
            printf("%i\n", (*arvore)->elemento.key);
            preOrdem(&(*arvore)->left);
            preOrdem(&(*arvore)->right);
        }
    }

    void posOrdem(PtrNoTree *arvore) {
        
        if ((*arvore) != NULL) {
            
            posOrdem(&(*arvore)->left);
            posOrdem(&(*arvore)->right);
            printf("%i\n", (*arvore)->elemento.key);
        }
    }

    void emOrdem(PtrNoTree *arvore) {
        
        if ((*arvore) != NULL) {
            
            emOrdem(&(*arvore)->left);
            printf("%i\n", (*arvore)->elemento.key);
            emOrdem(&(*arvore)->right);
        }
    }

    int maximo(PtrNoTree *arvore){
        if((*arvore)->right == NULL){
            
            return (*arvore)->elemento.key;
        }
       maximo(&(*arvore)->right);
    }
    
    int minimo(PtrNoTree *arvore){
        if((*arvore)->left == NULL){
            
            return (*arvore)->elemento.key;
        }
        minimo(&(*arvore)->left);
    }
    
    int maximoIterativo(PtrNoTree *arvore){
        
    }
    
#ifdef __cplusplus
}
#endif

#endif /* BINARYTREE_H */

