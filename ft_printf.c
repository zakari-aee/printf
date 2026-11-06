/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:14:41 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/06 22:16:27 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formate(char c, va_list *ap)
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

static int	is_spec(char c)
{
	int	i;

	i = 0;
	while ("cspdiuxX%"[i])
	{
		if ("cspdiuxX%"[i++] == c)
			return (1);
	}
	return (0);
}

static int	parse(const char *s, int *i, va_list *ap)
{
	int	start;

	start = *i;
	while (s[*i + 1] == ' ')
		(*i)++;
	if (!s[*i + 1])
		return (-1);
	(*i)++;
	if (!is_spec(s[*i]))
		return (write(1, s + start, *i - start + 1));
	return (formate(s[*i], ap));
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
	ret = 0;
	count = 0;
	i = -1;
	while (s[++i] && ret != -1)
	{
		if (s[i] == '%')
			ret = parse(s, &i, &ap);
		else
			ret = ft_print_char(s[i]);
		if (ret != -1)
			count += ret;
	}
	va_end(ap);
	if (ret == -1)
		return (-1);
	return (count);
}