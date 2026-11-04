/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:04:40 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/04 12:26:13 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int ft_strlen(char *s)
{
	if(*s == '\0')
		return 0;
	return (1 + ft_strlen(s+1));
}

int ft_print_chr(int c)
{
	return (write(1,&c,1));
}

int ft_print_str(char *str)
{
	int c;
	if (!str)
        str = "(null)";

	c = ft_strlen(str);
	write(1,str,c);
	return c;

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

int	ft_prr(char *s, ...) // ... elepses
{
	va_list ap;
	va_start(ap,s);
	int count;
	count = 0;
	while (*s)
    {
        if (*s == '%')
        {
            s++;
            if (*s == 'c')
                count += ft_print_chr(va_arg(ap, int));
            else if (*s == 's')
                count += ft_print_str(va_arg(ap, char *));
            else if (*s == 'd')
                count += ft_print_nbr(va_arg(ap, int));
        }
        else
            count += ft_print_chr(*s);
        s++; 
    }
	va_end(ap);
	return count;
}

int	main(void)
{
	ft_prr("%s slm %c sajbi zakariae db an7awlo n9ado ft_printf %d\n", NULL , 'A' , -12345);
	// printf("%s slm %c sajbi zakariae db an7awlo n9ado ft_printf", NULL , 'A');
	return (0);
	
}
