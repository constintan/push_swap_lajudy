/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:34:07 by lajudy            #+#    #+#             */
/*   Updated: 2021/11/05 20:45:18 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_finally_sorted(t_stack_elem *head)
{
	t_stack_elem	*p;
	int				flag;

	flag = 0;
	p = head;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (1);
		head = head->next;
	}
	return (0);
}

static int	do_action(t_stack_elem **head_a, t_stack_elem **head_b,
	char *action)
{
	if (ft_strcmp(action, "sa") == 0)
		act_sa(head_a, 0);
	else if (ft_strcmp(action, "sb") == 0)
		act_sb(head_b, 0);
	else if (ft_strcmp(action, "ss") == 0)
		act_ss(head_a, head_b, 0);
	else if (ft_strcmp(action, "pa") == 0)
		act_pa(head_a, head_b, 0);
	else if (ft_strcmp(action, "pb") == 0)
		act_pb(head_a, head_b, 0);
	else if (ft_strcmp(action, "ra") == 0)
		act_ra(head_a, 0);
	else if (ft_strcmp(action, "rb") == 0)
		act_rb(head_b, 0);
	else if (ft_strcmp(action, "rr") == 0)
		act_rr(head_a, head_b, 0);
	else if (ft_strcmp(action, "rra") == 0)
		act_rra(head_a, 0);
	else if (ft_strcmp(action, "rrb") == 0)
		act_rrb(head_b, 0);
	else if (ft_strcmp(action, "rrr") == 0)
		act_rrr(head_a, head_b, 0);
	else
		return (1);
	return (0);
}

static int	read_stdin(char (*buf)[5])
{
	int		size;
	char	symbol[2];

	*buf[0] = '\0';
	size = read(0, symbol, 1);
	symbol[1] = '\0';
	while (symbol[0] != '\n' && ft_strlen(*buf) < 5 && size != 0)
	{
		ft_strlcat(*buf, symbol, 5);
		size = read(0, symbol, 1);
	}
	return (size);
}

void	read_instructions(t_stack_elem **head_a)
{
	t_stack_elem	*head_b;
	char			buf[5];
	int				size;

	head_b = NULL;
	size = read_stdin(&buf);
	while (size != 0)
	{
		if (do_action(head_a, &head_b, buf) != 0)
		{
			free_stack(&head_b);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		size = read_stdin(&buf);
	}
	if (is_not_finally_sorted(*head_a) || stack_size(head_b) > 0)
	{
		ft_putstr_fd("KO\n", 1);
		free_stack(&head_b);
	}
	else
		ft_putstr_fd("OK\n", 1);
}
