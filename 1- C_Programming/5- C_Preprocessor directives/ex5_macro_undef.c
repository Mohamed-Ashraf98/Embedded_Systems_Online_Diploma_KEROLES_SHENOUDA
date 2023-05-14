#include <stdio.h>

#define height 100

int main()
{
    printf("height = %d\n",height);

    #undef height 
    #define height 300

    printf("height = %d\n",height);

    return 0;
}