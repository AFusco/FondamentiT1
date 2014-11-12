//
//  main.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

//#include <stdio.h>
#include "Arrays.h"
#include "List.h"

//#include "DataTypes.h"

//Commento aggiunto da Nicola

int main(int argc, const char * argv[]) {
    
    TYPE_L zero, orari[10];
    
    zero.h = 0; zero.m = 0; zero.s = 0;
    scanArrayTerminatedBy(orari, 10, zero);
    
    printArray(orari, 10, " ");
/*
    sortArray(orari, 10);
    
    printArray(orari, 10, " ");n */
    return 0;
}
