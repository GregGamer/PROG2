//Gregor Wagner
//WaG-vec1.c

//inlcudes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//prototypes
void chletter_WaG(char input[]);

//globalen Variablen

//main
int main (){
    //variablen
    char input[20];

    //input
    printf("Text eingeben: ");
    fgets(input, 20, stdin);

    printf("Eingegebener Text: %s", input);
    chletter_WaG(input);
    printf("Geaenderter Text: %s", input);

    return 0;
}

void chletter_WaG(char input[]){
    for (int i = 0; strcmp(&input[i],"\n"); ++i){
        if ( islower(input[i]) ){
            input[i] = toupper(input[i]);
        } else if ( isupper(input[i]) ){
            input[i] = tolower(input[i]);
        }
    }

}
