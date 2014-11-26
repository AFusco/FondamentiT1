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


#define INVALID_INPUT -2  //Input invalido
#define MALLOC_ERR  -3 //Errore nell'allocazione di memoria
#define ENDOFFILE_REACHED  -4 //Raggiunto EOF
#define CANNOT_OPEN_FILE -5


int errorHandler(int e);
void exitWithError(int e);
void printError(int code, char* err);


#endif /* defined(__Librerie__Errors__) */
