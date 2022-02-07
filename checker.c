/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:24:09 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 08:47:16 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_elem	*head_a;
	char			*str;

	if (argc == 2)
	{
		str = ft_strjoin("!checker ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
		argc = splited_size(argv);
	}
	if (not_valid_arguments(argc, argv) > 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (argv[0][0] == '!')
			free_after_split(argv);
		return (-1);
	}
	if (argc > 1)
	{
		head_a = stack_init(argc, argv);
		read_instructions(&head_a);
		free_stack(&head_a);
		if (argv[0][0] == '!')
			free_after_split(argv);
	}
}
