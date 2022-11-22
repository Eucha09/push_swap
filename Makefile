CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT_DIR = Libft
LIBFT = libft.a
INCLUDES = includes
SOURCES =	srcs/stack/ft_stack_clear.c\
			srcs/stack/ft_stack_new.c\
			srcs/stack/ft_stack_pop.c\
			srcs/stack/ft_stack_push.c\
			srcs/stack/ft_stack_top.c\
			srcs/stack/ft_stack_bottom.c\
			srcs/stack/ft_stack_resize.c\
			srcs/stack/ft_stack_size.c\
			srcs/push_swap_oper/push_oper.c\
			srcs/push_swap_oper/reverse_rotate_oper.c\
			srcs/push_swap_oper/rotate_oper.c\
			srcs/push_swap_oper/swap_oper.c\
			srcs/push_swap_oper/new_oper.c\
			srcs/push_swap_oper/clear_oper.c\
			srcs/push_swap.c\
			srcs/sort.c\
			srcs/validator.c\
			srcs/main.c
OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@ -I $(INCLUDES)

%.o : %.c
	cc $(CFLAGS) -c $^ -o $@ -I $(INCLUDES)

clean :
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re