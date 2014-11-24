//
//  Orario.c
//  Librerie
//
//  Created by Alessandro Fusco on 14/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "Orario.h"

void printTime (Time a)
{
    printf("%d:%d", a.h, a.m);
    
// Non si può usare un semplice if perchè si verrebbe incontro a un errore di compilazione
#if USA_SECONDI == 1
    printf(":%d", a.s);
#endif

}

int timeToSeconds(Time a)
{
    int secondiA;
    secondiA = ORE*a.h + MINUTI*a.m;
#if USA_SECONDI == 1
    secondiA += a.s;
#endif
    return secondiA;
}

Time secondsToTime(int sec)
{
    Time result;
    
#if USA_SECONDI == 1
    result.s = sec % MINUTI;
#endif
    
    result.m = (sec/MINUTI) % MINUTI;
    result.h = (sec/ORE) % ORE;
    
    return result;
}

int timeDifferenceInSeconds(Time a, Time b)
{
    return timeToSeconds(a) - timeToSeconds(b);
}

Time getTranslatedTime(Time a, int interval, int intervalUnit)
{
    return secondsToTime(  timeToSeconds(a) + interval*intervalUnit  );
}

