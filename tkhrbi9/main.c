/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:47:26 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/07 18:35:28 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int test(int c,...)
{
	int i = 1;
	va_list ap;
	// printf("Befor the va_start : reg_save_area = %p\n",ap[0].reg_save_area);
	// printf("Befor the va_start : overflow_arg_area = %p\n",(ap->overflow_arg_area));
	// printf("Befor the va_start : gp_offset = %d\n",(ap->gp_offset));
	// printf("Befor the va_start : fp_offset = %d\n",(ap->fp_offset));

	va_start(ap,c);

	// printf("-----------------------------------------------------------------------------------\n");
	// printf("Befor the va_start : reg_save_area = %p\n",ap[0].reg_save_area);
	// printf("Befor the va_start : overflow_arg_area = %p\n",(ap->overflow_arg_area));
	// printf("Befor the va_start : gp_offset = %d\n",(ap->gp_offset));
	// printf("Befor the va_start : fp_offset = %d\n",(ap->fp_offset));

	printf("calc : %ld\n",((int *)(ap->reg_save_area ) - &c));	
	printf("After the va_start : overflow_arg_area = %d\n", *((int *)ap->reg_save_area - 13));
	// printf("After the va_start : overflow_arg_area = %u\n", *(int *)((char *)ap[0].overflow_arg_area));
	// printf("After the va_start : gp_offset = %d\n",(ap->gp_offset));
	// printf("After the va_start : fp_offset = %d\n",(ap->fp_offset));;
	printf("-----------------------------------------------------------------------------------\n");
	

	// while(i <= c)
	// {
	// 	printf(" %d\n  -------------------------------------------------------------------------------\n",i);
	// 	va_arg(ap,int);
	// 	printf("After the va_arg : reg_save_area = %p\n",(ap->reg_save_area));
	// 	printf("After the va_arg : overflow_arg_area = %p\n",(ap->overflow_arg_area));
	// 	printf("After the va_arg : gp_offset = %d\n",(ap->gp_offset));
	// 	printf("After the va_arg : fp_offset = %d\n",(ap->fp_offset));
	// 	printf(" %d\n  -------------------------------------------------------------------------------\n",i);

	// 	i++;
		
	// }
	va_end(ap);
}

int main()
{
	test(133700,1,2,3,4,5,6,7,8,9,100);
}