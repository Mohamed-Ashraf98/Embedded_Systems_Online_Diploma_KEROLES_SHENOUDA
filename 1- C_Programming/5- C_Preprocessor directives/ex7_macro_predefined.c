#include <stdio.h>

int main()
{
    printf("__STDC__ = %ld\n",__STDC__);
    printf("__STDC_VERSION__ = %ld\n",__STDC_VERSION__);
    printf("__STDC_HOSTED__ = %ld\n",__STDC_HOSTED__);
    printf("__FILE__ = %S\n",__FILE__);
    printf("__LINE__ = %d\n",__LINE__);
    printf("__DATE__ = %S\n",__DATE__);
    printf("__TIME__ = %S\n",__TIME__);
    printf("__func__ = %s\n",__func__);

    return 0;
}