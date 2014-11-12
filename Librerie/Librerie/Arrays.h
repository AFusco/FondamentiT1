//
//  Arrays.h
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef __Librerie__Arrays__
#define __Librerie__Arrays__

#include <stdio.h>
#include "ArrayDataTypes.h"


//Input e Output
int scanArrayTerminatedBy(TYPE arr[], int dim, TYPE terminator);
int scanArrayTerminatedByZero(TYPE arr[], int dim );
void printArray( TYPE arr[], int dim, char* format);

//Copia
void copyArray(TYPE original[], int dim, TYPE copy[]);

//Ricerca
int searchFirst(TYPE arr[], int dim, TYPE element);
int searchLast(TYPE arr[], int dim, TYPE element);
BOOL inArray( TYPE arr[], int dim, TYPE element );

//Confronto
BOOL compareEquals(TYPE arr1[], int dim1, TYPE arr2[], int dim2);
BOOL compareUnordered(TYPE arr1[], int dim1, TYPE arr2[], int dim2);

//Ordinamento
void merge(TYPE arr[], int start, int center, int end);
void mergeSort(TYPE arr[], int first, int last);
void sortArray(TYPE arr[], int dim);


#endif /* defined(__Librerie__Arrays__) */
