//Gregor Wagner
//WaG-bsp1.c

#include <stdio.h>

int main (void){
    int euros[] = {500,200,100,50,20,10,5,2,1};
    int input = 0; 
    
    printf("Bitte den Euro Betrag eingeben: "); 
    scanf("%d",&input);

    for(int i = 0; i<(int)sizeof(euros);++i){
        if (input < 0){
            return 0;
        }

        printf("%d€: %d",euros[i],input/euros[i]);

        input = input % euros[i];
    }

}
