#include <stdio.h>

void __attribute__((constructor)) india();
void __attribute__((destructor)) usa();

void india(void);
void usa(void);

int main()
{
    printf("main\n");
    
    return 0;
}

void india(void)
{
    printf("india\n");
}

void usa(void)
{
    printf("usa\n");
}