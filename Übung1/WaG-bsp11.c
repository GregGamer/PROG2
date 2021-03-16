//Gregor Wagner
//WaG-bsp11.c

//Libraries
#include <stdio.h>

//Globale constanten
const int RIVER_LENGTH = 20;

//Prototypen
int digitalRiver(int start,int end);
int quersumme(int n);

int main (void){
    //Variablen
    int riverCrossPoint;

    //Fetch the Input
    printf("Start of the Digital River: ");
    scanf("%d",&riverCrossPoint);

    for(int i = 1; i < riverCrossPoint; ++i){
        digitalRiver(i,riverCrossPoint);
    }
    
    return 0;
}

int quersumme(int n){
    int sum = 0;

    while ( n > 0){
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int digitalRiver(int start, int end){
    
    int river = start;
    //printf("%d,",start);

    for (;start < end;){
        start = start + quersumme(start);
        //printf(" %d,",start);
        if(start == end){
            printf("Cross river with: %d\n",river);
            break;
        }
    }


    return start;
}
