/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:06:31 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 08:47:35 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort_triple(t_stack_elem **head)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = stack_size(*head);
	if (size == 3)
	{
		first = (*head)->value;
		second = (*head)->next->value;
		third = (*head)->next->next->value;
		if (second > third && second > first && third > first)
			act_sa(head, 1);
		if (third > first && third > second && first > second)
			act_sa(head, 1);
		if (first > third && first > second && second > third)
			act_sa(head, 1);
	}
}

/*filling stack B with numbers from A
 * in stack A stays only max, min and mediana
 * in the very end of the function it is pre-sorting these three numbers */
t_stack_elem	*fill_stack_b(t_stack_elem **head)
{
	t_stack_elem	*head_b;
	int				min;
	int				max;
	int				med;
	int				size;

	if (find_minmaxmed(head, &min, &max, &med) > 0)
		return (NULL);
	head_b = NULL;
	size = stack_size(*head);
	while (size > 3)
	{
		if ((*head)->value == min || (*head)->value == max
			|| (*head)->value == med)
			act_ra(head, 1);
		else
		{
			act_pb(head, &head_b, 1);
			size--;
		}
	}
	presort_triple(head);
	return (head_b);
}

/* Main function.
 * 1. checking is the stack pre-sorted or not
 * 1.1. pre-sorted means sorted as closed stack rotating in a circle. the uppest element could be not the least one.
 * 2. filling stack B with numbers from stack A
 * 3. transfering them back
 * 4. final sorting in ascending order*/

t_stack_elem	*stack_sort(t_stack_elem **head)
{
	t_stack_elem	*head_b;

	if (is_not_presorted(*head))
	{
		head_b = fill_stack_b(head);
		while (head_b)
			transfer_to_a(head, &head_b);
	}
	final_sort_stack(head);
	return (NULL);
}
