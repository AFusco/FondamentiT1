//
//  Errors.h
//  Librerie
//
//  Created by Alessandro Fusco on 13/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef __Librerie__Errors__
#define __Librerie__Errors__

#include "common.h"
#include "DataTypes.h"

typedef struct{
    int code;
    char* err;
} Error;

const extern Error INVALID_INPUT;
const extern Error MALLOC_ERR;
const extern Error ENDOFFILE_REACHED;


int errorHandler(Error e);
Error throwException(Error e);
Error newError(int code, char* err);
void exitWithError(Error e);

#endif /* defined(__Librerie__Errors__) */
