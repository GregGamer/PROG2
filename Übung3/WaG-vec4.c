//Gregor Wagner
//WaG-vec3.c

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Makros und globale Constanten

//Prototypen
void WaG_einlesen(int n, int *numbers);
float WaG_mittelwert_ermitteln(int n, int *numbers);
void WaG_sortieren(int n, int *numbers);
void WaG_benachbarte_mit_minimalen_abstand_ermitteln(int n, int *numbers);
void WaG_alles_ausgeben(int n, int *numbers);

int main (void) {
    //variablen
    int n;
    int *numbers;

    //input
    printf("Anzahl der Zahlen: ");
    scanf("%d",&n);

    numbers = malloc(n * sizeof(*numbers)); 

    WaG_einlesen(n,numbers);
    WaG_alles_ausgeben(n,numbers);
    return 0;
}

void WaG_einlesen(int n, int *numbers){
    for (int i = 0; i<n; ++i){
        printf("Zahl %d: ",i);
        scanf("%d", &numbers[i]);
    }
}

float WaG_mittelwert_ermitteln(int n, int *numbers){
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += numbers[i];
    return sum/n;
}

void WaG_sortieren(int n, int *numbers){
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < n-i-1; ++j)
            if(numbers[j]>numbers[j+1])
                numbers[j+1] = numbers[j];
}

void WaG_benachbarte_mit_minimalen_abstand_ermitteln(int n, int *numbers){
    int min = numbers[0];
    WaG_sortieren(n, numbers);
    for (int i = 0; i < n-1; ++i)
        min = (numbers[i+1]-numbers[i]<min)*(numbers[i+1]-numbers[i])+(numbers[i+1]-numbers[i]>=min)*min;

}

void WaG_alles_ausgeben(int n, int *numbers){
    printf("Anzahl der Zahlen: %d\n",n);
    printf("Die Zahlen: ");
/*    int *help = numbers;*/
    for(int i = 0; i<n;++i){
        printf(" %d",numbers[i]);
    }
    printf("\n");
}

