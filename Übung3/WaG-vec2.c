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
    const char *result;

    result = strcichr(str,c[0]);
    printf("strcichr: %c\n",*result);

    result = strrcichr(str,c[0]);
    printf("strrcichr: %c\n",*result);

    result = strcipbrk(str,c);
    printf("strcipbrk: %c\n",*result);


    char *s;
    &s      //addresse vom pointer;
    *s      //value
    s       //Adresse von value 

    return 0;
}

const char *strcichr (const char *s, char c){                   //strchr
    char z = tolower(c);
    char Z = toupper(c);
    for(; *s != '\0'; ++s)
        if(*s==z || *s==Z)
            return s;
    return NULL;
}


const char *strrcichr (const char *s, char c){                   //strrchar
    for(int i=strlen(s); i ;--i)
        if (tolower(c)==tolower(s[i]))
            return &s[i];
    return NULL;
}

const char *strcipbrk (const char *s, const char *accapt){      //strpbrk
    for (int i = 0; i<strlen(s);++i)
        for(int j = 0; j<strlen(accapt);++j)
            if(tolower(s[i])==tolower(accapt[j]))
                return &s[i];
    return NULL;
}
