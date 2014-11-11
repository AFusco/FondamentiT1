//
//  DataTypes.h
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef Librerie_DataTypes_h
#define Librerie_DataTypes_h

#define TYPE int
#define SIZE 10

#include <stdio.h>

typedef enum { false, true } BOOL;

TYPE scanType();
void printType(TYPE a);
BOOL equals(TYPE a, TYPE b);
BOOL isGreaterThan(TYPE a, TYPE b);
BOOL isLessThan(TYPE a, TYPE b);
BOOL isGreaterOrEqualThan(TYPE a, TYPE b);
BOOL isLessOrEqualThan(TYPE a, TYPE b);

void copySorted(TYPE arr1[], int dim1, TYPE result[]);



#endif
