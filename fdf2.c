/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:23:27 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/15 12:20:28 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ftt_print(t_map *list, t_env *e)
{
	t_map	*two;
	t_map	*tmp;
	t_map	*q;

	two = list;
	while (two->next)
	{
		tmp = two;
		q = tmp->next;
		while (q)
		{
			if (tmp->x0 == q->x0)
			{
				ft_line(tmp, q, e);
				break ;
			}
			q = q->next;
		}
		two = two->next;
	}
}

void	ft_print(t_map *list, t_env *e)
{
	t_map	*q;
	t_map	*tmp;

	tmp = list;
	while (tmp->next)
	{
		q = tmp->next;
		if (tmp->y0 == q->y0)
			ft_line(tmp, q, e);
		tmp = tmp->next;
	}
	ftt_print(list, e);
	ft_top_line(e);
}

void	ft_center(t_map **list, t_env *e)
{
	t_map	*tmp;

	tmp = *list;
	while (tmp)
	{
		tmp->x += (WIDTH / 2) - (e->max_x * e->p / 15) + e->mx;
		tmp->y += (HEIGHT / 2) - (e->max_y * e->p / 15) + e->my;
		tmp = tmp->next;
	}
}

void	ft_start(t_env *e)
{
	t_map	*tmp;

	tmp = e->list;
	e->rot_x = 225;
	e->rot_y = 135;
	e->rot_z = -90;
	tmp = ft_addcoord(&tmp, e, 0, 0);
	ft_rot_x(e->rot_x, &tmp);
	ft_rot_y(e->rot_y, &tmp);
	ft_rot_z(e->rot_z, &tmp);
	ft_center(&tmp, e);
	ft_print(tmp, e);
}
