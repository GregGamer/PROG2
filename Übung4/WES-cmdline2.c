//Wendler Stefan
//WES-cmdline2.c
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct st_WEScandle
{
	short x;
	short y;
	short L;
} t_WEScandle;

t_WEScandle* WES_CheckParams(const int argc, char **argv, int *const quantity);
void WES_PrintGameField(const int gamefield[][SIZE]);
void WES_PrintDarkField(const int gamefield[][SIZE]);
void WES_Illuminate(int gamefield[][SIZE], const t_WEScandle *const candles, const int quantity);
void illuminateField(int gamefield[][SIZE], const int cRow, const int cCol, const int strength);

int main(int argc, char **argv)
{
	int gamefield[SIZE][SIZE] = {0};
	t_WEScandle *candles;
	int quantity = 0;
	if (argc == 1)
	{
		WES_PrintGameField(gamefield);
		return 0;
	}
	candles = WES_CheckParams(argc, argv, &quantity);
	WES_Illuminate(gamefield, candles, quantity);
	WES_PrintGameField(gamefield);
	WES_PrintDarkField(gamefield);
	free(candles);
	return 0;
}

t_WEScandle* WES_CheckParams(const int argc, char **argv, int *const quantity)
{
	t_WEScandle *candles = malloc((argc-1) * sizeof(t_WEScandle));
	int counter = 0;
	t_WEScandle candle;
	for (int arg=1; arg<argc; arg++)
	{
		if (argv[arg][0] == '-' && argv[arg][1] == 'k')
		{
			candle.x = atoi(argv[arg]+2);
			candle.y = atoi(argv[arg]+4);
			candle.L = atoi(argv[arg]+6);
			candles[counter] = candle;
			++counter;
		}
	}
	*quantity = counter;
	return candles;
}

void WES_PrintDarkField(const int gamefield[][SIZE])
{
	printf("Darkfields: ");
	for (int cRow=0; cRow<SIZE; ++cRow)
		for (int cCol=0; cCol<SIZE; ++cCol)
			if (gamefield[cRow][cCol] == 0)
				printf("(%d,%d); ", cCol+1, cRow+1);
}

void WES_PrintGameField(const int gamefield[][SIZE])
{
	for (int cRow=0; cRow<SIZE; ++cRow)
	{
		for (int cCol=0; cCol<SIZE; ++cCol)
		{
			if (gamefield[cRow][cCol] != 0)
			{
				//printf("\033[0;32m"); //green
				printf("\033[0;31m"); //red
				printf("%d ", gamefield[cRow][cCol]);
			}
			else 
			{
				//printf("\033[0;30m"); //black
				printf("\033[0;37m"); //white
				printf("%d ", gamefield[cRow][cCol]);
			}

		}
		printf("\033[0;37m"); //white
		printf("\n");
	}
}

void WES_Illuminate(int gamefield[][SIZE], const t_WEScandle *const candles, const int quantity)
{
	int candle, line, i;
	short cRow, cCol, strength;
	short row, col;
	for (candle=0; candle<quantity; ++candle)
	{
		cRow = candles[candle].y;
		cCol = candles[candle].x;
		strength = candles[candle].L;
		gamefield[cRow][cCol] = candles[candle].L;
		for (line=1; candles[candle].L-line>0; ++line)
		{
			strength = candles[candle].L - line;
			for (i=line*(-1); i<=line; ++i)
			{
				row = cRow + i;
				col = cCol + i;
				illuminateField(gamefield, cRow-line, col, strength);
				illuminateField(gamefield, cRow+line, col, strength);
				illuminateField(gamefield, row, cCol-line, strength);
				illuminateField(gamefield, row, cCol+line, strength);
			}
		}
	}
}

void illuminateField(int gamefield[][SIZE], const int row, const int col, const int strength)
{
	if (row >= 0 && row < SIZE && col >= 0 && col < SIZE &&
			strength > gamefield[row][col])
		gamefield[row][col] = strength;
}

