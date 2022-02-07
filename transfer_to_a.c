/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 02:40:01 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 08:47:41 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* For each number we need not only forward rotation but also backward.
 * May be it is cheaper for some numbers to rotate reversed way. */
void	scoring_in_b(t_stack_elem *head_b)
{
	int	size;
	int	i;

	size = stack_size(head_b);
	i = 0;
	while (head_b)
	{
		head_b->b_score = i;
		head_b->b_rscore = size - i;
		i++;
		head_b = head_b->next;
	}
}

/* Scoring for "how much will it cost to put a specific number into the right place to keep the pre-sort in stack A.
 * Scoring for rotate and r-rotate*/
void	scoring_in_a(t_stack_elem *head_a, t_stack_elem *head_b)
{
	t_stack_elem	*save_point;
	int				size;
	int				i;
	int				prev;

	size = stack_size(head_a);
	save_point = head_a;
	while (head_b)
	{
		head_a = save_point;
		i = 0;
		prev = last_stack_elem(head_a)->value;
		while (head_a)
		{
			if (prev < head_b->value && head_a->value > head_b->value)
			{
				head_b->a_score = i;
				head_b->a_rscore = size - i;
			}
			i++;
			prev = head_a->value;
			head_a = head_a->next;
		}
		head_b = head_b->next;
	}
}

/*big task for the function: to find best number from stack B to transfer it back.
 * best number in terms of how many operations need to be done to put in into the stack
 * to keep stack A right way pre-sorted all the time
 * 1. Making scores for each number to rotate and r-rotate (reverse) into stack B
 * 2. For each number in B scoring rotation and r-rotation in stack A (to put it into the right place
 * 3. Comparing the result, making decision = choosing the best-score-number
 * 4. Processing a decision: making and printing swapping-rotating and all of then*/
void	transfer_to_a(t_stack_elem **head_a, t_stack_elem **head_b)
{
	t_stack_elem	*best_rank_elem;
	int				transfer_type;

	scoring_in_b(*head_b);
	scoring_in_a(*head_a, *head_b);
	best_rank_elem = make_decision(*head_b, &transfer_type);
	process_decision(head_a, head_b, best_rank_elem, &transfer_type);
}
