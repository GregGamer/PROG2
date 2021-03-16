//Gregor Wagner
//WaG-bsp7.c

//include
#include <stdio.h>
#include <string.h>

//prototypen

//main
int main (){
    //variablen
    int input;
    int roemischen_zahlen[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const char *roemischen_zeichen[] = {"M","CM","D","CD","C","XC","L","XL","IX","V","IV","I"};

    //input
    printf("Zahl eingeben: ");
    scanf("%d",&input);

    printf("Roemische Zahl: ");

    for(int i = 0; i < (int)sizeof(roemischen_zahlen); ++i){
        
        for(int j = 0; j < (int)(input/roemischen_zahlen[i]); ++j){
            printf("%s", roemischen_zeichen[i]); 
        }
        input %= roemischen_zahlen[i];

    }

    return 0;
}
