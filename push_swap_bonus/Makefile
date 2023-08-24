SRCS = checker.c			\
		get_next_line.c		\
		get_next_line_utils.c\
		rotate.c			\
		push.c				\
		reverse_rotate.c	\
		swap.c				\
		checker_utils1.c	\
		checker_utils2.c	\

NAME = libft.a

%.o : %.c push_swap.h
	@cc -Wall -Werror -Wextra -c $< -o $@

$(NAME) : $(SRCS:.c=.o)
	@make -C libft
	@make bonus -C libft 
	@cp libft/libft.a .
	@ar -r $(NAME) $(SRCS:.c=.o)
	@cc checker.c libft.a -o checker
	@mv checker ..
	@echo "Libft created !"

all : $(NAME)

clean :
	@rm -rf $(SRCS:.c=.o) $(SRCSB:.c=.o)
	@make clean -C libft
	@echo "objs erased !"

fclean : clean
	@rm -rf $(NAME)
	@rm -rf ../checker
	@make fclean -C libft
	@echo "libft.a erased !"

re : fclean all