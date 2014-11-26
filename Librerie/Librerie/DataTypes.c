//
//  DataTypes.c
//  Librerie
//
//  Created by Alessandro Fusco on 12/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "DataTypes.h"

#define TYPE_scanFormat "%d" //Formato utilizzato per la scanf
#define TYPE_printFormat "%d" //Formato utilizzato per la printf
#define TYPE_args 1 //Numero di flags nella stringa di formato, usato per controllare gli errori



//INPUT
int fscanType(FILE* stream, TYPE* scanned)
{
    
    //CAMBIARE QUESTA RIGA
    int res = fscanf(stream, TYPE_scanFormat, scanned);
    
    //NON CAMBIARE
    if (res == EOF) {
        return ENDOFFILE_REACHED;
    }
    else if ( res != TYPE_args )
    {
        return INVALID_INPUT;
    }
    else
    {
        return 0;
    }
    
}

//OUTPUT
void printType(TYPE a)
{
    printf(TYPE_printFormat, a);
}

//CONFRONTO
int compare(TYPE a, TYPE b)
{
    
//per i numeri
    if (a > b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
 
/*  
 //per le stringhe
 return strcmp(a, b);
*/
    
    
/* 
 // per gli orari
 
 int sec;
 sec = timeDifferenceInSeconds(a, b);
 if (sec > 0)
 return 1;
 else if (sec == 0)
 return 0;
 else
 return -1;
 
 
 
 */
    
}

//COPIA
void copy(TYPE *b, TYPE a)
{
    *b = a;
}



/* Funzioni già implementate */

//INPUT
void scanType(TYPE* scanned)
{
    int a;
    do
    {
        a = fscanType(stdin, scanned);
        if (a != 0)
        {
            fpurge(stdin);
            printf("Input non valido, riprova: ");
        }
    } while (a != 0);
    
}

//CONFRONTO
BOOL isLessThan(TYPE a, TYPE b)
{
    return compare(a, b) < 0;
}
BOOL isGreaterOrEqualThan(TYPE a, TYPE b)
{
    return compare(a, b) >= 0;
}
BOOL isLessOrEqualThan(TYPE a, TYPE b)
{
    return compare(a, b) <= 0;
}
BOOL isGreaterThan(TYPE a, TYPE b)
{
    return compare(a, b) > 0;
}
BOOL equals(TYPE a, TYPE b)
{
    return compare(a, b) == 0;
}

TYPE maxType(TYPE a, TYPE b)
{
    return isGreaterOrEqualThan(a, b) ? a : b;
}
TYPE minType(TYPE a, TYPE b)
{
    return isGreaterOrEqualThan(a, b) ? b : a;
}
