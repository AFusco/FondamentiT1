//
//  Arrays.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "Arrays.h"

int scanArrayTerminatedBy(TYPE arr[], int dim, char* format, TYPE terminator)
{
    int i = 0;
    TYPE temp;
    do
    {
        arr[i] = scanf(format, &temp);
        i++;
    }
    while (i < dim && temp != terminator);
    return i;
}

int scanArrayTerminatedByZero(TYPE arr[], int dim, char* format)
{
    return scanArrayTerminatedBy(arr, dim, format, 0);
}

int searchFirst(TYPE arr[], int dim, TYPE element)
{
    int i, found = -1;

    for (i = 0; i < dim && found < 0; i++)
    {
        if ( equals(arr[i], element) )
        {
            found = i;
        }
    }
    return found;
}

int searchLast(TYPE arr[], int dim, TYPE element)
{
    int i, found = -1;
    
    for (i = dim -1; i > 0 && found < 0; i--)
    {
        if ( equals(arr[i], element) )
        {
            found = i;
        }
    }
    return found;
}



