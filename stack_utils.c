/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:01:49 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 11:16:04 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_elem *stack)
{
	if (stack == NULL)
		return (0);
	else
		return (1 + stack_size(stack->next));
}

static t_stack_elem	*new_stack_elem(int value)
{
	t_stack_elem	*p;

	p = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (p == NULL)
		return (NULL);
	p->value = value;
	p->a_score = -1;
	p->b_score = -1;
	p->a_rscore = -1;
	p->b_rscore = -1;
	p->rank = -1;
	p->next = NULL;
	return (p);
}

// initialization of stack A and fill it up with numbers
t_stack_elem	*stack_init(int argc, char **argv)
{	
	int				i;
	t_stack_elem	*head;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		stack_add_back(&head, new_stack_elem(ft_atoi(argv[i])));
		i++;
	}
	return (head);
}
