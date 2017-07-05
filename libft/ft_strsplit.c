/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:17:36 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/06 12:20:55 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_num_w(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static int		ft_num_s(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

static char		*ft_create_tab_i(char const *s, char c, char *str, int k)
{
	int	j;

	j = 0;
	while (s[k] && s[k] != c)
	{
		str[j] = s[k];
		k++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char		**ft_create_tab(char const *s, char c, char **tab, int i)
{
	int	k;

	k = 0;
	while (s[k])
	{
		while (s[k] == c && s[k])
			k++;
		if (s[k] && s[k] != c)
		{
			tab[i] = (char*)malloc(sizeof(char) * ft_num_s(&s[k], c) + 1);
			if (tab[i] == NULL)
				return (NULL);
			tab[i] = ft_create_tab_i(s, c, tab[i], k);
			while (s[k] && s[k] != c)
				k++;
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s || !c)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * ft_num_w(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	tab = ft_create_tab(s, c, tab, 0);
	return (tab);
}
