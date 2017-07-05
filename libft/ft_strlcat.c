/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:04:04 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/05 16:33:23 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t d;
	size_t s;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (size >= d)
	{
		while (src[i] && d < size - 1)\
		{
			dst[d] = src[i];
			d++;
			i++;
		}
		dst[d] = '\0';
		return (((unsigned long)s - i) + (unsigned long)d);
	}
	return ((unsigned long)s + (unsigned long)size);
}
