#include <stdio.h>
#include "ft_printf.h"
int main(){
    char str[50];
    
    // taking string as input
    scanf("%s", str);
    ft_printf("Entered String: %s", str);
    return 0;
}