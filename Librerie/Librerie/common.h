//
//  common.h
//  Librerie
//
//  Created by Alessandro Fusco on 14/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef Librerie_common_h
#define Librerie_common_h


//La dimensione di default del buffer stdin
#define DEFAULT_BUFFER_CAPACITY 128

typedef enum {false, true} BOOL;
typedef char* string;

#include <stdlib.h>
#include <stdio.h>
#include "Errors.h"
#include <string.h>

string getString(FILE* stream);
string getStringTerminatedByChar(FILE* stream, char term);

#endif
