//
//  List.c
//  Librerie
//
//  Created by Alessandro Fusco on 11/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "List.h"
#include "ArrayDataTypes.h"
#include "Errors.h"


/* 
 * list emptyList()
 * -----------------
 * Restituisce una lista vuota
 */

list emptyList()
{
    return NULL;
}

/* 
 * BOOL isEmptyList(list l)
 * -----------------------
 * Controlla se la lista è vuota
 */

BOOL isEmptyList(list l)
{
    return (l == NULL);
}

/*
 * list addNode(TYPE_L newVal, list l)
 * ------------------------
 * Aggiunge un nodo a capo della lista @l, imposta il valore @newVal come value del primo nodo
 *
 * RETURN: la lista che punta al nuovo primo elemento
 */



list addNodeHead(TYPE_L newVal, list l)
{
    list tmp;
    tmp = l;
    list newNode = (list)malloc(sizeof(node));
    
    //Se malloc fallisce ritorna NULL
    if (newNode == NULL)
    {
        exit(MEMORIA_NON_DISPONIBILE);
    }
    
    newNode->value = newVal;
    newNode->next = tmp;
    l = newNode;
    return l;
    
}

list addNodeTail(TYPE_L newVal, list l)
{
    list precedente = NULL,  attuale = l;
    
    if (isEmptyList(attuale))
    {
        return addNodeHead(newVal, l);
    }
    
    while ( !isEmptyList(attuale) )
    {
        precedente = attuale;
        attuale = attuale->next;
    }
    
    list newNode = (list)malloc(sizeof(node));
    if (newNode == NULL)
    {
        exit(MEMORIA_NON_DISPONIBILE);
    }
    
    
    newNode->value = newVal;
    newNode->next = NULL;
    
    precedente->next = newNode;
    return l;
}

void printList(list l)
{
    if (!isEmptyList(l))
    {
        printNode(l->value);
        printList(tailOfList(l));
    }
}

/*
 * TYPE_L headOfList(list l)
 * -----------------------
 * Restituisce il primo elemento della lista
 */

TYPE_L headOfList(list l)
{
    if (isEmptyList(l)) exit(LETTURA_DA_LISTA_VUOTA);
    return l->value;
}

/*
 * list tailOfList(list l)
 * -----------------------
 * Restituisce la coda della lista a partire dal secondo elemento
 */

list tailOfList(list l)
{
    if (isEmptyList(l)) exit(SELEZIONE_DA_LISTA_VUOTA);
    else return (l->next);
}

/*
 * void freeList(list l)
 * -----------------------
 * Libera la memoria della lista @l, allocata precedentemente nell'heap da @addNode(TYPE_L newVal, list l)
 * Utilizza la ricorsione
 */

void freeList(list l) {
    
    //C'è poco di liberabile nel non liberabile
    if (isEmptyList(l))
    {
        return;
    }
    else
    {
        //Prima libero la fine altrimenti si perde il riferimento
        freeList( tailOfList(l) );
        free(l);
    } 
    return; 
}

/*
 *
 *
 */



