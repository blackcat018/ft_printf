#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	 int j = printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n--------------------------------------------------\n");
	int i = ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n(ft_printf) : %d, \n (printf) : %d",i,j);
}