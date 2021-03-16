//Gregor Wagner, Marie Strohm, Jonas Kronberger, Arved Didio
//WaG-bsp7.c

//include
#include <stdio.h>
#include <string.h>

//prototypen

//main
int main (){
    //variablen
    int input;

    //input
    printf("Zahl eingeben: ");
    scanf("%d",&input);
    
    printf("Roemische Zahl: ");
    
    while(input != 0){
        if(input > 1000){
            printf("M");
            input -= 1000;
        }
        else if(input > 900){
            printf("CM");
            input -= 900;
        }
        else if(input > 500){
            printf("D");
            input -= 500;
        }
        else if(input > 400){
            printf("CD");
            input -= 400;
        }
        else if(input > 100){
            printf("C");
            input -= 100;
        }
        else if(input > 90){
            printf("XC");
            input -= 90;
        }
        else if(input > 50){
            printf("L");
            input -= 50;
        }
        else if(input > 40){
            printf("XL");
            input -= 40;
        }
        else if(input > 10){
            printf("X");
            input -= 10;
        }
        else if(input > 9){
            printf("IX");
            input -= 9;
        }
        else if(input > 5){
            printf("V");
            input -= 5;
        }
        else if(input > 4){
            printf("IV");
            input -= 4;
        }
        else if(input >= 1){
            printf("I");
            input -= 1;
        }
    }
    printf("\n");
    return 0;
}
