/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:14:00 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/06 09:52:50 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long i, char *s)
{
	int count;
	int ret;
	count = 0;

	if (i > 16)
	{
		ret = ft_print_hex(i / 16, s);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (write(1, &s[i % 16], 1) == -1)
		return (-1);
	return (count + 1);
}