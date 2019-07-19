#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char str[] = "memmove can be very useful......";
    memmove (str+20, str+15, 11);
    //char str1[] = "abcde###";
    // memcpy(str1+3, str1, 5);
    puts (str);
    //puts (str1);
    return 0;
}
