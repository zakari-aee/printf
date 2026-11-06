#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int a = -1337;
    char *s = "zakariae";
    int f1;
    int f2;
    // f1 = ft_printf("slm ana db ndiro test %X %x %d %i %u %s %p\n",a,a,a,a,a,s ,&s);
    ft_printf("'% &'%s& % %%'s' \n", "ss");
       printf("'% &'%s& % %%'s' \n", "ss");
    
}