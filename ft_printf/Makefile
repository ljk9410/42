# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:53:27 by jung-lee          #+#    #+#              #
#    Updated: 2021/03/04 16:46:53 by hmyoung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./ft_printf.c \
		  ./check_conversion.c \
		  ./check_options.c \
		  ./ft_printf_utils.c \
		  ./handle_base.c \
		  ./init_struct.c \
		  ./print_conversion_c.c \
		  ./print_conversion_diuxX.c \
		  ./print_conversion_p.c \
		  ./print_conversion_percent.c \
		  ./print_conversion_s.c \
		  ./print_conversion_utils.c \
		  ./print_num_utils.c \

NAME 	= libftprintf.a
OBJS	= $(SRCS:.c=.o)
CC 	 	= gcc
CFLAGS 	= -Wall -Wextra -Werror
RM		= rm -f

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)
	

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all


