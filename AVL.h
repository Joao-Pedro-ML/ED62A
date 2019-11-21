#ifndef AVL_H
#define AVL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
        int hdir = 0, hesq = 0;
        if (*avl == NULL) {
            return 0;
        } else {
            hdir = 1 + alturaAVL(&(*avl)->right);
            hesq = 1 + alturaAVL(&(*avl)->left);
            if (hdir > hesq) {
                return (hdir);
            } else {
                return (hesq);
            }
        }
    }

    int atualizaAltura(PtrNoAVL left, PtrNoAVL right) {
        int ae, ad;
        ae = alturaAVL(&left);
        ad = alturaAVL(&right);
        if (ae > ad) {
            return (ae + 1);
        } else {
            return (ad + 1);
        }
    }

    int fatorBalanceamento(PtrNoAVL *avl) {
        int dir, esq;
        if ((*avl)->right != NULL) {
            dir = 1 + alturaAVL(&(*avl)->right);
        }
        if ((*avl)->left != NULL) {
            esq = -1 - alturaAVL(&(*avl)->left);
        }
        return dir + esq;
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
            //return true;
        } else {
            x = (inserirAVL(&(*avl)->right, obj));
            //return true;
        }
        if (x == false) {
            //return false;
        }
        int hesq = alturaAVL(&(*avl)->left);
        int hdir = alturaAVL(&(*avl)->right);
        if (hesq - hdir == 2 || hesq - hdir == -2) {
            printf("A arvore esta desbalanceada!\n");
            aplicarRotacoes(&(*avl));
        }
        (*avl)->altura = atualizaAltura((*avl)->left, (*avl)->right);
    }

    PtrNoAVL getMaxAux(PtrNoAVL *avl) {
        PtrNoAVL aux;
        if ((*avl)->right == NULL) {
            aux = (*avl);
            (*avl) = (*avl)->left;
            return (aux);
        }
        return (getMaxAux(&(*avl)->right));
    }

    bool remover(PtrNoAVL *avl, int chave) {
        if (*avl == NULL) { //não existe elemento a ser removido
            return false;
        }
        if ((*avl)->elemento.key == chave) {
            PtrNoAVL aux = (*avl);


            if (aux->left == NULL && aux->right == NULL) {
                *avl = NULL;
            } else if (aux->right == NULL && aux->left != NULL) {
                *avl = (*avl)->left;
            } else if (aux->left == NULL && aux->right != NULL) {
                *avl = (*avl)->right;
            } else {
                aux = getMaxAux(&((*avl)->right));
                (*avl)->elemento = aux->elemento;
            }
            free(aux);
            return true;
        }
        bool teste;
        if (chave < (*avl)->elemento.key) {
            teste = remover(&(*avl)->left, chave);
        } else {
            teste = remover(&(*avl)->right, chave);
        }
        if (teste == false) {
            return false;
        }
        int hesq = alturaAVL(&(*avl)->left);
        int hdir = alturaAVL(&(*avl)->right);
        if (hesq - hdir == 2 || hesq - hdir == -2) {
            printf("A arvore esta desbalanceada!\n");
            aplicarRotacoes(&(*avl));
        }
        (*avl)->altura = atualizaAltura((*avl)->left, (*avl)->right);
    }

    void imprimeNo(PtrNoAVL *a, int b) {

        FILE *arq2;
        arq2 = fopen(argv[2], "a");
        if (arq2 == NULL) {
            printf("Erro ao abrir o arquivo de saida!!!\n");
        }
        int hesq = alturaAVL(&(*a)->left);
        int hdir = alturaAVL(&(*a)->right);
        int f = hdir - hesq;
        int i;
        for (i = 0; i < b; i++) {
            fprintf(arq2, "\t");
        }
        fprintf(arq2, "%i (%i),\n", (*a)->elemento.key, f);
        fclose(arq2);
    }

    void mostraArvore(PtrNoAVL *a, int b) {

        if ((*a)->right != NULL) {
            mostraArvore(&(*a)->right, b + 1);
        }
        if (a != NULL) {
            imprimeNo(&(*a), b);
        }

        if ((*a)->left != NULL) {
            mostraArvore(&(*a)->left, b + 1);
        }
    }

#ifdef __cplusplus
}
#endif

#endif /* AVL_H */
