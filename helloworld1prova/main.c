//
//  main.c
//  helloworld1prova
//
//  Created by Alessandro Fusco on 01/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

int quadrato(int a)
{
    return a*a;
}

int allaquarta(int a)
{
    return quadrato(quadrato(a));
}
int cubo(int b)
{
    return b*quadrato(b);
}