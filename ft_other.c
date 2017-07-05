/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:21:04 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/09 17:25:32 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*ft_addcoord(t_map **tmp, t_env *e, int i, int j)
{
	t_map	*q;

	e->ny = 0;
	q = *tmp;
	while (q)
	{
		while (e->ny < e->max_y)
		{
			j = 0;
			e->nx = 0;
			while (e->nx < e->max_x)
			{
				q->x = (q->x * e->k - e->max_x * e->k / 2);
				q->y = (q->y * e->k - e->max_y * e->k / 2);
				if (q->z != 0)
					q->z += e->mz;
				j += e->k;
				e->nx++;
				q = q->next;
			}
			i += e->k;
			e->ny++;
		}
	}
	return (*tmp);
}

static void	ft_valid_line(char *line, t_env *e)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			size++;
		i++;
	}
	if (e->max_x == 0)
		e->max_x = size;
	else if (size != e->max_x)
		ft_line_error();
}

void		ft_validate(char *line, t_env *e)
{
	int		i;

	i = 0;
	while (line[i])
	{
		line[i] = ft_tolower(line[i]);
		if ((line[i] >= '0' && line[i] <= '9') ||
				(line[i] >= 'a' && line[i] <= 'f') ||
				line[i] == ',' || line[i] == 'x' ||
				line[i] == ' ' || line[i] == '-')
			i++;
		else
			ft_symbol_error();
	}
	ft_valid_line(line, e);
}

void		ft_free_line(char **res, char *line)
{
	int	i;

	i = 0;
	if (res)
	{
		while (res[i])
		{
			free(res[i]);
			i++;
		}
	}
	if (line)
		free(line);
}

void		ft_valid_color(char *color)
{
	int	i;

	i = 2;
	if (ft_strlen(color) > 8)
		ft_color_error();
	if (color[0] != '0')
		ft_color_error();
	if (color[1] != 'x')
		ft_color_error();
	while (color[i])
	{
		if ((color[i] >= '0' && color[i] <= '9') ||
				(color[i] >= 'a' && color[i] <= 'f') ||
				(color[i] >= 'A' && color[i] <= 'F'))
			i++;
		else
			ft_color_error();
	}
}
