//Wendler Stefan
//WES-cmdline1.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS 500

void readLines(char *lines[MAX_CHARS], size_t *const quantity);
void sortLines(char *lines[], const size_t quantity, const bool desc, const int crit);
bool checkIfLineSwap(char **copy, char **helper, const int crit);
int getSpacePos(char **pointer, const int crit);

int main(int argc, char **argv)
{
	char *lines[MAX_CHARS];
	size_t quantity;
	bool desc = false;
	int crit = 1;
	for (int arg = 1; arg<argc; ++arg)
	{
		if (argv[arg][0] == '-')
		{
			if (argv[arg][1] == 'd')
				desc = true;
			if (argv[arg][1] == 'n')
				crit = atoi(argv[arg+1]);
		}
	}
	printf("\nWord(n): %d\nDescending: %s\n", crit, desc ? "true" : "false");
	printf("\nInput:\n");
	readLines(lines, &quantity);
	if (quantity)
	{
		sortLines(lines, quantity, desc, crit);
		printf("\nOutput:\n");
		for (size_t i=0; i<quantity; ++i)
			printf("%s", lines[i]);
	}
	while(quantity)
		free(lines[--quantity]);
	return 0;
}

void readLines(char *lines[], size_t *const quantity)
{
	char *eof;
	char line[MAX_CHARS];
	size_t counter = 0;
	while (counter < MAX_LINES)
	{
		eof = fgets(line, MAX_CHARS, stdin);
		if (!eof)
			break;
		lines[counter] = calloc(sizeof(char), strlen(line)+1);
		strcpy(lines[counter], line);
		++counter;
	}
	*quantity = counter;
}
:q

void sortLines(char *lines[], const size_t quantity, const bool desc, const int crit)
{
	char **copy = lines;
	int offset = 1;
	if (desc)
	{
		copy = lines + quantity-1;
		offset = -1;
	}
	char **helper;
	bool sorted = false;
	char *tmp;
	while(!sorted)
	{
		sorted = true;
		for(size_t i=0; i<quantity-1; ++i, copy+=offset)
		{
			helper = copy + offset;
			if (checkIfLineSwap(copy, helper, crit))
			{
				sorted = false;
				tmp = *copy;
				//*copy = *helper;
				//*helper = tmp;

				*copy = realloc(*helper, strlen(*helper)+1);
				strcpy(*copy, *helper);
				*helper = realloc(tmp, strlen(tmp)+1);
				strcpy(*helper, tmp);
			}
		}
		copy = copy - offset * (quantity-1);
	}
}

bool checkIfLineSwap(char **copy, char **helper, const int crit)
{
	bool swap = false;
	int counter = 0;
	int spacePosCopy = 0;
	int spacePosHelper = 0;
	if (crit > 1)
	{
		spacePosCopy = getSpacePos(copy, crit);
		spacePosHelper = getSpacePos(helper, crit);
		if (spacePosCopy == 0 && spacePosHelper != 0)
			return false;
		if (spacePosCopy != 0 && spacePosHelper == 0)
			return true;
		if (spacePosCopy != 0 && spacePosHelper != 0)
		{
			*copy += ++spacePosCopy;
			*helper += ++spacePosHelper;
		}
	}
	for ( ; **copy != '\0' && **helper != '\0'; ++counter, ++*copy, ++*helper)
	{
		if (**copy > **helper)
		{
			swap = true;
			break;
		}
		else if (**copy < **helper)
		{
			swap = false;
			break;
		}
	}
	*copy -= (counter + spacePosCopy);
	*helper -= (counter + spacePosHelper);
	return swap;
}

int getSpacePos(char **pointer, const int crit)
{
	int i = 0;
	int spacePos = 0;
	int spaceCnt = 0;
	for ( ; **pointer!='\0'; ++i, ++*pointer)
	{
		if (**pointer == ' ' && spaceCnt != crit-1)
		{
			spacePos = i;
			++spaceCnt;
		}
	}
	*pointer -= i;
	if (crit - 1 == spaceCnt)
		return spacePos;
	return 0;
}
