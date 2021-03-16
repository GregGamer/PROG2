//Gregor Wagner, Marie Strom, Jonas Kronberger, Arved Didio
//WaG-bsp4.c
#include <stdio.h>
#include <math.h>
//User gibt 3 Seitenlaengen fuer das Dreieck ein. Programm berechnet, ob Dreieck gleichseitig, gleichschenkelig, rechtwinkelig oder allgemein ist oder kein Dreieck. Wenn gueltig, dann Umfang und Flaeche ausgeben.

int main()
{
	//Einlesen Seitenlaengen
	int a;
	int b;
	int c;
	int istriangle = 1;
	double area;

	printf("Enter three side length \n");
	scanf("%d %d %d", &a, &b, &c);
	int umfang = a + b + c;
	double s = 0.5*umfang;
	printf("Dreieck ist ");
	if((a <= b+c) && ( b <= a+c) && (c <= a+b))

	{
		if(a == b && a == c )
		{
			printf("gleichseitiges \n");
			area = 0.25 * a * a * sqrt(3);
		}	
		else if((a==b  && a != c) ||( a !=b && b==c) ||( a==c && b != c ))
		{
			printf("gleichschenkligs \n");

		}
		else if(( pow(a,2) == pow(b,2) + pow(c,2)) || ( pow(c,2) == pow(a,2) + pow(b,2)) ||(  pow(b,2) == pow(a,2) + pow(c,2)))
		{
			printf("rechtwinkligs \n");

		}

		printf("Dreieck");
	}else {
		printf("Kein Dreieck");
		istriangle = 0;
	}

	if(istriangle == 1)
	{
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		printf("Umfang ist %d \n", umfang);	
		printf("Flaeche ist %lf \n", area);
	}


	return 0;

}
