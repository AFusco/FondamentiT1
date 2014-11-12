//
//  DataTypes.c
//  Librerie
//
//  Created by Alessandro Fusco on 10/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "ArrayDataTypes.h"

/*
 *
 *  DA IMPLEMENTARE
 *
 *
 */


 
 void printNode(TYPE_L a)
 {
 printf("%d:%d:%d ", a.h, a.m, a.s);
 }
 
 TYPE scanType()
 {
     TYPE temp;
     scanf("%d:%d:%d", &temp.h, &temp.m, &temp.s );
     return temp;
 }
 
 void printType(TYPE a)
 {
 printf("%d:%d:%d", a.h, a.m, a.s);
 }
 
 BOOL equals(TYPE a, TYPE b)
 {
 return ((a.h == b.h) && (a.m == b.m) && (a.s == b.s));
 }
 
 BOOL isGreaterThan(TYPE a, TYPE b)
 {
     if ( a.h < b.h ) return false;
     else if ( a.h > b.h ) return true;
     else
     {
         if ( a.m < b.m ) return false;
         else if ( a.m > b.m ) return true;
         else
         {
             if ( a.s <= b.s ) return false;
             else return true;
         }
     }
     
     
 }

void copy(TYPE *b, TYPE a)
{
    b->h = a.h;
    b->m = a.m;
    b->s = a.s;
}



/*
 
void printNode(TYPE_L a)
{
    printf("%d ", a);
}
 
TYPE scanType()
{
    TYPE temp;
    scanf("%d", &temp );
    return temp;
}

void printType(TYPE a)
{
    printf("%d", a);
}

BOOL equals(TYPE a, TYPE b)
{
    return a == b;
}

BOOL isGreaterThan(TYPE a, TYPE b)
{
    return a > b;
}

BOOL isLessThan(TYPE a, TYPE b)
{
    return a < b;
}
 
void copy(TYPE a, TYPE *b)
{
    *b = a;
}

*/

/*
 *
 *  GIA FATTE
 *
 *
 */

int compare(TYPE a, TYPE b)
{
    if ( equals(a, b)) return 0;
    else if ( isGreaterThan(a, b)) return 1;
    else return -1;
}

BOOL isLessThan(TYPE a, TYPE b)
{
    return !(isGreaterOrEqualThan(a, b));
}

BOOL isGreaterOrEqualThan(TYPE a, TYPE b)
{
    return (isGreaterThan(a, b) || equals(a, b));
}

BOOL isLessOrEqualThan(TYPE a, TYPE b)
{
    return !(isGreaterThan(a, b));

}