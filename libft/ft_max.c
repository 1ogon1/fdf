/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:17:31 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/06 11:20:25 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, int length)
{
	int max;
	int i;

	if (length != 0)
	{
		i = 0;
		max = tab[i];
		while (i < length)
		{
			if (tab[i] > max)
				max = tab[i];
			i++;
		}
		return (max);
	}
	else
		return (0);
}
