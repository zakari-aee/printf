/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:04:40 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/05 12:23:59 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + ft_strlen(s + 1));
}

int	ft_print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
}

int	ft_print_str(char *str)
{
	int	c;

	if (!str)
		str = "(null)";
	c = ft_strlen(str);
	if (write(1, str, c) == -1)
		return (-1);
	return (c);
}

int	ft_print_nbr(int n)
{
	int		count;
	int		ret;
	long	nb;
	char	c;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb > 9)
	{
		ret = ft_print_nbr(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = (nb % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_print_hex(unsigned int i, char *s)
{
	int		count;

	count = 0;
	if(i >= 16)
	{
		count = ft_print_hex(i / 16 ,s);
		if(count < 0)
			return -1 ;
	}
	if( write(1,&(s[i % 16]),1) == -1)
		return -1;
	return (count + 1);
}

int	formate(char *s, va_list ap)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (*s == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (*s == 'd')
		count += ft_print_nbr(va_arg(ap, int));
	else if (*s == 'x')
		count += ft_print_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*s == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*s == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_prr(char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	va_start(ap, s);
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
			count += formate(&(s[++i]), ap);
		else if (count < 0)
			return (count);
		else
			count += ft_print_char(s[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int r1;
	int r2;

	// close(1);
	// setvbuf(stdout, NULL, _IONBF, 0);

	r1 = ft_prr("hello %X\n", 42);
	r2 = printf("hello %X\n", 42);
	fprintf(stderr, "ft_printf: %d\nprintf:    %d\n", r1, r2);
	return (0);
}