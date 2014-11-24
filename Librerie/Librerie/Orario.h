//
//
//  Orario.h
//  Librerie
//
//  Created by Alessandro Fusco on 14/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#ifndef __Librerie__Orario__
#define __Librerie__Orario__

#include "common.h"

// Questa libreria è implementata in modo da tenere anche conto dei secondi.
// Per allargarne il riutilizzo, è possibile disabilitare i secondi impostando
// la costante USA_SECONDI a 0

#define USA_SECONDI 1

#define SECONDI 1
#define MINUTI 60
#define ORE 3600

typedef struct orario {
    int h;
    int m;
    
// Direttiva al preprocessore per l'implementazione dei secondi: vedi commento a riga 15
#if USA_SECONDI == 1
    int s;
#endif
    
} Time;

int timeDifferenceInSeconds(Time a, Time b);
void printTime (Time a);
Time getTranslatedTime(Time a, int interval, int intervalUnit);
int timeToSeconds(Time a);
Time secondsToTime(int sec);

#endif /* defined(__Librerie__Orario__) */
