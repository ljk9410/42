SRCS_PS =	./srcs/push_swap.c \
			./srcs/call_function.c \
			./srcs/find_pivot.c \
			./srcs/p_function.c \
			./srcs/r_function.c \
			./srcs/s_function.c \
			./srcs/rr_function.c \
			./srcs/error_check_before.c \
			./srcs/error_check_after.c \
			./srcs/ft_atoi.c \
			./srcs/quick_sort.c \
			./srcs/lst_function.c \

NAME_PS = push_swap
OBJS_PS = $(SRCS_PS:.c=.o)
INCS = .
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

all : $(NAME_PS)

$(NAME_PS) : $(OBJS_PS)
		$(CC) $(CFLAGS) -o $(NAME_PS) $(OBJS_PS) -I $(INCS)

clean :
		$(RM) $(OBJS_PS)

fclean : clean
		$(RM) $(NAME_PS)

re : fclean all
