#include <stdarg.h>
#include <stdio.h>

typedef union u_types
{
	char c;
	int i;
	long l;
	char *s;
} t_types;
/*
void	defaults(char *types_str, ...)
{
	va_list	va;
	char	*res;

	va_start(va, types_str);
	while (*types_str)
	{
		switch (*types_str++)
		{
			case 'c':
				printf("%c", va_arg(va, int)); //promoted
				break;
			case 'i':
				printf("%i", va_arg(va, int));
				break;
			case 'l':
				printf("%li", va_arg(va, long));
				break;
			case 's':
				printf("%s", va_arg(va, char*));
				break;
			default:
				printf("?");
				break;
		}
		if (*types_str)
			printf("|");
	}
	printf("\n");
	va_end(va);
}
*/
static char *g_supported_types = "cils";
typedef void (*print_fun)(t_types);

void print_c(t_types val)
{
	printf("%c\n", val.c);
}
void print_i(t_types val)
{
	printf("%i\n", val.i);
}
void print_l(t_types val)
{
	printf("%li\n", val.l);
}
void print_s(t_types val)
{
	printf("%s\n", val.s);
}

static	print_fun print_funs[4] = {&print_c, &print_i, &print_l, &print_s};

int		pos(char c, char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		print_val(char ctype, t_types val)
{
	int i = pos(ctype, "cils");

	if (i == -1)
		return -1;
	print_funs[i](val);
	return (0);
}



void	defaults(char *types_str, ...)
{
	va_list	va;
	char	*res;

	va_start(va, types_str);
	while (*types_str)
	{
		if (print_val(*types_str, va_arg(va, t_types)) == -1)
			printf("Unknown conversion character : %c\n", *types_str);
		types_str++;
	}
	printf("\n");
	va_end(va);
}
int main()
{
	defaults("cciillss", 'a', 'z', 0, 1000000000, 0L, 1000000000000L, "caca", "boudin");
	return (0);
}
