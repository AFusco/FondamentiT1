//
//  tartaglia.h
//  tartaglia
//
//  Created by Alessandro Fusco on 30/10/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef tartaglia_tartaglia_h
#define tartaglia_tartaglia_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** mallocTriangolo(int righe);
void freeTriangolo(int** triangolo, int righe);
int binom(int **triangolo, int riga, int colonna);
void scriviTriangolo(int **triangolo, int righe);
void stampaTriangolo(int **triangolo, int righe);
int numCifre(int x);
int maxNumCifre(int **triangolo, int righe);
void printNum(int x, int lunghezza);
void printSpazio(int lunghezza);

#endif
