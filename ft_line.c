/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:23:45 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/10 13:00:36 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

static void		ft_help(t_line *line, t_env *e)
{
	while (line->x1 != line->x2 || line->y1 != line->y2)
	{
		mlx_pixel_put(e->mlx, e->win, line->x1, line->y1, line->color);
		line->error2 = line->error * 2;
		if (line->error2 > -(line->deltay))
		{
			line->error -= line->deltay;
			line->x1 += line->signx;
		}
		if (line->error2 < line->deltax)
		{
			line->error += line->deltax;
			line->y1 += line->signy;
		}
	}
}

static void		ft_color(t_line *line, t_map *a, t_map *b)
{
	if (a->color == 16777215 && b->color != 16777215)
		line->color = b->color;
	else if (a->color != 16777215 && b->color == 16777215)
		line->color = a->color;
	else
		line->color = a->color;
}

void			ft_line(t_map *a, t_map *b, t_env *e)
{
	t_line	*line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	line->x1 = a->x;
	line->y1 = a->y;
	line->x2 = b->x;
	line->y2 = b->y;
	ft_color(line, a, b);
	line->deltax = abs(line->x2 - line->x1);
	line->deltay = abs(line->y2 - line->y1);
	if (line->x1 < line->x2)
		line->signx = 1;
	else
		line->signx = -1;
	if (line->y1 < line->y2)
		line->signy = 1;
	else
		line->signy = -1;
	line->error = line->deltax - line->deltay;
	mlx_pixel_put(e->mlx, e->win, line->x2, line->y2, line->color);
	ft_help(line, e);
	free(line);
}
