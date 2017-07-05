/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:38:15 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/06 12:20:07 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*src;
	size_t	i;

	i = 0;
	src = (char *)malloc(sizeof(char) * size + 1);
	if (src == NULL)
		return (NULL);
	while (i <= size)
	{
		src[i] = '\0';
		i++;
	}
	src[i] = '\0';
	return (src);
}
