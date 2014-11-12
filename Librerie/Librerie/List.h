
//
//  List.h
//  Librerie
//
//  Created by Alessandro Fusco on 11/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef __Librerie__List__
#define __Librerie__List__

#include <stdio.h>
#include <stdlib.h>
#include "ArrayDataTypes.h"

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

/* Input */
void printList(list l);

TYPE_L headOfList(list l);
list tailOfList(list l);
//int member(element el, list l);

#endif /* defined(__Librerie__List__) */
