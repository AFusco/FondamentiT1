//
//  DataTypes.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "ArrayDataTypes.h"

/*
 *
 *  DA IMPLEMENTARE
 *
 *
 */


TYPE scanType()
{
    TYPE temp;
    scanf("%d", &temp );
    return temp;
}

void printType(TYPE a)
{
    printf("%d", a);
}

BOOL equals(TYPE a, TYPE b)
{
    return a == b;
}

BOOL isGreaterThan(TYPE a, TYPE b)
{
    return a > b;
}

BOOL isLessThan(TYPE a, TYPE b)
{
    return a < b;
}

/*
 *
 *  GIA FATTE
 *
 *
 */


BOOL isGreaterOrEqualThan(TYPE a, TYPE b)
{
    return (isGreaterThan(a, b) || equals(a, b));
}

BOOL isLessOrEqualThan(TYPE a, TYPE b)
{
    return (isLessThan(a, b) || equals(a, b));

}