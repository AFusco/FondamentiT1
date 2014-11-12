//
//  DataTypes.h
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef Librerie_DataTypes_h
#define Librerie_DataTypes_h

#define SIZE 10

#include <stdio.h>

typedef enum { false, true } BOOL;

typedef struct time{ int h; int m; int s; } TYPE_L;
typedef TYPE_L TYPE;


TYPE scanType();
void printType(TYPE a);
BOOL equals(TYPE a, TYPE b);
BOOL isGreaterThan(TYPE a, TYPE b);
BOOL isLessThan(TYPE a, TYPE b);
BOOL isGreaterOrEqualThan(TYPE a, TYPE b);
BOOL isLessOrEqualThan(TYPE a, TYPE b);
int compare(TYPE a, TYPE b);
void copy(TYPE *b, TYPE a);


void copySorted(TYPE arr1[], int dim1, TYPE result[]);


void printNode(TYPE_L a);




#endif
