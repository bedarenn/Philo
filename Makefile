# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 23:28:11 by bedarenn          #+#    #+#              #
#    Updated: 2024/07/05 13:26:23 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCL = hdrs/
DIR_LIBS = libs/

SRCS = \
	w_tools.c \
	w_arg.c \
	w_thrd.c \
	thrd_lauch.c \
	m_philo.c \
	m_philo_print.c \
	m_philo_action.c \
	undertaker.c \
	main.c

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))

CFLAGS = -Wall -Wextra -Werror #-g #-fsanitize=thread
IFLAGS = -I$(DIR_INCL)
LFLAGS = -L$(DIR_LIBS) -lpthread

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	@mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $^ -o $@

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re