//
//  main.c
//  millisecondi
//
//  Created by Alessandro Fusco on 30/10/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    
    scanf("%d%*c", &a);
    printf("Hai scritto %d. Premi invio per uscire... ", a);
    
    getchar();
    
    
    return 0;
}
