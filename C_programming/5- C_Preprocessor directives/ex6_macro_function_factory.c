#include <stdio.h>

#define function(name,num) \
int fun_##name(int x) \
{ \
return (x*num) ; \
}

function(mul_two,2)
function(mul_three,3)

int main()
{
    printf("12*2 : %d\n",fun_mul_two(12));
    printf("9*3 : %d\n",fun_mul_three(9));

    return 0;
}