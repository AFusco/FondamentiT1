//
//  tartaglia.c
//  tartaglia
//
//  Created by Alessandro Fusco on 30/10/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "tartaglia.h"


/********
 *
 *  Alloca la memoria per un triangolo di tartaglia
 *  Parametri: il numero di righe del triangolo
 *  Return: int** che punta alla matrice bidimensionale triangolare
 *
 *********/


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

/*******
 *
 *  Libera la memoria allocata alla matrice triangolare
 *  Parametri: int** che punta al triangolo | int che rappresenta il numero di righe del triangolo
 *
 *****/


void freeTriangolo(int** triangolo, int righe)
{
    int i;
    for (i = 0; i<righe; i++)
    {
        free(triangolo[i]);
    }
    free(triangolo);
}


/************
 *
 *  Calcola il coefficiente binomiale N su K e lo inserisce in triangolo[N][K], usando la ricorsione
 *  Parametri: int** che punta al triangolo | int N/riga | int K/colonna
 *  Return: int coefficiente binomiale di N su K
 *
 ************/

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


/***********
 *
 * Calcola i coefficienti biomiali dell'ultima riga del triangolo, generando quindi anche tutte le altre righe
 * Parametri: int** che punta al triangolo | int che indica il numero di righe
 *
 ***********/


void scriviTriangolo(int **triangolo, int righe)
{
    int i;
    
    triangolo[0][0] = 1;
    
    for (i = 0; i<righe; i++)
    {
        binom(triangolo, righe-1, i);
    }
    
}


/**********
 *
 * Stampa a schermo il triangolo 
 * Parametri: int** che punta al triangolo | int numero di righe
 *
 **********/


void stampaTriangolo(int **triangolo, int righe)
{
    int i, j, lunghezza;
    
    lunghezza = maxNumCifre(triangolo, righe);  //Definisce quella che sarà il numero di spazi tra un numero e l'altro
    
    for (i = 0; i<righe; i++)
    {
        for (j = 1; j < righe-i; j++)
        {
            printSpazio(lunghezza);  // Stampa gli spazi all'inizio della riga
        }
        for (j = 0; j <= i; j++)
        {
            // Alterna ogni numero a uno spazio di lunghezza definita
            printNum(triangolo[i][j], lunghezza);
            printSpazio(lunghezza);
        }
        printf("\n");
    }
}


/********
 *
 * Stampa a schermo lMax caratteri; i caratteri iniziali sono spazi, quelli finali sono le cifre del numero x
 * Parametri: int il numero da stampare | la lunghezza della stringa stampata
 *
 ********/

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

/**********
 *
 * Stampa a schermo un numero definito di spazi bianchi
 * Parametri: int numero di spazi da stampare
 *
 **********/

void printSpazio(int lunghezza)
{
    int i;
    for (i = 0; i < lunghezza; i++)
    {
        printf(" ");
    }
}

/*********
 *
 *  Calcola il numero di cifre di un numero intero
 *  Parametri: int di cui calcolare il numero di cifre
 *
 *********/

int numCifre(int x)
{
    x = x > 0 ? x : -1*x;
    return x == 0 ? 1 :(int)log10(x)+1;
}

/*********
 *
 * Calcola il numero di cifre del numero più elevato del triangolo
 *
 ********/

int maxNumCifre(int **triangolo, int righe)
{
    return numCifre(triangolo[righe-1][righe/2]);
}
