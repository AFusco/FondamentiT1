//
//  tartaglia.c
//  tartaglia
//
//  Created by Alessandro Fusco on 30/10/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "tartaglia.h"


int** mallocTriangolo(int righe)
{
    int **triangolo;
    int i;
    
    triangolo = malloc( righe * sizeof( int * ) );
    if (triangolo == NULL) { return NULL; }
    
    for (i = 0; i < righe; i++)
    {
        triangolo[i] = calloc( i+1, sizeof(int));
    }
    return triangolo;
}

void freeTriangolo(int** triangolo, int righe)
{
    int i;
    for (i = 0; i<righe; i++)
    {
        free(triangolo[i]);
    }
    free(triangolo);
}

int binom(int **triangolo, int riga, int colonna)
{
    if ( colonna == 0 || colonna == riga )
    {
        triangolo[riga][colonna] = 1;
        return 1;
    }
    else if ( triangolo[riga][colonna] != 0 )
    {
        return triangolo[riga][colonna];
    }
    else
    {
        return triangolo[riga][colonna] = binom(triangolo, riga-1 , colonna-1 ) + binom(triangolo, riga-1 , colonna );
    }
}

void scriviTriangolo(int **triangolo, int righe)
{
    int i;
    
    for (i = 0; i<righe; i++)
    {

        binom(triangolo, righe-1, i);
    
    }
    
}


void stampaTriangolo(int **triangolo, int righe)
{
    int i, j, lunghezza;
    
    scriviTriangolo(triangolo, righe);
    lunghezza = maxNumCifre(triangolo, righe);
    
    for (i = 0; i<righe; i++)
    {
        for (j = 1; j < righe-i; j++)
        {
            printSpazio(lunghezza);
            //printf("\t");
        }
        for (j = 0; j <= i; j++)
        {
            printNum(triangolo[i][j], lunghezza);
            printSpazio(lunghezza);
        }
        printf("\n");
    }
}

void printNum(int x, int lMax)
{
    int i;
    int spazi = lMax - numCifre(x);
    for (i = 0; i < spazi; i++)
    {
        printf(" ");
    }
    printf("%d",x);
}

void printSpazio(int lunghezza)
{
    int i;
    for (i = 0; i < lunghezza; i++)
    {
        printf(" ");
    }
}

int numCifre(int x)
{
    x = x > 0 ? x : -1*x;
    return x == 0 ? 1 :(int)log10(x)+1;
}

int maxNumCifre(int **triangolo, int righe)
{
    return numCifre(triangolo[righe-1][righe/2]);
}
