#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int    main(void)
{
    int    r1;
    int    r2;

    close(1);
    setvbuf(stdout, NULL, _IONBF, 0);
    
    char *p = NULL;
    r1 = ft_printf("hello %s\n",p);
    r2 = printf("hello %s\n", p);
    fprintf(stderr, "ft_printf: %d\nprintf:    %d\n", r1, r2);
    return (0);
}