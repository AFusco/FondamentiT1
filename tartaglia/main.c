//
//  main.c
//  tartaglia
//Recovery Key: 576453-3E2iXanXXzJ8u9jgb4GxGd5zERDinTCPtv3SPBMI
//Generated: Wed, 29 Oct 2014, 17:53.45
//
//  Created by Alessandro Fusco on 29/10/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tartaglia.h"

int main() {
    int righe;
    do
    {
        printf("Inserisci il numero di righe: ");
        scanf("%d%*c", &righe);
    }
    while (righe <= 0);
  
    int** triangolo = mallocTriangolo(righe);
    if (triangolo == NULL) { printf("ERRORE"); }
    
    scriviTriangolo(triangolo, righe);
    
    stampaTriangolo(triangolo, righe);
    
    freeTriangolo(triangolo, righe);
   
  
    
    printf("\n\nPremi invio per uscire...");
    getchar();
    return 0;
}
