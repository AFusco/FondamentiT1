//
//  List.c
//  Librerie
//
//  Created by Alessandro Fusco on 13/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "List.h"

//DA MODIFICARE SE TYPE_L e TYPE NON COINCIDONO
int compareTypeL(TYPE_L a, TYPE_L b)
{
    //Riutilizza la funzione del tipo TYPE
    return compare(a, b);
}

/* list emptyList()
 * ----------------
 * Restituisce una lista vuota (un puntatore a NULL)
 *
 */

list emptyList()
{
    return NULL;
}

/* list createNode(TYPE_L val)
 * ---------------------------
 * Alloca la memoria e restituisce l'indirizzo di un  nodo che punta a NULL, di valore @val
 * Se l'allocazione non va a buon fine, esce dal programma con l'errore MALLOC_ERR
 *
 */
list createNode(TYPE_L val)
{
    list newNode = (list)malloc(sizeof(list));
    
    if (newNode == NULL)
        exitWithError(MALLOC_ERR);
    
    newNode->next = NULL;
    newNode->value = val;
    
    return newNode;
}

/* void freeList(list l)
 * ---------------------
 * Fa il free della memoria di tutti gli elementi di una lista,
 * utilizzando la ricorsione
 *
 */

void freeList(list l)
{
    if(!isEmptyList(tail(l)))
        freeList(tail(l));
    free(l);
}


/* BOOL isEmptyList(list l)
 * ------------------------
 * Predicato che restituisce true se la lista @l è vuota, altrimenti false
 *
 */

BOOL isEmptyList(list l){
    if (l == NULL)
        return true;
    else
        return false;
}



/* list addNodeHead(TYPE_L newVal, list l)
 * ---------------------------------------
 * Crea una lista che ha come primo elemento un nuovo nodo di valore @newVal,
 * seguito dalla lista @l. Restituisce la lista creata.
 *
 */

list addNodeHead(TYPE_L newVal, list l)
{
    list newNode = createNode(newVal);
    newNode->next = l;
    l = newNode;
    return l;
}

/* list addNodeTail(TYPE_L newVal, list l)
 * ---------------------------------------
 * Crea un nodo di valore @newVal, che verrà aggiunto alla fine della lista @l.
 * Restituisce la lista @l, anche se l'indirizzo rimane invariato, in quanto viene
 * modificato solo l'ultimo elemento.
 *
 */

list addNodeTail(TYPE_L newVal, list l)
{
    list newNode = createNode(newVal);
    lastNode(l)->next = newNode;
    
    return l;
}







list insertOrdered(TYPE_L newVal, list l){
    //TODO
    return NULL;
}


/* TYPE_L head(list l)
 * -------------------
 * Restituisce il valore del primo elemento della lista @l
 *
 */

TYPE_L head(list l)
{
    return l->value;
}

/* list tail(list l)
 * -----------------
 * Restituisce la coda della lista @l, ovvero la lista che si 
 * ottiene escludendo il primo elemento di @l.
 * Se @l è vuoto, restituisce NULL
 *
 */

list tail(list l){
    if (!isEmptyList(l))
        return l->next;
    else
        return NULL;
}

/* list lastNode(list l)
 * ---------------------
 * Itera per tutta la lista @l e restituisce l'ultimo nodo della lista.
 *
 */
list lastNode(list l)
{
    list iterator = l;
    BOOL ultimo = false;
    
    while (!isEmptyList(iterator) && !ultimo)
    {
        if (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        else
        {
            ultimo = true;
        }
    }
    return iterator;
}






/* void printList(list l)
 * ----------------------
 * Stampa su una riga tutti gli elementi di una lista, usando la ricorsione.
 * Usa come formato TYPE_L_printFormat, che se non è definito è uguale a TYPE_printFormat definito in DataTypes.h
 *
 *
 */

void printList(list l)
{
    if (!isEmptyList(l))
    {
        printf(TYPE_L_printFormat , l->value);
        printf(" ");
        printList(tail(l));
    }
    else
    {
        printf("\n");
    }
}




/* void sortList(list* l)
 * -----------------------
 * Implementazione di mergeSort per le linked lists.
 * Non crea una copia della lista ma la ordina e basta
 *
 */

void sortList(list* l)
{
    list a, b, head = *l;
    
    //Caso base: la lista è vuota o ha un elemento solo, quindi è già ordinata :)
    if (isEmptyList(*l) || (*l)->next == NULL)
    {
        return;
    }
    else
    {
        
        //dividi
        splitList(head, &a, &b);
        //et impera
        sortList(&a);
        sortList(&b);
        
        //Merge delle liste ordinate nella lista originale
        *l = mergeLists(a, b);
        
    }
    
    
    
}

list mergeLists(list a, list b)
{
  
    list merged = NULL;
    
    /* Caso base: se una delle due liste è vuota, l'unione è l'altra */
    
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    
    /* PER ORDINARE  */
    if ( compareTypeL(a->value, b->value) <= 0 )
    {
        merged = a;
        merged->next = mergeLists(a->next, b);
    }
    else
    {
        merged = b;
        merged->next = mergeLists(a, b->next);
    }
    
    
    return merged;
    
    
}



/* void splitList(list l, list* prima, list* seconda)
 * --------------------------------------------------
 * Prende come argomenti la lista originale @l, e due liste (@prima e @seconda) per riferimento.
 * La funzione divide la lista originale in due metà separate, che verranno inserite in @prima e @seconda.
 */


void splitList(list l, list* prima, list* seconda)
{
    
    //Usa il metodo veloce lento per trovare l'elemento centrale

    list veloce;
    list lento;
    if (l==NULL || l->next==NULL)
    {
        *prima = l;
        *seconda = NULL;
    }
    else
    {
        lento = l;
        veloce = l->next;
        
        /* 'veloce' avanza di 2 nodi, 'lento' avanza di 1 nodo.
         Così quando 'veloce' sarà giunto alla fine, 'lento' sarà a metà.*/
        
        while (veloce != NULL)
        {
            veloce = veloce->next;
            if (veloce != NULL)
            {
                lento = lento->next;
                veloce = veloce->next;
            }
        }
        
    //la prima metà inizia dall'inizio (l)
    //la seconda metà inizia dopo il puntatore lento.
    
    *prima = l;
    *seconda = lento->next;
    
    //Le due metà vengono divise eliminando il collegamento tra di esse
    lento->next = NULL;
    }
}