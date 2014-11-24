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

typedef struct Node
{
    TYPE_L value;
    struct Node *next;
} node;

typedef node* list;

/* Creazione e distruzione lista */
list emptyList();
void freeList(list l);

/* Controlli sulle liste */
BOOL isEmptyList(list l);

/* Inserimento elementi */
list addNodeHead(TYPE_L newVal, list l);
list addNodeTail(TYPE_L newVal, list l);
list insertOrdered(TYPE_L newVal, list l);

/* Output */
void printList(list l);

TYPE_L head(list l);
list tail(list l);


#endif /* defined(__Librerie__List__) */
