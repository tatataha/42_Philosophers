# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 05:53:05 by muhcelik          #+#    #+#              #
#    Updated: 2023/10/24 15:03:45 by muhcelik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philosophers.c threads.c initialize.c philo_funcs.c\
	checks_philo.c utils_for_philo.c utils.c error.c

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@$(CC) ${OBJS} $(FLAGS) -o $(NAME)

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re