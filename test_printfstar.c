#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("'%0*.*i'\n", 6, 3, 8);
	printf("'%0*.*i'\n", 6, -2, 8);
	printf("'%0*.*i'\n", 5, -2, 8);
	printf("'%0*.*i'\n", 4, -2, 8);
	printf("'%0*.*i'\n", 2, -2, 8);
	ft_printf("'%0*.*i'\n", 2, -2, 8);
	printf("'%*.*i'\n", -2, -2, 8);
	ft_printf("'%*.*i'\n", -2, -2, 8);
	printf("\n");
	printf("%05.2d\n", 8);
	printf("%05.d\n", 8);
	printf("%05d\n", 8);
	printf("|%*.0u|\n", -45, 0);
	ft_printf("|%*.0u|\n", -45, 0);
	printf("%.*u\n", -1, 0);
	ft_printf("%.*u\n", -1, 0);
}
