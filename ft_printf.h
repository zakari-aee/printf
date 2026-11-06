/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:46:23 by zallioua          #+#    #+#             */
/*   Updated: 2026/11/06 10:00:23 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_print_char(char c);
int	ft_strlen(char *s);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_unbr(unsigned int nbr);
int	ft_print_hex(unsigned long i, char *s);
int	ft_print_point(void *ptr);

#endif