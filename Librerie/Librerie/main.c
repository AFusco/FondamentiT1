//
//  main.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

//#include <stdio.h>
#include "Arrays.h"
//#include "DataTypes.h"

//Commento aggiunto da Nicola

int main(int argc, const char * argv[]) {
    TYPE arr1[SIZE], arr2[SIZE];
    int dim1, dim2;
    BOOL uguali;
    printf("Array 1: ");
    dim1 = scanArrayTerminatedByZero(arr1, SIZE);
    
    printf("Array 2: ");
    dim2 = scanArrayTerminatedByZero(arr2, SIZE);
    
    uguali = compareUnordered(arr1, dim1, arr2, dim2);
    printf("%d", uguali);
    
}
