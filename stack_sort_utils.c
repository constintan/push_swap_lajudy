/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 01:38:00 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 08:47:36 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_array(int *array, int size, t_stack_elem *head)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < size)
	{
		array[i] = head->value;
		head = head->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
			}
		}
	}
	return (array);
}

void	insert_ranks(t_stack_elem *head, int *array)
{
	int	i;

	while (head)
	{
		i = 0;
		while (array[i] != head->value)
			i++;
		head->rank = i;
		head = head->next;
	}
}

int	find_minmaxmed(t_stack_elem **head, int *min, int *max, int *med)
{
	int	size;
	int	*array;

	size = stack_size(*head);
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		return (1);
	array = sort_array(array, size, *head);
	*min = array[0];
	*max = array[size - 1];
	*med = array[size / 2];
	insert_ranks(*head, array);
	free(array);
	array = NULL;
	return (0);
}

int	is_not_presorted(t_stack_elem *head)
{
	t_stack_elem	*p;
	int				flag;

	flag = 0;
	p = head;
	while (head && head->next)
	{
		if (head->value > head->next->value && flag)
			return (1);
		if (head->value > head->next->value)
			flag = 1;
		head = head->next;
	}
	if (head && head->value > p->value && flag)
		return (1);
	return (0);
}

void	final_sort_stack(t_stack_elem **head)
{
	t_stack_elem	*p;
	int				min;
	int				max;
	int				steps;
	int				size;

	if (find_minmaxmed(head, &min, &max, &steps) > 0)
		return ;
	p = *head;
	steps = 0;
	while (p->value != min)
	{
		steps++;
		p = p->next;
	}
	size = stack_size(*head);
	if (steps <= size - steps)
		while (steps-- > 0)
			act_ra(head, 1);
	else
		while (steps++ < size)
			act_rra(head, 1);
}
