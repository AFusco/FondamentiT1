//
//  DataTypes.h
//  Librerie
//
//  Created by Alessandro Fusco on 12/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef __Librerie__DataTypes__
#define __Librerie__DataTypes__

#include <stdio.h>

typedef enum {false, true} BOOL;
typedef TYPE TYPE_A; //PER LA LIBRERIA ARRAY
typedef TYPE TYPE_L; //PER LA LIBRERIA LIST

//INPUT
TYPE_A scanType();


void printType(TYPE_A a);
BOOL equals(TYPE_A a, TYPE_A b);
BOOL isGreaterThan(TYPE_A a, TYPE_A b);


BOOL isLessThan(TYPE_A a, TYPE_A b);
BOOL isGreaterOrEqualThan(TYPE_A a, TYPE_A b);
BOOL isLessOrEqualThan(TYPE_A a, TYPE_A b);
int compare(TYPE_A a, TYPE_A b);
void copy(TYPE_A *b, TYPE_A a);
void copySorted(TYPE_A arr1[], int dim1, TYPE_A result[]);


#endif /* defined(__Librerie__DataTypes__) */
