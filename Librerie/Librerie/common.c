// Matricola: 0000718566
// alessandro.fusco3@studio.unibo.it
//
//  common.c
//  Librerie
//
//  Creato da Alessandro Fusco il 26/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include "common.h"
#include <limits.h>


string getString(FILE* stream)
{
    return getStringTerminatedByChar(stream, '\n');
}

string getStringTerminatedByChar(FILE* stream, char term)
{
    // Creo un buffer vuoto
    string buffer = NULL;
    
    // La capacità del buffer
    unsigned int capacity = 0;
    
    // number of chars actually in buffer
    unsigned int n = 0;
    
    // Carattere letto (o EOF)
    int c;
    
    string temp, minimal;
    
    // Ottiene carattere per carattere
    while ((c = fgetc(stdin)) != term && c != EOF)
    {
        // Se necessario, aumento la capacità del buffer
        if (n + 1 > capacity)
        {
            
            if (capacity == 0)
                capacity = DEFAULT_BUFFER_CAPACITY;
            else if (capacity <= (UINT_MAX / 2))
                capacity *= 2;
            else
            {
                free(buffer);
                return NULL;
            }
            
            // extend buffer's capacity
            temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
        
        // append current character to buffer
        buffer[n] = c;
        n++;
    }
    
    // return NULL if user provided no input
    if (n == 0 && c == EOF)
        return NULL;
    
    // Minimizza buffer
    minimal = malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);
    
    // terminate string
    minimal[n] = '\0';
    
    // return string
    return minimal;
}


