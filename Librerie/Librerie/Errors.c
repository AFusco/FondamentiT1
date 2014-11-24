//
//  Errors.c
//  Librerie
//
//  Created by Alessandro Fusco on 13/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "Errors.h"



const Error INVALID_INPUT = {2, "Input non valido"};
const Error MALLOC_ERR = {3, "Errore nell'allocazione di memoria"};
const Error ENDOFFILE_REACHED = {4, "Raggiunta la fine del file prima che terminasse la scansione"};






int errorHandler(Error e)
{
    fprintf(stderr, "Errore %d: %s\n", e.code, e.err);
    return e.code;
}

Error newError(int code, char* err)
{
    Error ret;
    ret.code = code;
    ret.err = err;
    return ret;
}

void exitWithError(Error e)
{
    exit(errorHandler(e));
}