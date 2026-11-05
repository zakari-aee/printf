/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:49:01 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/05 11:34:05 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int ft_print_char(int c)
{
	if(write(1,&c,1) == -1)
		return -1;
	return(write(1,&c,1));
}

int ft_print_str(char *str)
{
	int count;
	count = 0;
	while(*str)
	{
		ft_print_char((int)*str);
		str++;
		count++;
	}
	return count;
}

int ft_print_digit(int a,int base)
{
	int count;
	count = 0;
	char *b = "0123456789abcdef";
	if(a < 0)
	{
		count += write(1,"-",1);
		a *= -1;
	}
	else if(a < base)
		count += ft_print_char((int )b[a]);
	else if(a >= base)
	{
		count += ft_print_digit(a / 10,base);
		return (1 + ft_print_digit(a %10,base));
	}
	return count;
}

int print_format(char sep,va_list ap)
{
	int count;
	count = 0;
	if(sep == 'c')
		count += ft_print_char(va_arg(ap,int));
	else if(sep == 's')
		count += ft_print_str(va_arg(ap,char *));
	else if(sep == 'd')
		count += ft_print_digit(va_arg(ap,int), 10);
	else if(sep == 'x')
		count += ft_print_digit(va_arg(ap,int),16);
	else
		write(1,&sep,1);

}

int	ft_printf(const char *s, ...)
{
	va_list arg;
	int c;
	va_start(arg,s);
	while(*s)
	{
		if(*s == '%')
			c += print_format(*(++s) , arg);
		else
			c += write(1,s,1);
		s++;
	}
	va_end(arg);
	return c;
}

int	main(void)
{
	ft_printf("%x",0x00);
}
