# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lajudy <lajudy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 17:15:03 by lajudy            #+#    #+#              #
#    Updated: 2021/11/05 20:55:24 by lajudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	error_handling.c ft_atoi.c libft.c\
		stack_actions.c stack_actions2.c stack_sort.c\
		stack_sort_utils.c\
		stack_utils.c stack_utils2.c\
		transfer_to_a.c transfer_to_a2.c\
		ft_split.c
MAIN =	main.c

BSRCS = checker.c checker_utils.c libft_checker.c\
		stack_actions3.c

HDRS =	push_swap.h

MOBJS = $(MAIN:.c=.o)
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

$(NAME):$(OBJS) $(MOBJS)
	$(CC) $(CFLAGS) $(MOBJS) $(OBJS) -o $(NAME)

bonus: $(BNAME)

$(BNAME):$(OBJS) $(BOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BOBJS) -o $(BNAME)

clean:
	${RM} ${OBJS}
	${RM} ${MOBJS}
	${RM} ${BOBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BNAME}

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS} ${BSRCS}
	norminette -R CheckDefine ${HDRS}

.PHONY: all clean fclean re bonus norm