//
//  main.c
//  AreaPerimetroTriangolo
//
//  Created by Alessandro Fusco on 31/10/14.
//  Copyright (c) 2014 Alessandro Fusco. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define TRIANGOLO_NON_VALIDO -1
#define TRIANGOLO_DEGENERE -2



/********
 *
 *
 *
 *
 ********/
int area_perimetro(float l1, float l2, float l3, float* perimetro, float* area)
{
    float s;
    
    if (l1==0|| l2==0 || l3==0|| l3==l1+l2 || l2==l1+l3 || l1==l2+l3)
    {
        return TRIANGOLO_DEGENERE;
    }
    else if (l3>l1+l2 || l2>l1+l3 || l1>l2+l3)
    {
        return TRIANGOLO_NON_VALIDO;
    }
    else
    {
        *perimetro = l1+l2+l3;
        s = *perimetro/2;
        *area = sqrt(s*(s-l1)*(s-l2)*(s-l3));
        return 0;
    }
    
}




int main(int argc, const char * argv[]) {
    float l1, l2, l3, perimetro, area;
    area = perimetro = 0;
    
    printf("Inserisci i 3 lati: ");
    scanf("%f %f %f", &l1, &l2, &l3);
    switch (area_perimetro(l1, l2, l3, &perimetro, &area)){

        case TRIANGOLO_NON_VALIDO:
            printf("Triangolo non valido\n");
            break;
        case TRIANGOLO_DEGENERE:
            printf("Triangolo degenere\n");
            break;
        default:
            printf("Area: %f, Perimetro: %f \n", area, perimetro);
            break;
    
    }
        return 0;
}
