#include "ft_printf.h"

static int	formate(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_print_unbr(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_print_point(va_arg(*ap, void *)));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	is_flag(char c)
{
	return (c == ' ' || c == '\'');
}

static int	parse(const char *s, int *i, va_list *ap)
{
	while (is_flag(s[*i + 1]))
		(*i)++;
	if (!s[*i + 1])
		return (-1);
	(*i)++;
	return (formate(s[*i], ap));
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		ret;
	int		i;

	if (!s)
		return (-1);
	va_start(ap, s);
	ret = 0;
	count = 0;
	i = -1;
	while (s[++i] && ret != -1)
	{
		if (s[i] == '%')
			ret = parse(s, &i, &ap);
		else
			ret = ft_print_char(s[i]);
		if (ret != -1)
			count += ret;
	}
	va_end(ap);
	if (ret == -1)
		return (-1);
	return (count);
}