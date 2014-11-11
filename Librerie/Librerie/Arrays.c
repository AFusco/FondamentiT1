//  Matricola: 0000718566
//
//  Arrays.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "Arrays.h"


// FUNZIONI DI INPUT E OUTPUT



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

//
// COPIA DI UN ARRAY
//


/* void copyArray
 * ---------------------
 *
 *  Copia ogni elemento di @original[] in copy.
 *  Si assume che la dimensione di copy sia uguale o maggiore di quella di original
 *
 */

void copyArray(TYPE original[], int dim, TYPE copy[])
{
    int i;
    
    for (i = 0; i < dim; i++)
    {
        copy[i] = original[i];
    }
}



//
// FUNZIONI DI RICERCA
//


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



//
// FUNZIONI DI CONFRONTO
//




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

/* BOOL compareUnordered
 * ---------------------
 * Controlla se due array contengono gli stessi elementi
 *
 * Args:
 * @TYPE arr1[]: l'array da stampare a schermo
 * @int dim1: la dimensione logica dell'array @arr[]
 * @TYPE arr1[]: l'array da stampare a schermo
 * @int dim1: la dimensione logica dell'array @arr[]
 *
 * RETURN: true se ogni valore di arr1 è presente in arr2, altrimenti false
 */

BOOL compareUnordered(TYPE arr1[], int dim1, TYPE arr2[], int dim2)
{
    BOOL alreadyChecked[SIZE];
    BOOL result = true;
    
    int tempPos, tempOffset;
    BOOL found = false;
    
    int i;
    
    if (dim1 != dim2)
    {
        return false;
    }
    
    for ( i = 0; i < SIZE; i++ ) //inizializza tutti gli elementi di alreadyChecked a false
    {
        alreadyChecked[i] = false;
    }
    
    for (i = 0; i < dim1 && result == true; i++)
    {
        tempOffset = 0;
        found = false;
        do
        {
            //Trova la posizione dell'elemento arr1[i] in arr2
            tempPos = searchFirst(&arr2[tempOffset], dim2-tempOffset, arr1[i]) + tempOffset;
            
            if ( tempPos >= 0 && alreadyChecked[tempPos] == true )   //Se si trova ed è già stato "preso"
            {
                tempOffset = tempPos + 1; //Cambia l'offset per ripetere la ricerca
            }
            else if ( tempPos >= 0 && !alreadyChecked[tempPos]) //Altrimenti se è stato trovato ed non è ancora stato preso
            {
                found = true; //Flag per uscire dal ciclo while
                alreadyChecked[tempPos] = true; //Imposto la posizione come già controllata in alreadyChecked
            }
            else //Altrimenti, se l'elemento nell'offset non è stato trovato,
            {
                result = false; //Gli array sono diversi
            }
            
        }
        while (tempOffset <= dim1 && found == false && result == true);
        
    }
    
    return result;
}



//
// FUNZIONI DI ORDINAMENTO
//


/*
 *  Implementazione dell'algoritmo mergeSort ricorsivo
 */

void mergeSort(TYPE arr[], int first, int last) {
    
    int center;
    
    if ( first < last) {
        center = ( first + last )/2;
        mergeSort(arr, first, center);
        mergeSort(arr, center+1, last);
        merge(arr, first, center, last);
    }
    return;
}

/*
 *  Funzione di merging di supporto a mergeSort
 */

void merge(TYPE a[], int start, int center, int end) {
    
    int i, j, k;
    int tempArr[SIZE];
    
    i = start;
    j = center+1;
    k = 0;
    
    //Fai il merge dei due sottoarray ordinati
    
    while ( (i<=center) && (j<=end) ) {
        if ( isLessOrEqualThan(a[i], a[j]) ) {
            tempArr[k] = a[i];
            i++;
            k++;
        } else {
            tempArr[k] = a[j];
            k++;
            j++;
        }
    }
    
    //Aggiungi quelli del primo o del secondo se ne avanzano
    
    while (i<=center)
    {
        tempArr[k] = a[i];
        k++;
        i++;
    }
    
    while (j<=end)
    {
        tempArr[k] = a[j];
        k++;
        j++;
    }
    
    //Inserisci gli elementi ordinati al posto giusto nell'array originale
    for (k=start; k<=end; k++)
        a[k] = tempArr[k-start];
    
}

/* void sortArray
 * --------------
 * Ordina gli elementi dell'array arr[] tramite mergeSort O(nlogn)
 *
 */

void sortArray(TYPE arr[], int dim)
{
    mergeSort(arr, 0, dim-1);
}


/*
 * void copySortedArray
 * 
 * Copia l'array arr1[] in result[], che poi verrà ordinato tramite mergeSort
 *
 */

void copySortedArray(TYPE arr1[], int dim1, TYPE result[])
{
    copyArray(arr1, dim1, result);
    sortArray(result,  dim1);
}




