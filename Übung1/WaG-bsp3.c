//Marie Strohm, Gregor Wagner, Jonas Kronberger, Arved Didio
//WaG-bsp3.c

#include <stdio.h>

int main (void){
    int time = 0;
	printf("Please enter time: ");
	scanf("%d", &time);

    int days = time/86400;
    time %= 86400;
    int hours = time/3600;
    time %= 3600;
    int minutes = time/60;
    time %= 60;
    int seconds = time;

    printf("Days: %d, Hours: %d, Minutes: %d, Seconds: %d",days,hours,minutes,seconds);
    
    return 0;
}
