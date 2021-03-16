//Gregor Wagner, Marie Strohm, Jonas Kronberger, Didio Arved
//WaG-bsp9.c

//include
#include <stdio.h>

//protypen

//main
int main (void){
    //variablen
    int start[2],end[2];

    //input
    printf("Punkt Fx: ");
    scanf("%d",&start[0]);
    printf("Punkt Fy: ");
    scanf("%d",&start[1]);
    printf("Punkt Zx: ");
    scanf("%d",&end[0]);
    printf("Punkt Zx: ");
    scanf("%d",&end[1]);

    for(;start[0]!=end[0] && start[1]!=end[1];){
        
        printf("Fx: %d von %d\n",start[0],end[0]);
        printf("Fy: %d von %d\n",start[1],end[1]);       

        start[0] = start[0] + (start[0]<end[0]) * 1 + (start[0]>end[0]) * -1;
        start[1] = start[1] + (start[1]<end[1]) * 1 + (start[1]>end[1]) * -1;
    }


    printf("Punkt erreicht");


    return 0;
}
