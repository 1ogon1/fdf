/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:40:06 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/05 16:31:52 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litt, size_t len)
{
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = 0;
	while (litt[s])
		s++;
	if (s == 0)
		return ((char *)big);
	while (big[i] && (size_t)i < len)
	{
		while (litt[j] == big[i + j] && (size_t)(i + j) < len)
		{
			if (j == s - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
