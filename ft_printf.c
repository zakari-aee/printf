/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:49:01 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/06 09:46:03 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formate(const char *s, va_list ap)
{
	if (*s == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (*s == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (*s == 'd' || *s == 'i')
		return (ft_print_nbr(va_arg(ap, int)));
	else if (*s == 'u')
		return (ft_print_unbr(va_arg(ap, unsigned int)));
	else if (*s == 'x')
		return (ft_print_hex(va_arg(ap, unsigned long), "0123456789abcdef"));
	else if (*s == 'X')
		return (ft_print_hex(va_arg(ap, unsigned long), "0123456789ABCDEF"));
	else if (*s == 'p')
		return (ft_print_point(va_arg(ap, void *)));
	else if (*s == '%')
		return (ft_print_char('%'));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	int count;
	count = 0;
	int i;
	int ret;
	i = 0;
	va_list ap;
	va_start(ap, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
			ret += formate(&(s[++i]), ap);
		else
			ret += ft_print_char(s[i]);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	va_end(ap);
	return (count);
}