/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:40:33 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/02 09:57:09 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>


int ft_sum(int count,...)
{
	va_list arg;
	int t = 0;
	va_start(arg,count);
	while( count  > 0)
	{
		t += va_arg(arg,int);
		count--;
	}
	va_end(arg);
	return t;
}

int	main(void)
{
	printf("%d",ft_sum(1,1,2,3,4));
}
