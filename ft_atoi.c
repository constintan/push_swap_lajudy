/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:06:36 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 08:47:23 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_BOUNDRY 922337203685477580
#define MIN_BOUNDRY -922337203685477580

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_over_boundry(long long int n, char c, int sign)
{
	if ((n * sign) == MIN_BOUNDRY)
		if (c == '8' || c == '9')
			return (0);
	if ((n * sign) < MIN_BOUNDRY - 1)
		return (0);
	if ((n * sign) == MAX_BOUNDRY)
		if (c == '8' || c == '9')
			return (-1);
	if ((n * sign) > MAX_BOUNDRY + 1)
		return (-1);
	return (1);
}

long long int	ft_atoi(const char *str)
{
	long long int	n;
	int				sign;
	int				boundry;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	n = 0;
	while (*str && ft_isdigit(*str))
	{
		boundry = ft_over_boundry(n, *str, sign);
		if (boundry != 1)
			return (boundry);
		n = 10 * n + (*str - '0');
		str++;
	}
	return (n * sign);
}
