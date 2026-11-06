/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:18:07 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/06 09:57:38 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_point(void *ptr)
{
	int	ret;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	ret = ft_print_hex((unsigned long)ptr, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (ret + 2);
}