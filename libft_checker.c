/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:11:06 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/07 08:47:26 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') & (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	size_t				len_s;
	size_t				len_d;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	if (len_d > dstsize)
		return (len_s + dstsize);
	while (i + len_d + 1 < dstsize && s[i])
	{
		d[i + len_d] = s[i];
		i++;
	}
	if (dstsize > 0 && len_d < dstsize)
		d[i + len_d] = '\0';
	return (len_s + len_d);
}
