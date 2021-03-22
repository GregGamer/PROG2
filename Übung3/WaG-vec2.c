//Gregor Wagner
//WaG-vec2.c

//includes
#include <stdio.h>
#include <stdlib.h>

//Makros und globale Constanten

//Prototypen
const char *strcichr (const char *s, char c);                   //strchr
const char *strrcichr (const char *s, char c);                   //strrchar
const char *strcipbrk (const char *s, const char *accapt);      //strpbrk

int main (void) {
    //variablen
    char str[20] = "Hallo Welt!\n";
    char c = " ";
    char result[5];

    result = strcichr(str,c);
    printf("%s",result);

    result = strrcichr(str,c);
    printf("%s",result);

    result = strcipbrk(str,c);
    printf("%s",result);


    return 0;
}


const char *strcichr (const char *s, char c){                   //strchr

    return NULL;
}


const char *strrcichr (const char *s, char c){                   //strchr

    return NULL;
}


const char *strcipbrk (const char *s, const char *accapt){      //strpbrk


    return NULL;
}
