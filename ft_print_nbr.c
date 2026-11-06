/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:34:56 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/06 09:58:23 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;
	int		ret;
	char	c;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		ret = ft_print_nbr(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = nb % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}