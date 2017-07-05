/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:37:12 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/06 11:24:15 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			if (str[i] <= 74)
				str[i] = str[i] + 16;
			else
				str[i] = str[i] - 10;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			if (str[i] <= 106)
				str[i] = str[i] + 16;
			else
				str[i] = str[i] - 10;
		}
		i++;
	}
	return (tmp);
}
