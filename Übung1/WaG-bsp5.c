// Marie Strohm, Gregor Wagner, Jonas Kronberger, Didio Arved
// WaG-bsp5.c
#include <stdio.h>

//Benutzer gibt Zahl zwischen 1 - 12 ein worauf das dazugehörige Monat ausgegeben wird

int main(){

int month = 0;


while(month < 1 || month > 12){ //abfrage solange wert außerhalb liegt

	printf("Input Number between 1 and 12: ");
	scanf("%d", &month);

}


switch(month){

case 1:
    printf("January\n");
    break;

case 2:
    printf("February\n");
    break;

case 3:
    printf("March\n");
    break;

case 4:
    printf("April\n");
    break;

case 5:
    printf("May\n");
    break;

case 6:
    printf("June\n");
    break;

case 7:
    printf("July\n");
    break;

case 8:
    printf("August\n");
    break;

case 9:
    printf("September\n");
    break;

case 10:
    printf("October\n");
    break;

case 11:
    printf("November\n");
    break;

case 12:
    printf("December\n");
    break;


}


return 0;

}
