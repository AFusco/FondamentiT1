//
//  DataTypes.h
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef Librerie_DataTypes_h
#define Librerie_DataTypes_h

#define TYPE int

typedef enum { false, true } BOOL;

BOOL equals(TYPE a, TYPE b)
{
    return a == b;
}

#endif
