//
//  main.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//
#define N 3

//#include <stdio.h>
#include "Arrays.h"
//#include "DataTypes.h"

int main(int argc, const char * argv[]) {
    TYPE arr1[N], arr2[N];
    int dim1, dim2;
    BOOL uguali;
    
    dim1 = scanArrayTerminatedByZero(arr1, N, "%d");
    dim2 = scanArrayTerminatedByZero(arr2, N, "%d");
    
    uguali = compareEquals(arr1, dim1, arr2, dim2);
    printf("%d", uguali);
    
}
