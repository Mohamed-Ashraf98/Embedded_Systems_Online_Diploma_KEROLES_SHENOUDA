#include <stdio.h>

#define CAT(a,...) PRIMITIVE_CAT(a,__VA_ARGS__)
#define PRIMITIVE_CAT(a,...) a##__VA_ARGS__
#define DEC(x) CAT(DEC_,x)
#define DEC_7 7
#define Dprintf(...) printf(__VA_ARGS__);

int main()
{
    Dprintf("DEC(7) = %d\n",DEC(7))

    return 0;
}