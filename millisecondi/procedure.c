//
//  procedure.c
//  millisecondi
//
//  Created by Alessandro Fusco on 30/10/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "procedure.h"

void millisec2Tempo(long int millisec)
{
    long int min;
    int sec, mil;
    
    mil = millisec % 1000;
    min = (millisec/1000)/60;
    sec = (millisec/1000)%60;
    
    printf("%ld:%02d.%03d", min, sec, mil);
}

