/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:35:54 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 08:47:30 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_elem
{
	struct s_stack_elem	*next;
	int					value;
	int					a_score;
	int					a_rscore;
	int					b_score;
	int					b_rscore;
	int					rank;
}	t_stack_elem;

//error_handling.c
int				not_valid_arguments(int argc, char **argv);

//libft.c
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
void			free_after_split(char **argv);

//stack_utils.c
t_stack_elem	*stack_init(int argc, char **argv);
int				stack_size(t_stack_elem *stack);

//stack_utils2.c
void			stack_add_front(t_stack_elem **stack, t_stack_elem *new);
void			stack_add_back(t_stack_elem **stack, t_stack_elem *new);
t_stack_elem	*last_stack_elem(t_stack_elem *stack);
t_stack_elem	*before_last_stack_elem(t_stack_elem *stack);
void			free_stack(t_stack_elem **head);

//ft_atoi.c
long long int	ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);

//stack_sort.c
t_stack_elem	*stack_sort(t_stack_elem **head);

//stack_actions.c
void			act_sa(t_stack_elem **head, int output);
void			act_pb(t_stack_elem **head, t_stack_elem **head_b, int output);
void			act_pa(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);
void			act_ra(t_stack_elem **head, int output);
void			act_rb(t_stack_elem **head, int output);

//stack_actions2.c
void			act_rr(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);
void			act_rra(t_stack_elem **head, int output);
void			act_rrb(t_stack_elem **head, int output);
void			act_rrr(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);

//stack_actions3.c
void			act_sb(t_stack_elem **head, int output);
void			act_ss(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);

// stack_sort_utils.c
int				is_not_presorted(t_stack_elem *head);
void			final_sort_stack(t_stack_elem **head);
int				find_minmaxmed(t_stack_elem **head,
					int *min, int *max, int *med);
int				*sort_array(int *array, int size, t_stack_elem *head);
void			start_rotating(t_stack_elem **head, int index);

//transfer_to_a.c
void			transfer_to_a(t_stack_elem **head_a, t_stack_elem **head_b);

//transfer_to_a2.c
int				total_score_elem2(int result, t_stack_elem *head, int *ttype);
int				total_score_elem(t_stack_elem *head, int *ttype);
t_stack_elem	*make_decision(t_stack_elem *head, int *transfer_type);
void			process_decision2(t_stack_elem **head_a, t_stack_elem **head_b,
					t_stack_elem *elem, int *ttype);
void			process_decision(t_stack_elem **head_a, t_stack_elem **head_b,
					t_stack_elem *elem, int *ttype);

//ft_split.c
char			**ft_split(char const *s, char c);
int				splited_size(char **words);

//checker_utils.c
void			read_instructions(t_stack_elem **head_a);

//libft_checker.c
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
