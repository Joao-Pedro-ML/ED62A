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

    typedef struct {
        int key;
    } objeto;

    typedef struct NoAVL *PtrNoAVL;

    typedef struct NoAVL {
        objeto elemento;
        PtrNoAVL left;
        PtrNoAVL right;
        int fator_balanceamento;
    } NoAVL;


#ifdef __cplusplus
}
#endif

#endif /* AVL_H */

