//Gregor Wagner
//WaG-vec3.c

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Makros und globale Constanten

//Prototypen

int main (void) {
    //variablen
    char input[100];
    const char delimeter[2] = " ";
    char *token;

    //input
    printf("Eingabe der Zahlen: ");
    scanf("%s",input);
    token = strtok(input, delimeter);
    
    int size = atoi(token);
    int zahlen[size];
    int i=0;
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimeter);
        if(token != NULL){
            zahlen[i]=atoi(token);
            printf("%d --", zahlen[i]);
            i=i+1;
        }
    } 


    return 0;
}
