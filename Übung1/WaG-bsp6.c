//Marie Strohm, Gregor Wagner, Jonas Kronberger, Arved Didio
//WaG-bsp6.c

#include <stdio.h>

int main(){
	char tree = 'M';
	char base = 'S';

	int height;
	int growth;

	printf("Please enter height and growth");
	scanf("%d %d", &height, &growth);

	int i;
	int a;
	int end;
	int tmp;

	end = ((height - 1) *  growth) +1;
	printf("ende : %d \n", end);
	tmp = end;
	for(i = 0; i < height ; ++i)
	{
		printf("\n");
		for(a = 0; a < tmp/2; ++a)
		{
			printf(" ");
		}
		for(a = 0; a < i*growth + 1;  ++a)
		{
			printf("%c", tree);
		}
		for(a = tmp - (tmp/2); a < tmp; ++a)
		{
			printf(" ");
		}
		tmp = tmp - growth;
	}

	printf("\n");

	for(i=0; i < end/2; i++)
	{
		printf(" ");
	}

	printf("%c", base);

	for(i=end/2; i < end; i++)
	{
		printf(" ");
	}



	return 0;
}


