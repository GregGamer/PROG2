//Arved Didio, Marie Strohm, Gregor Wagner, Jonas Kronberger
//StM-bsp8.c
#include <stdio.h>
#include <stdint.h>
//display the size and ranges for each of Cs data types.
//Compile 32bit and 64bit exe and compare result
int main()
{
        printf("%20s%20s\n", "Type", "Bytes");
        printf("%20s%20zu\n","char", sizeof(char));
        printf("%20s%20zu\n","int8_t", sizeof(int8_t));
        printf("%20s%20zu\n","unsigned char", sizeof(unsigned char));

        printf("%20s%20zu\n","uint8_t", sizeof(uint8_t));
        printf("%20s%20zu\n","short", sizeof(short));
        printf("%20s%20zu\n","int16_t", sizeof(int16_t));
        printf("%20s%20zu\n","uint16t", sizeof(uint16_t));

        printf("%20s%20zu\n","int", sizeof(int));
        printf("%20s%20zu\n","unsigned", sizeof(unsigned));
        printf("%20s%20zu\n","long", sizeof(long));
        printf("%20s%20zu\n","unsigned long", sizeof(unsigned long));

        printf("%20s%20zu\n","int32_t", sizeof(int32_t));
        printf("%20s%20zu\n","uint32_t", sizeof(uint32_t));
        printf("%20s%20zu\n","long long ", sizeof(long long));
        printf("%20s%20zu\n","int64_t", sizeof(int64_t));


        printf("%20s%20zu\n","unsigned long long", sizeof(unsigned long long));
        printf("%20s%20zu\n","uint64_t", sizeof(uint64_t));
        printf("%20s%20zu\n","float", sizeof(float));
        printf("%20s%20zu\n","double", sizeof(double));
        printf("%20s%20zu\n","long double", sizeof(long double));
        printf("%20s%20zu\n","_Bool", sizeof(_Bool));
        return 0;
}
