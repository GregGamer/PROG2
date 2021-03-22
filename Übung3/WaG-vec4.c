//Gregor Wagner
//WaG-vec3.c

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Makros und globale Constanten

//Prototypen
void WaG_einlesen(const int n, int *numbers);
float WaG_mittelwert_ermitteln(const int n, int *numbers);
void WaG_sortieren(const int n, int *numbers);
int WaG_benachbarte_mit_minimalen_abstand_ermitteln(const int n, int *numbers);
void WaG_alles_ausgeben(const int n, int *numbers);

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

void WaG_einlesen(const int n, int *numbers){
    int *num = numbers;
    for (int i = 0; i<n;++i,++num){
        printf("Zahl %d: ",i+1);
        scanf("%d", num);
    }
}

float WaG_mittelwert_ermitteln(const int n, int *numbers){
    float sum = 0;
    int *num = numbers;
    for(int i = 0; i < n; ++i,++num)
        sum += *num;
    return sum/n;
}

void WaG_sortieren(const int n, int *numbers){
    int tmp;
    int *num = numbers;
    for (int i = 1; i < n; ++i){
        for (int j = 0; j < n-i; ++j,++num){
            if(numbers[j] > numbers[j+1]){
                tmp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = tmp;
            }
        }
    }
}

int WaG_benachbarte_mit_minimalen_abstand_ermitteln(const int n, int *numbers){
    int *num = numbers;
    int min = *num;
    WaG_sortieren(n, numbers);
    for (int i = 0; i < n-1; ++i,++num)
        min = (*(num+1)-*num<min)*(*(num+1)-*num)+(*(num+1)-*num>=min)*min;
    return min;
}

void WaG_alles_ausgeben(const int n, int *numbers){
    printf("Anzahl der Zahlen: %d\n",n);
    printf("Die Zahlen: ");
    WaG_sortieren(n,numbers);
    int *num = numbers;
    for(int i = 0; i<n;++i,++num){
        printf(" %d",*num);
    }
    printf("\nMittelwert: %f\nMinimaler Abstand: %d\n", WaG_mittelwert_ermitteln(n,numbers), WaG_benachbarte_mit_minimalen_abstand_ermitteln(n,numbers));
}

