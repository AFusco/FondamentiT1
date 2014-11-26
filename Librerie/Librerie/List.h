//
//  List.h
//  Librerie
//
//  Created by Alessandro Fusco on 13/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef __Librerie__List__
#define __Librerie__List__

#include "common.h"
#include "DataTypes.h"

#ifndef TYPE_L_printFormat
#define TYPE_L_printFormat TYPE_printFormat
#endif

typedef struct Node
{
    TYPE_L value;
    struct Node *next;
} node;

typedef node* list;


/* Creazione e distruzione lista */
list emptyList();
list createNode(TYPE_L val);
void freeList(list l);



/* Predicati */
BOOL isEmptyList(list l);

/* Inserimento elementi */
list addNodeHead(TYPE_L newVal, list l);
list addNodeTail(TYPE_L newVal, list l);
list insertOrdered(TYPE_L newVal, list l);



/* Selettori */
TYPE_L head(list l);
list tail(list l);
list lastNode(list l);

/* Output */
void printList(list l);


/* Ordinamento */
void sortList(list* l);
list mergeLists(list a, list b);
void splitList(list l, list* prima, list* seconda);


#endif /* defined(__Librerie__List__) */
