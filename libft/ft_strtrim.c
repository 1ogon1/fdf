/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:15:14 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/06 12:22:09 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_search_len(char const *str)
{
	int i;
	int len;
	int lenbeg;

	i = 0;
	len = 0;
	lenbeg = 0;
	while (str[len])
		len++;
	while (str[lenbeg] == ' ' || str[lenbeg] == '\n' || str[lenbeg] == '\t')
		lenbeg++;
	while (str[len - 1] == ' ' || str[len - 1] == '\n' || str[len - 1] == '\t')
		len--;
	if (len > lenbeg)
		return (len - lenbeg);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	dst = (char *)malloc(sizeof(char) * ft_search_len(s) + 1);
	if (dst == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < ft_search_len(s))
	{
		dst[j] = s[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
