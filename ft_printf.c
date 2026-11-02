/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:49:01 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/02 10:04:24 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list arg;
	while(*s)
	{
		if(*s == '%' && *(s+1) == 'c')
		{
			s++;
			ft_putendl_fd("hada caracter",1);
		}
			
		else
			write(1,&(*s),1);
		s++;
	}
	va_end(arg);
}

int	main(void)
{
	ft_printf("%cdd");
}
