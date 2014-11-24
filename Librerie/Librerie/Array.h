//
//  Array.h
//  Librerie
//
//  Created by Alessandro Fusco on 13/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef __Librerie__Array__
#define __Librerie__Array__


#include "common.h"
#include "DataTypes.h"


//Input e Output
int scanArrayTerminatedBy(TYPE_A arr[], int dim, TYPE_A terminator);
int scanArrayTerminatedByZero(TYPE_A arr[], int dim );
void printArray( TYPE_A arr[], int dim, char* separatore);

//Copia
void copyArray(TYPE_A original[], int dim, TYPE_A copy[]);

//Ricerca
int searchFirst(TYPE_A arr[], int dim, TYPE_A element);
int searchLast(TYPE_A arr[], int dim, TYPE_A element);
BOOL inArray( TYPE_A arr[], int dim, TYPE_A element );

//Confronto
BOOL compareEquals(TYPE_A arr1[], int dim1, TYPE_A arr2[], int dim2);
BOOL compareUnordered(TYPE_A arr1[], int dim1, TYPE_A arr2[], int dim2);

//Ordinamento
void sortArray(TYPE_A arr[], int dim);
void merge(TYPE_A arr[], int start, int center, int end);
void mergeSort(TYPE_A arr[], int first, int last);

#endif /* defined(__Librerie__Array__) */
