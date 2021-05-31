CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
NAME =			libftprintf.a
LIBFT =			libft/libft.a
LIBFTFLAGS =	-Llibft -lft
LPRINTFFLAGS =	-L. -lftprintf
IFLAGS =		-Ilibft
SRCS =			parser.c parser_opts1.c parser_opts2.c int_conv.c int_conv_utils.c char_conv.c ft_printf.c utils.c conv_utils.c
OBJS =			$(SRCS:.c=.o)
RM =			rm -f

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	ar q $@ $(OBJS)

%.o: %.c ft_printf.h libft.h
	$(CC) -c $(CFLAGS) $(IFLAGS) $<

test_%: test_%.o $(NAME)
	$(CC) $(CFLAGS) $(IFLAGS) $(LIBFTFLAGS) $(LPRINTFFLAGS) -o $@ $< && ./$@

$(LIBFT):
	@make -C libft bonus

clean:
	@make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
