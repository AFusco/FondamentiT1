//
//  main.c
//  EserciziFile
//
//  Created by Alessandro Fusco on 24/11/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define DIM 100

typedef struct
{
    int matricola;
    int cdl;
} dati;

typedef struct
{
    int matricola;
    char nome[21];
    char cognome[31];
    char via[31];
    char citta[31];
    int cap;
} indirizzo;

typedef struct
{
    int matricola;
    char nome[21];
    char cognome[31];
    char via[31];
    char citta[31];
    int cap;
    int cdl;
} studente;

void printStudente(studente a)
{
    printf("%d %s %s %s %s %d %d\n", a.matricola, a.nome, a.cognome, a.via, a.citta, a.cap, a.cdl);
}

int main() {
    studente stud[DIM];
    
    FILE *f1;
    FILE *f2;
    
    dati temp1;
    
    int trovato = 0;
    
    int i = 0, j;
    
    f1 = fopen("dati.txt", "r");
    if (f1 == NULL)
    {
        printf("Errore lettura dati.txt");
        exit(-1);
    }
    
    f2 = fopen("indirizzi.txt", "r");
    if (f2 == NULL)
    {
        printf("Errore lettura indirizzi.txt");
        exit(-1);
    }
    
    while (i < DIM && fscanf(f1, "%d %d", &temp1.matricola, &temp1.cdl ) == 2 )
    {
        trovato = 0;
        while( !trovato && fscanf(f2, "%d %s %s %s %s %d", &stud[i].matricola, stud[i].nome, stud[i].cognome, stud[i].via, stud[i].citta, &stud[i].cap )  == 6)
        {
            if (temp1.matricola == stud[i].matricola)
            {
                stud[i].cdl = temp1.cdl;
                trovato = 1;
            }
            
        }
        i++;
        rewind(f2);
    }
    
    for (j = 0; j <= i; j++)
    {
        printStudente(stud[j]);
    }
    
    fclose(f1);
    fclose(f2);
    
    
    
    system("pause");
}
