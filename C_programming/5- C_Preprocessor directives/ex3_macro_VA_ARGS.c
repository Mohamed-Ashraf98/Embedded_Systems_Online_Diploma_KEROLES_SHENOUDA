#include <stdio.h>

#define num 7
#define Mohamed(...) printf(__VA_ARGS__);
#define learn_in_depth(val,...) printf(__VA_ARGS__,val);

int main()
{
    printf("num = %d\n",num);
    Mohamed("num = %d\n",num)
    learn_in_depth(num,"num = %d\n")

    return 0;
}