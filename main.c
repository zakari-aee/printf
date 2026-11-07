#include <stdio.h>
#include "ft_printf.h"

int main()
{
    char *str = "";
    //printf("This should not be able to compile %s\n", 0x01);
    ft_printf("This shouls not be able to compile %s\n", 0x01);

}