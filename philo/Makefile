# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 23:28:11 by bedarenn          #+#    #+#              #
#    Updated: 2024/07/18 17:26:16 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCL = hdrs/
DIR_LIBS = libs/

SRCS = \
	w_tools.c \
	mutex_utils.c \
	w_arg.c \
	thrd_create.c \
	thrd_laucher.c \
	thrd_join.c \
	undertaker.c \
	m_philo.c \
	m_philo_action.c \
	thrd_delete.c \
	main.c

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))

CFLAGS = -Wall -Wextra #-Werror
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