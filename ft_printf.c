/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:49:01 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/06 22:40:33 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formate(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_print_unbr(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_print_point(va_arg(*ap, void *)));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		ret;
	int		i;

	if (!s)
		return (-1);
	va_start(ap, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			ret = formate(s[++i], &ap);
		else
			ret = ft_print_char(s[i]);
		if (ret == -1)
			return (va_end(ap), -1);
		count += ret;
		i++;
	}
	va_end(ap);
	return (count);
}