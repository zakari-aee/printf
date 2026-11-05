/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:34:56 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/05 13:43:39 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_nbr(int n)
{
	long	cast_nbr;
	int		count;
	int		ret;
	char	c;

	cast_nbr = n;
	count = 0;
	if (cast_nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count += 1;
		cast_nbr *= -1;
	}
	if (cast_nbr >= 10)
	{
		ret = ft_print_nbr(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}

int	main(void)
{
	ft_print_nbr(123);
}