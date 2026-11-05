/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:40:33 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/02 22:35:53 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_sum(int count, ...)
{
	va_list	arg;
	int		t;

	t = 0;
	va_start(arg, count);
	while (count > 0)
	{
		t += va_arg(arg, int);
		count--;
	}
	va_end(arg);
	return (t);
}
