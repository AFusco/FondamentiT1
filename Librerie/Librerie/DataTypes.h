//
//  DataTypes.h
//  Librerie
//
//  Created by Alessandro Fusco on 12/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef __Librerie__DataTypes__
#define __Librerie__DataTypes__

#include "Errors.h"
#include "common.h"
#include "Orario.h"

typedef int TYPE;


typedef TYPE TYPE_A; //PER LA LIBRERIA ARRAY
typedef TYPE TYPE_L; //PER LA LIBRERIA LIST

#define TYPE_scanFormat "%d" //Formato utilizzato per la scanf
#define TYPE_printFormat "%d" //Formato utilizzato per la printf
#define TYPE_args 1 //Numero di flags nella stringa di formato, usato per controllare gli errori


#define TYPE_L_printFormat TYPE_printFormat



/* Funzioni da modificare ad hoc */

//INPUT
int fscanType(FILE* stream, TYPE* scanned);

//OUTPUT
void printType(TYPE a);

//CONFRONTO
int compare(TYPE a, TYPE b);



/* Funzioni già implementate */

//INPUT
void scanType(TYPE* scanned);

//CONFRONTO
BOOL isLessThan(TYPE a, TYPE b);
BOOL isGreaterOrEqualThan(TYPE a, TYPE b);
BOOL isLessOrEqualThan(TYPE a, TYPE b);
BOOL isGreaterThan(TYPE a, TYPE b);
BOOL equals(TYPE a, TYPE b);

TYPE maxType(TYPE a, TYPE b);
TYPE minType(TYPE a, TYPE b);

//COPIA
void copy(TYPE *b, TYPE a);


#endif /* defined(__Librerie__DataTypes__) */
