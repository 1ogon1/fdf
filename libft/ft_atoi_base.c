/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:00:46 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/09 15:11:15 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_16(char c)
{
	int		nb;

	nb = 0;
	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'A' && c <= 'F')
		nb = c - 'A' + 10;
	else
		nb = c - 'a' + 10;
	return (nb);
}

int			ft_atoi_base(char *s, int base)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F')
			|| (s[i] >= 'a' && s[i] <= 'f'))
	{
		nb = nb * base + ft_16(s[i]);
		i++;
	}
	return (nb);
}
