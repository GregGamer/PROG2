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
const int GAMEFIELD_WIDTH = 8;
const int GAMEFIELD_HEIGHT = 8;

//prototypen
void initGamefield(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT]);
void WaG_PrintGame(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int roboterPosition[]);
void WaG_CreateObstacles(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int n);
void WaG_MoveOneStep(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int roboterPosition[]);
void WaG_StepByStep(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int roboterPosition[]);
void WaG_N_Steps(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int roboterPosition[]);

int main (void) {
    //variablen
    int WaG_Gamefield[GAMEFIELD_HEIGHT][GAMEFIELD_WIDTH];
    int roboterPosition[] = {IS_NUMMER%8%GAMEFIELD_WIDTH,IS_NUMMER%4%GAMEFIELD_HEIGHT,IS_NUMMER % 4};
    int anzObstacles = 5;
    char input[5] = "";

    initGamefield(WaG_Gamefield);
    WaG_CreateObstacles(WaG_Gamefield, anzObstacles);

    while (strcmp(input,"1") && strcmp(input,"2")){
        //input
        printf("1: Step by Step\n");
        printf("2: Move N Steps\n");
        printf("Eingabe: ");
        scanf("%s",input);
        printf("----------------\n");
    }

    if(strcmp(input,"2")){
        WaG_N_Steps(WaG_Gamefield,roboterPosition);
    } else {
        WaG_StepByStep(WaG_Gamefield, roboterPosition);
    }

    return 0;
}

void initGamefield (int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT]) {
    for(int i = 0; i<GAMEFIELD_WIDTH; ++i){
        for (int j = 0; j < GAMEFIELD_HEIGHT; ++j){
            (WaG_Gamefield[i][j]) = 0;
        }
    }
}

void WaG_PrintGame (int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int roboterPosition[]) {

    system("@cls||clear");
    
    for(int i = 0; i < GAMEFIELD_WIDTH; ++i){
        for (int j = 0; j < GAMEFIELD_HEIGHT; ++j){

            if(roboterPosition[0] == j && roboterPosition[1] == i){
                printf("0");
                continue;
            }

            if (WaG_Gamefield[i][j] == 0){
                printf(".");
            }
            else if (WaG_Gamefield[i][j] == 1) {
                printf("#");
            }

        }
        printf("\n");
    }
}

void WaG_CreateObstacles(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT],int n){
    int Xrand;
    int Yrand;
    time_t t;

    srand((unsigned) time(&t));

    for (int i = 0; i < n; ++i){
        Xrand = rand() % GAMEFIELD_WIDTH;
        Yrand = rand() % GAMEFIELD_HEIGHT;
        WaG_Gamefield[Xrand][Yrand] = 1;
    }
}

void WaG_MoveOneStep(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int roboterPosition[]){
    int nextStep[2];
    nextStep[0] = roboterPosition[0] + ((roboterPosition[2] == 1) * 1 + (roboterPosition[2] == 3 * -1));
    nextStep[1] = roboterPosition[1] + ((roboterPosition[2] == 2) * 1 + (roboterPosition[2] == 0 * -1));

    //Berechnet mir die neue Blickrichtung wenn vor dem Bot ein Hinderniss ist
    roboterPosition[2] = (WaG_Gamefield[nextStep[0]][nextStep[1]] == 1) * \
                         (((IS_NUMMER/5) * 1 + !(IS_NUMMER/5) * -1 + roboterPosition[2]) % 4); 

    roboterPosition[0] = nextStep[0] % GAMEFIELD_WIDTH;
    roboterPosition[1] = nextStep[1] % GAMEFIELD_HEIGHT;
}

void WaG_StepByStep(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int roboterPosition[]){
    //variablen
    char input[10] = "";

    WaG_PrintGame(WaG_Gamefield,roboterPosition);
        
    while (strcmp(input,"quit")){
        //input
        printf("StepByStep Mode, quit by typing quit: ");
        scanf("%s",input);
        
        WaG_MoveOneStep(WaG_Gamefield, roboterPosition);
        WaG_PrintGame(WaG_Gamefield, roboterPosition);
    }
}

void WaG_N_Steps(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT], int roboterPosition[]){
    //variablen
    int input;

    //input
    printf("Eingabe der Anzahl der Schritte: ");
    scanf("%d",&input);

    WaG_PrintGame(WaG_Gamefield,roboterPosition);

    for (int i = 0; i < input; ++i){
        WaG_MoveOneStep(WaG_Gamefield,roboterPosition);
        sleep(1);
        WaG_PrintGame(WaG_Gamefield,roboterPosition);
    }

}
