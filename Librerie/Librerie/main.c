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

int main(int argc, const char * argv[]) {
    TYPE arr1[SIZE], arr2[SIZE];
    int dim1, dim2;

    printf("Array 1: ");
    dim1 = scanArrayTerminatedByZero(arr1, SIZE);
    
    //printf("Array 2: ");
    //dim2 = scanArrayTerminatedByZero(arr2, SIZE);
    
    dim2 = dim1;
    copySorted(arr1, dim1, arr2);
    
    
    printArray(arr1, dim1, " ");
    printf("\n");
    printArray(arr2, dim2, " ");

}
