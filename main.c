#include "ft_printf.h"

int main()
{
    int a = -1337;
    char *s = "zakariae";
    ft_printf("slm ana dn ndiro test %X %x %d %i %u %s %p\n",a,a,a,a,a,s ,&s);
    printf("slm ana dn ndiro test %X %x %d %i %u %s %p",a,a,a,a,a,s ,&s);

}