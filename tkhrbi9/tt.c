#include <stdarg.h>
#include <stdio.h>

int	test(int c, ...)
{
	va_list	ap;
	long	off;

	va_start(ap, c);
	off = (int *)ap->reg_save_area - &c;
	printf("offset in ints : %ld\n", off);
	printf("value          : %d\n", *((int *)ap->reg_save_area - off));
	va_end(ap);
	return (0);
}

int	main(void)
{
	test(133700, 1, 2, 3, 4, 5, 6, 7, 8, 9, 100);
	return (0);
}