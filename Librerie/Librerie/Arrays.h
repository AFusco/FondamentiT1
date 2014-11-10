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

int scanArrayTerminatedBy(TYPE arr[], int dim, TYPE terminator);
int scanArrayTerminatedByZero(TYPE arr[], int dim );
int searchFirst(TYPE arr[], int dim, TYPE element);
int searchLast(TYPE arr[], int dim, TYPE element);
BOOL inArray( TYPE arr[], int dim, TYPE element );
void printArray( TYPE arr[], int dim, char* format);
BOOL compareEquals(TYPE arr1[], int dim1, TYPE arr2[], int dim2);



#endif /* defined(__Librerie__Arrays__) */
