//Gregor Wagner
//WaG-bsp10.c

//Libraries
#include <stdio.h>

//Globale constanten
const int RIVER_LENGTH = 20;

//Prototypen
void digitalRiver(int n);
int quersumme(int n);

//Main
int main (void){
    //Variablen
    int riverBeginning;

    //Fetch the Input
    printf("Start of the Digital River: ");
    scanf("%d",&riverBeginning);

    //Output des digital Rivers
    digitalRiver(riverBeginning);

}

int quersumme(int n){
    int sum = 0;

    while ( n > 0){
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

void digitalRiver(int n){
    
    printf("%d,",n);

    for ( int i = 0; i < RIVER_LENGTH; ++i){
        n = n + quersumme(n);
        printf(" %d,",n);
    }
}
