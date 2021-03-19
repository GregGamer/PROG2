//Gregor Wagner, Strohm Marie, Arved Didio, Jonas Kronberger
//WaG-bsp1.c

//include
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//globale constanten
const int IS_NUMMER = 8;
const int GAMEFIELD_WIDTH = 24;
const int GAMEFIELD_HEIGHT = 24;
const int X = 5;
const int Y = 1;
const int Z = 15;

//prototypen
void initGamefield(int WaG_Gamefield[][GAMEFIELD_HEIGHT]);
void WaG_PrintGame(int WaG_Gamefield[][GAMEFIELD_HEIGHT], int roboterPosition[]);
void WaG_CreateObstacles(int WaG_Gamefield[][GAMEFIELD_HEIGHT], int n);
void WaG_MoveRoboter(int roboterPosition[]);

int main (void) {
    //variablen
    int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT] = {{0}};
    int roboterPosition[] = {(IS_NUMMER%8)%GAMEFIELD_WIDTH,(IS_NUMMER%4)%GAMEFIELD_HEIGHT,IS_NUMMER % 4,Z};
    int anzObstacles = (GAMEFIELD_WIDTH*GAMEFIELD_HEIGHT)*0.15;

    //initGamefield(WaG_Gamefield);
    WaG_CreateObstacles(WaG_Gamefield, anzObstacles);
    WaG_PrintGame(WaG_Gamefield,roboterPosition);

    while(roboterPosition[3] >= 0){
        WaG_MoveRoboter(roboterPosition);
        WaG_PrintGame(WaG_Gamefield,roboterPosition);

        if (WaG_Gamefield[roboterPosition[1]][roboterPosition[0]] >= 1){
            roboterPosition[3] += WaG_Gamefield[roboterPosition[1]][roboterPosition[0]];
            WaG_Gamefield[roboterPosition[1]][roboterPosition[0]] = 0;
        }

        roboterPosition[3] -= Y;
    }

    return 0;
}

void initGamefield (int WaG_Gamefield[][GAMEFIELD_HEIGHT]) {
    for(int i = 0; i<GAMEFIELD_HEIGHT; ++i){
        for (int j = 0; j < GAMEFIELD_WIDTH; ++j){
            (WaG_Gamefield[i][j]) = 0;
        }
    }
}

void WaG_PrintGame (int WaG_Gamefield[][GAMEFIELD_HEIGHT], int roboterPosition[]) {
    int sum = 0;

    system("@cls||clear");
    
    for (int help = 0; help < GAMEFIELD_WIDTH; ++help)
        printf("=");
    printf("\n");

    for(int i = 0; i < GAMEFIELD_HEIGHT; ++i){
        for (int j = 0; j < GAMEFIELD_WIDTH; ++j){

            if(roboterPosition[0] == j && roboterPosition[1] == i){
                printf("0");
                continue;
            }

            if (WaG_Gamefield[i][j] == 0){
                printf(".");
            }
            else if (WaG_Gamefield[i][j] >= 1) {
                printf("#");
            }

            sum += WaG_Gamefield[i][j];
        }
        printf("\n");
    }

    for (int help = 0; help < GAMEFIELD_WIDTH; ++help)
        printf("=");
    printf("\n");

    printf("Deine Punkte: %d\n", roboterPosition[3]);
    printf("Wert des Feldes: %d\n", WaG_Gamefield[roboterPosition[1]][roboterPosition[0]]);

    if (sum == 0){
        system("@cls||clear");

        printf("==================\n");
        printf("    GRATULATION   \n");
        printf("      DU HAST     \n");
        printf("     GEWONNEN     \n");
        printf("==================\n");

        exit(1);
    }
}

void WaG_CreateObstacles(int WaG_Gamefield[][GAMEFIELD_HEIGHT],int n){
    int Xrand;
    int Yrand;
    time_t t;

    srand((unsigned) time(&t));

    for (int i = 0; i < n; ++i){
        Xrand = rand() % GAMEFIELD_WIDTH;
        Yrand = rand() % GAMEFIELD_HEIGHT;
        
        if (Xrand != 0 && Yrand != 0){
            if (WaG_Gamefield[Xrand][Yrand] >= 1){
                --i;
            }
            WaG_Gamefield[Xrand][Yrand] = rand() % 5 + 1;
        }
    }
}

void WaG_MoveRoboter(int roboterPosition[]){
    char input;

    system("/bin/stty raw");
    input = getchar();
    system("/bin/stty cooked");

    if (!strcmp(&input,"h")){           //left
        roboterPosition[0] = (roboterPosition[0]+GAMEFIELD_WIDTH-1)%GAMEFIELD_WIDTH;
    } else if (!strcmp(&input,"j")){    //bottom
        roboterPosition[1] = (roboterPosition[1]+1)%GAMEFIELD_HEIGHT;
    } else if (!strcmp(&input,"k")){    //up
        roboterPosition[1] = (roboterPosition[1]+GAMEFIELD_HEIGHT-1)%GAMEFIELD_HEIGHT;
    } else if (!strcmp(&input,"l")){    //right
        roboterPosition[0] = (roboterPosition[0]+1)%GAMEFIELD_WIDTH;
    } else if (!strcmp(&input,"q")){    //quit
        exit(1);
    }
}
