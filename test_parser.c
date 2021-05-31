#include "libft.h"
#include "parser.h"
#include <stdio.h>

void print_match(void *mp)
{
	char *str_zero, *str_minus;
	t_match *m = (t_match *)mp;
	t_options opts = m->opts;
	if (opts.flags & FLAG_ZERO)
		str_zero = "ZERO";
	else
		str_zero = "";
	if (opts.flags & FLAG_MINUS)
		str_minus = "MINUS";
	else
		str_minus = "";

	printf("i_start=%ld ; len=%d ; conv=%c ; opts:%s|%s,flen=%d",
			m->i_start, m->len, m->conv_char_id,
			str_zero, str_minus, opts.field_len);
	if (opts.field_len == -1)
		printf(",flen_arg=%d", opts.field_len_arg);
	printf(",prec=%d", opts.precision);
	if (opts.precision == -1)
		printf(",prec_arg=%d", opts.precision_arg);
	printf(",modif=%d)\n", opts.modif);
}

int main()
{
	t_list	*matches;
	char	*formats[50] = {
		"%i",
		"%d",
		"%%",
		"%12d",
		"%.12d",
		"%12.12d",
		"%0d",
		"%-0d",
		"%012d",
		"%012.12d",
		"%hhd",
		"%hd",
		"%ld",
		"%lld",
		"Un chien savant sachant %-d doit savoir %0d sans son nez",
		"N1 equals %d",
		"Let me try unimplemented convs : %k %z",
		"%*d",
		"%.*d",
		"%*25$d",
		"%.*25$d",
		"%.*25d",
		NULL};

	int i = 0;
	while (formats[i])
	{
		ft_putstr_fd("Format string :\n", 1);
		ft_putstr_fd(formats[i], 1);
		ft_putchar_fd('\n', 1);
		matches = parser_all(formats[i]);
		ft_lstiter(matches, &print_match);
		ft_lstclear(&matches, &free);	
		ft_putchar_fd('\n', 1);
		i++;
	}
}
