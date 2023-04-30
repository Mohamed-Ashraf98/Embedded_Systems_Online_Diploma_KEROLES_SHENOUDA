#include <stdio.h>

#define greater(num1,num2) \
if(x>y) \
printf("%d is greater than %d\n",num1,num2); \
else \
printf("%d is not greater than %d\n",num1,num2);

int main()
{
    int x=5,y=6;
    greater(x,y)

    x=15,y=10;
    greater(x,y)

    return 0;
}