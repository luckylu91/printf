#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf(" | return=%d\n", printf("%.*d", -10, 0));
	printf(" | return=%d\n", ft_printf("%.*d", -10, 0));
	printf(" | return=%d\n", printf("%*.*d", 0, -5, 0));
	printf(" | return=%d\n", ft_printf("%*.*d", 0, -5, 0));
}
