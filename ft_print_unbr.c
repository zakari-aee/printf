/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:07:52 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/06 09:59:52 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int nbr)
{
	int		count;
	char	c;
	int		ret;

	count = 0;
	if (nbr > 9)
	{
		ret = ft_print_unbr(nbr / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}