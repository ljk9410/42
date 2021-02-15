# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:53:27 by jung-lee          #+#    #+#              #
#    Updated: 2021/02/15 11:53:27 by jung-lee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= ./ft_printf.c
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