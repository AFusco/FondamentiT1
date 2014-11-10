//
//  DataTypes.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "ArrayDataTypes.h"


TYPE scanType()
{
    TYPE temp;
    scanf("%d", &temp );
    return temp;
}

BOOL equals(TYPE a, TYPE b)
{
    return a == b;
}