/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:27:16 by rkonoval          #+#    #+#             */
/*   Updated: 2017/02/15 17:29:46 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_str(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n' || s[i + 1] == '\0')
			return (&s[i + 1]);
		i++;
	}
	s = NULL;
	return (s);
}

char	*ft_write_line(char *s)
{
	int		i;
	char	*d;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (!(d = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*str = NULL;

	if ((read(fd, buff, 0)) == -1)
		return (-1);
	if (str == NULL)
	{
		while ((ret = read(fd, buff, BUFF_SIZE)))
		{
			if (ret == 0)
				break ;
			buff[ret] = '\0';
			if (!str)
				str = ft_strdup(buff);
			else
				str = ft_strjoin(str, buff);
		}
	}
	*line = ft_write_line(str);
	str = ft_free_str(str);
	if (str == NULL)
		return (0);
	return (1);
}
