#ifndef HASH_H
#define HASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
    
#define TAM 23
    
    typedef struct{
        char *info;
        int key;
    }objeto;

    typedef struct{
        objeto *array[TAM];
        int contador;
    }hash;
    
    int funcaoHash(int key);
    void iniciaHash(hash *tabela);
    void insereHash(hash *tabela, int chave, char *info);
    bool procuraHash(hash *tabela, int chave);
    objeto* removeHash(hash *tabela, int chave);
    void imprimeHash(hash *tabela);

    
#ifdef __cplusplus
}
#endif

#endif /* HASH_H */
