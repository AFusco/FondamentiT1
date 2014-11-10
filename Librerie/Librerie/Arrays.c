//  Matricola: 0000718566
//
//  Arrays.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "Arrays.h"

/* int scanArrayTerminatedBy
 * ---------------------
 * Prende da stdinput al più @dim elementi, di formato @format, 
 * terminati dall'elemento @terminator, e li inserisce in @arr[]
 * 
 * Args:
 * @TYPE arr[]: puntatore all'array in cui verranno inseriti gli elementi
 * @int dim: la dimensione fisica dell'array @arr[]
 * @TYPE terminator: elemento che termina lo scan
 *
 * RETURN: la dimensione logica dell'array inserito
 *
 */


int scanArrayTerminatedBy(TYPE arr[], int dim, TYPE terminator)
{
    int i = 0;
    TYPE temp;
    do
    {
        temp = scanType();
        
        if (!equals(temp, terminator))
        {
            arr[i] = temp;
            i++;
        }
    }
    while (i < dim && !equals(temp, terminator));
    return i;
}

/*
 * Come scanArrayTerminatedBy ma con terminator = 0 di default
 */

int scanArrayTerminatedByZero(TYPE arr[], int dim)
{
    return scanArrayTerminatedBy(arr, dim, 0);
}

/* int searchFirst
 * ---------------------
 * Restituisce il primo indice trovato con la ricerca lineare di un elemento @element
 *
 * Args:
 * @TYPE arr[]: l'array in cui effettuare la ricerca
 * @int dim: la dimensione logica dell'array @arr[]
 * @TYPE element: l'elemento da cercare nell'array
 *
 * RETURN: -1 se l'elemento non è presente nell'array, oppure il primo indice dell'elemento
 *
 */

int searchFirst(TYPE arr[], int dim, TYPE element)
{
    int i, found = -1;

    for (i = 0; i < dim && found < 0; i++)
    {
        if ( equals(arr[i], element) )
        {
            found = i;
        }
    }
    return found;
}

/* int searchLast
 * ---------------------
 * Restituisce l'ultimo indice trovato con la ricerca lineare di un elemento @element
 *
 * Args:
 * @TYPE arr[]: l'array in cui effettuare la ricerca
 * @int dim: la dimensione logica dell'array @arr[]
 * @TYPE element: l'elemento da cercare nell'array
 *
 * RETURN: -1 se l'elemento non è presente nell'array, oppure l'ultimo indice dell'elemento
 */

int searchLast(TYPE arr[], int dim, TYPE element)
{
    int i, found = -1;
    
    for (i = dim -1; i > 0 && found < 0; i--)
    {
        if ( equals(arr[i], element) )
        {
            found = i;
        }
    }
    return found;
}


/* BOOL inArray
 * ---------------------
 * Restituisce true se l'elemento @element è presente nell'array
 * Restituisce false se l'elemento @element non è presente nell'array
 *
 * Args:
 * @TYPE arr[]: l'array in cui effettuare la ricerca
 * @int dim: la dimensione logica dell'array @arr[]
 * @TYPE element: l'elemento da cercare nell'array
 *
 */

BOOL inArray( TYPE arr[], int dim, TYPE element )
{
    int i, found = false;
    
    for (i = 0; i < dim && found < 0; i++)
    {
        if ( equals(arr[i], element) )
        {
            found = true;
        }
    }
    return found;
}

/* void printArray
 * ---------------------
 * Stampa a schermo un'array
 *
 * Args:
 * @TYPE arr[]: l'array da stampare a schermo
 * @int dim: la dimensione logica dell'array @arr[]
 * @char* separator: il separatore tra un elemento e l'altro
 *
 */

void printArray( TYPE arr[], int dim, char* separator)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printType(arr[i]);
        if (separator != NULL)
        {
            printf("%s", separator);
        }
    }
}

/* BOOL compareEquals
 * ---------------------
 * Controlla se due array sono identici
 *
 * Args:
 * @TYPE arr1[]: l'array da stampare a schermo
 * @int dim1: la dimensione logica dell'array @arr[]
 * @TYPE arr1[]: l'array da stampare a schermo
 * @int dim1: la dimensione logica dell'array @arr[]
 * 
 * RETURN: true se ogni valore di arr1 è uguale al valore nella posizione corrisponente in arr2, altrimenti false
 */


BOOL compareEquals(TYPE arr1[], int dim1, TYPE arr2[], int dim2)
{
    int i;
    BOOL result = true;
    
    if (dim1 != dim2) //Se le dimensioni degli array sono diverse, gli array non possono essere uguali
    {
        return false;
    }
    
    for ( i = 0; i < dim1 && result == true; i++ )
    {
        if (!equals(arr1[i], arr2[i]))
        {
            result = false;
        }
    }
    
    return result;
}





