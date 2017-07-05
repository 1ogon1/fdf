/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:44:49 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/06 12:11:29 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*des;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	des = (char *)malloc(sizeof(char) * (len + 1));
	if (des != NULL)
	{
		while (i < len)
		{
			des[i] = s1[i];
			i++;
		}
		des[i] = '\0';
		return (des);
	}
	else
		return (0);
}
