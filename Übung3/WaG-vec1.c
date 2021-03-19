//Gregor Wagner
//WaG-vec1.c

//inlcudes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//prototypes
void chletter_WaG(char input[]);
void chdigit_WaG(char input[]);
void printline_WaG(char input[]);
//globalen Variablen

//main
int main (){
    //variablen
    char input[20] = "";

    while (1){
        //input
        printf("Text eingeben: ");          //quit
        fgets(input, 20, stdin);

        if(!strcmp(input,"quit\n")){
            break;
        }

        printf("%s", input);
        chletter_WaG(input);
        chdigit_WaG(input);
        printf("%s", input);
        printline_WaG(input);
    }

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

void chdigit_WaG(char input[]){
    for (int i = 0; strcmp(&input[i],"\n"); ++i){
        if ( isdigit(input[i]) ){
            int help = (int)input[i] - 48; 
            help = (help +10 -1) % 10;
            input[i] = (char)help + 48;
        } 
    }
}

void printline_WaG(char input[]){
    for (int i = 0; strcmp(&input[i],"\n"); ++i){
        int help = (int)input[i]; 
        if (help >= 32 && help <= 127)
            printf("%c %x|",input[i],help);
        else
            printf("?");
    }
    printf("\n");
}
