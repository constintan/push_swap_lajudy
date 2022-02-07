/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_a2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:10:53 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 08:47:42 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_score_elem2(int result, t_stack_elem *head, int *ttype)
{
	if (head->b_score + head->a_rscore < result)
	{
		result = head->b_score + head->a_rscore;
		*ttype = 5;
	}
	if (head->b_rscore + head->a_score < result)
	{
		result = head->b_rscore + head->a_score;
		*ttype = 6;
	}
	return (result);
}

int	total_score_elem(t_stack_elem *head, int *ttype)
{
	int	result;
	int	biggest_rscore;

	result = head->b_score;
	*ttype = 1;
	if (head->a_score >= head->b_score)
	{
		result = head->a_score;
		*ttype = 2;
	}
	biggest_rscore = head->a_rscore;
	if (head->b_rscore > biggest_rscore)
		biggest_rscore = head->b_rscore;
	if (result > biggest_rscore)
	{
		result = biggest_rscore;
		if (head->b_rscore > head->a_rscore)
			*ttype = 3;
		else
			*ttype = 4;
	}
	result = total_score_elem2(result, head, ttype);
	return (result);
}

t_stack_elem	*make_decision(t_stack_elem *head, int *transfer_type)
{
	t_stack_elem	*save_point;
	int				best_total_score;
	int				best_rank;
	int				best_transfer_type;

	best_total_score = total_score_elem(head, transfer_type);
	best_rank = head->rank;
	best_transfer_type = *transfer_type;
	save_point = head;
	while (head)
	{
		if (total_score_elem(head, transfer_type) < best_total_score
			|| (total_score_elem(head, transfer_type) == best_total_score
				&& head->rank >= best_rank))
		{
			best_total_score = total_score_elem(head, transfer_type);
			best_rank = head->rank;
			best_transfer_type = *transfer_type;
		}
		head = head->next;
	}
	*transfer_type = best_transfer_type;
	while (save_point->rank != best_rank)
		save_point = save_point->next;
	return (save_point);
}

/*
ttype = 1, b_score больше. rb + rr
ttype = 2, a_score больше или равно. rr + ra
ttype = 3 b_rscore больше a_rscore. rrb + rrr
ttype = 4 a_rscore больше или равно b_rscore. rrr + rra
ttype = 5, rb + rra
ttype = 6, rrb + ra
*/

void	process_decision2(t_stack_elem **head_a, t_stack_elem **head_b,
	t_stack_elem *elem, int *ttype)
{
	if (*ttype == 4)
	{
		while (elem->b_rscore-- > 0 && elem->a_rscore--)
			act_rrr(head_a, head_b, 1);
		while (elem->a_rscore-- > 0)
			act_rra(head_a, 1);
	}
	if (*ttype == 5)
	{
		while (elem->b_score-- > 0)
			act_rb(head_b, 1);
		while (elem->a_rscore-- > 0)
			act_rra(head_a, 1);
	}
	if (*ttype == 6)
	{
		while (elem->b_rscore-- > 0)
			act_rrb(head_b, 1);
		while (elem->a_score-- > 0)
			act_ra(head_a, 1);
	}
}

/*
ttype = 1, b_score больше. rb + rr
ttype = 2, a_score больше или равно . rr + ra
ttype = 3 b_rscore больше a_rscore. rrb + rrr
ttype = 4 a_rscore больше или равно b_rscore. rrr + rra
ttype = 5, rb + rra
ttype = 6, rrb + ra
*/
void	process_decision(t_stack_elem **head_a, t_stack_elem **head_b,
	t_stack_elem *elem, int *ttype)
{
	if (*ttype == 1)
	{
		while (elem->a_score-- > 0 && elem->b_score--)
			act_rr(head_a, head_b, 1);
		while (elem->b_score-- > 0)
			act_rb(head_b, 1);
	}
	if (*ttype == 2)
	{
		while (elem->b_score-- > 0 && elem->a_score--)
			act_rr(head_a, head_b, 1);
		while (elem->a_score-- > 0)
			act_ra(head_a, 1);
	}
	if (*ttype == 3)
	{
		while (elem->a_rscore-- > 0 && elem->b_rscore--)
			act_rrr(head_a, head_b, 1);
		while (elem->b_rscore-- > 0)
			act_rrb(head_b, 1);
	}
	if (*ttype > 3)
		process_decision2(head_a, head_b, elem, ttype);
	act_pa(head_a, head_b, 1);
}
