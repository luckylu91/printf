#include <stdio.h>
#include <stdlib.h>

void	test_conv(int n, int min_size, char *(*f_conv)(int, int))
{
	char	*n_str;

	if ((n_str = (*f_conv)(n, min_size)) == NULL)
	{
		
	}
	free(n_str)
	
}

int		main()
{
}
