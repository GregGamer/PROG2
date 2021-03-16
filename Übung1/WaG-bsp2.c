//Marie Strohm, Gregor Wagner, Jonas Kronberger, Arved Didio
//WaG-bsp2.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
    // Variables
    int x1,y1;
    int x2,y2;

    //get the input
    printf("Input x1: ");
    scanf("%d",&x1);
    printf("Input y1: ");
    scanf("%d",&y1);
    printf("Input x2: ");
    scanf("%d",&x2);
    printf("Input y2: ");
    scanf("%d",&y2);

    //Berechnung
    int x,y;
    x = x2-x1;
    y = y2-y1;
    double erg = sqrt(x*x+y*y);

    //Output
    printf("Distance between the said points: %f\n",erg);

    return 0;
}
