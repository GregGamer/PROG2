//Gregor Wagner, Strohm Marie, Arved Didio, Jonas Kronberger
//WaG-bsp1.c

//include
#include <stdio.h>

//globale constanten
const int GAMEFIELD_WIDTH = 8;
const int GAMEFIELD_HEIGHT = 8;

//prototypen
void initGamefield(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT]);
void printGamefield(int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT]);

int main (void) {
    //variablen
    int WaG_Gamefield[GAMEFIELD_HEIGHT][GAMEFIELD_WIDTH];

    initGamefield(WaG_Gamefield);
    printGamefield(WaG_Gamefield);


    return 0;
}

void initGamefield (int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT]) {
    for(int i = 0; i<GAMEFIELD_WIDTH; ++i){
        for (int j = 0; j < GAMEFIELD_HEIGHT; ++j){
            (WaG_Gamefield[i][j]) = 0;
        }
    }
}

void printGamefield (int WaG_Gamefield[GAMEFIELD_WIDTH][GAMEFIELD_HEIGHT]) {
    for(int i = 0; i<GAMEFIELD_WIDTH; ++i){
        for (int j = 0; j < GAMEFIELD_HEIGHT; ++j){
            if (WaG_Gamefield[i][j] == 0){
                printf(".");
            }
            else if (WaG_Gamefield[i][j] == 1) {
                printf("#");
            }
            else if (WaG_Gamefield[i][j] == 2) {
                printf("0");
            }
        }
        printf("\n");
    }
}
