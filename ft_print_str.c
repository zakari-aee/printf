/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:28:14 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/05 13:34:19 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int i;
	int c;

	i = 0;
	c = ft_strlen(str);
	while (str[i])
	{
		if (write(1, &(str[i]), 1) == -1)
			return (-1);
		i++;
	}
	return (c);
}