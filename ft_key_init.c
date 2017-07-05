/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:09:51 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/15 12:20:16 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_rot(int keykode, t_env *e)
{
	if (keykode == 1)
		e->rot_x -= 5;
	if (keykode == 13)
		e->rot_x += 5;
	if (keykode == 0)
		e->rot_y -= 5;
	if (keykode == 2)
		e->rot_y += 5;
}

void	ft_move(int keykode, t_env *e)
{
	if (keykode == 123)
		e->mx -= 5;
	if (keykode == 124)
		e->mx += 5;
	if (keykode == 125)
		e->my += 5;
	if (keykode == 126)
		e->my -= 5;
	if (keykode == 12)
		e->mz -= 2;
	if (keykode == 14)
		e->mz += 2;
}

void	ft_zoom_color(int keykode, t_env *e)
{
	if (keykode == 78)
		e->k -= 1;
	if (keykode == 69)
		e->k += 1;
	if (e->k < 1)
		e->k = 1;
}

void	ft_reset(t_env *e)
{
	e->rot_x = 225;
	e->rot_y = 135;
	e->rot_z = -90;
	e->mx = 0;
	e->my = 0;
	e->mz = 0;
	e->k = e->res_k;
}

int		key_init(int keykode, t_env *e)
{
	t_map	*list;

	ft_copy_list(e->list);
	list = e->list;
	if (keykode == 53)
		exit(0);
	if (keykode == 78 || keykode == 69)
		ft_zoom_color(keykode, e);
	if (keykode == 15)
		ft_reset(e);
	if ((keykode >= 123 && keykode <= 126) || keykode == 12 || keykode == 14)
		ft_move(keykode, e);
	if ((keykode >= 0 && keykode <= 2) || keykode == 13)
		ft_move_rot(keykode, e);
	mlx_clear_window(e->mlx, e->win);
	list = ft_addcoord(&list, e, 0, 0);
	ft_rot_x(e->rot_x, &list);
	ft_rot_y(e->rot_y, &list);
	ft_rot_z(e->rot_z, &list);
	ft_center(&list, e);
	ft_print(list, e);
	return (0);
}
