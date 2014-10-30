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
    int mil, sec, min;
    
    mil = millisec % 1000;
    
    if (millisec != 0)
    {
        sec = millisec/1000;
        if (sec != 0)
        {
            min = sec/60;
        }
        sec %= 60;
    }
    
    printf("%d:%02d.%03d", min, sec, mil);
}

