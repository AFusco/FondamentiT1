//
//  Errors.c
//  Librerie
//
//  Created by Alessandro Fusco on 13/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "Errors.h"

#define INVALID_INPUT -2  //Input invalido
#define MALLOC_ERR  -3 //Errore nell'allocazione di memoria
#define ENDOFFILE_REACHED  -4 //Raggiunto EOF


int errorHandler(int e)
{
    
    
    switch (e)
    {
        case INVALID_INPUT:
            printError(e, "Input non valido");
            break;
        case MALLOC_ERR:
            printError(e, "Errore nell'allocazione di memoria");
            break;
        case ENDOFFILE_REACHED:
            printError(e, "E' stata raggiunta la fine del file");
            break;
        case CANNOT_OPEN_FILE:
            printError(e, "Impossibile aprire il file");
            break;
        default:
            printError(e, "Si e' verificato un errore generico");
            break;
    }
    
    return e;
}



void exitWithError(int e)
{
    exit(errorHandler(e));
}


void printError(int code, char* err)
{
    fprintf(stderr, "Errore %d: %s\n", code, err);
}
