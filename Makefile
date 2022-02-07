# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 17:15:03 by lajudy            #+#    #+#              #
#    Updated: 2022/02/07 08:47:28 by lajudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	error_handling.c ft_atoi.c libft.c\
		stack_actions.c stack_actions2.c stack_sort.c\
		stack_sort_utils.c\
		stack_utils.c stack_utils2.c\
		transfer_to_a.c transfer_to_a2.c\
		ft_split.c main.c

BSRCS = ft_split.c libft.c stack_utils.c\
		stack_utils2.c ft_atoi.c error_handling.c\
		stack_actions.c stack_actions2.c\
		checker.c checker_utils.c libft_checker.c\
		stack_actions3.c

HDRS =	push_swap.h

OBJS = 	$(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

NAME = 	push_swap
BNAME = checker

CC = 	gcc
CFLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all:	$(NAME)

$(MOBJS):$(HDRS) Makefile
$(OBJS):$(HDRS) Makefile
$(BOBJS):$(HDRS) Makefile

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
	${RM} ${OBJS}
	${RM} ${BOBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BNAME}

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS} ${BSRCS}
	norminette -R CheckDefine ${HDRS}

.PHONY: all clean fclean re bonus norm