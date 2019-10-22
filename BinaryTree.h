
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

            return (false);
        }
        //achou elemento
        if ((*arvore)->elemento.key == chave) {

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

    int maximo(PtrNoTree *arvore) {
        if ((*arvore)->right == NULL) {

            return (*arvore)->elemento.key;
        }
        maximo(&(*arvore)->right);
    }

    int minimo(PtrNoTree *arvore) {
        if ((*arvore)->left == NULL) {

            return (*arvore)->elemento.key;
        }
        minimo(&(*arvore)->left);
    }

    int maximoIterativo(PtrNoTree *arvore) {
        PtrNoTree aux;
        for (aux = (*arvore); aux->right != NULL; aux = aux->right) {

        }
        return aux->elemento.key;
    }

    int minimoIterativo(PtrNoTree *arvore) {
        PtrNoTree aux;
        for (aux = (*arvore); aux->left != NULL; aux = aux->left) {

        }
        return aux->elemento.key;
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

   
    bool remover(PtrNoTree *arvore, int chave, objeto *x) {
        if (*arvore == NULL) { //não existe elemento a ser removido
            return false;
        }
        if ((*arvore)->elemento.key == chave) {
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
        }else if (chave < (*arvore)->elemento.key) {
            return (remover(&(*arvore)->left, chave, x));
        } else { 
            return (remover(&(*arvore)->right, chave, x));
        }
        
        
    }

#ifdef __cplusplus
}
#endif

#endif /* BINARYTREE_H */

