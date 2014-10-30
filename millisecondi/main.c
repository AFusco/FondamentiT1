//
//  main.c
//  millisecondi
//
//  Created by Alessandro Fusco on 30/10/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include <stdio.h>
#include "procedure.h"

int main(int argc, const char * argv[]) {
    long int millisec;

    do {
        printf("Inserisci i millisecondi: ");
        scanf("%ld", &millisec);
    } while (millisec < 0);
    
    millisec2Tempo(millisec);
    getchar();
    getchar();
    return 0;
}
