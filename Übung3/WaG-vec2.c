//Gregor Wagner
//WaG-vec2.c

//includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Prototypen
const char *strcichr (const char *s, char c);                   //strchr
const char *strrcichr (const char *s, char c);                   //strrchar
const char *strcipbrk (const char *s, const char *accapt);      //strpbrk

//main
int main (void) {
    //variablen
    char str[20] = "Hallo Welt!\n";
    char c[] = "llo";
/*TODO Bugfixing, bei strcipbrk kommt das Falsche zurück, weil anscheinend was falsch in c steh*/
    const char *result;

    result = strcichr(str,c[0]);
    printf("strcichr: %c\n",*result);

    result = strrcichr(str,c[0]);
    printf("strrcichr: %c\n",*result);

    result = strcipbrk(str,c);
    printf("strcipbrk: %c\n",*result);


    return 0;
}


const char *strcichr (const char *s, char c){                   //strchr
    for(int i=0; i < sizeof(s);++i)
        if (c==tolower(s[i]))
            return &s[i];
    return NULL;
}


const char *strrcichr (const char *s, char c){                   //strrchar
    for(int i=sizeof(s); i ;--i)
        if (c==tolower(s[i]))
            return &s[i];
    return NULL;
}

const char *strcipbrk (const char *s, const char *accapt){      //strpbrk
    for (int i = 0; i<sizeof(s);++i)
        for(int j = 0; j<sizeof(accapt);++j)
            if(tolower(s[i])==tolower(accapt[j]))
                return &s[i];
    return NULL;
}
