#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	*ptr = (void*)-42;
	
	ft_printf("[%25p]\n", ptr);
	printf("[%25p]\n", ptr);
}
