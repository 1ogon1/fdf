/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:27:24 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/15 12:20:08 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_x(float rotx, t_map **list)
{
	t_map	*tmp;
	float	y;
	float	z;

	tmp = *list;
	rotx = rotx * 0.01745329252;
	while (tmp)
	{
		y = tmp->y * cos(rotx) - tmp->z * sin(rotx);
		z = tmp->z * cos(rotx) + tmp->y * sin(rotx);
		tmp->y = y;
		tmp->z = z;
		tmp = tmp->next;
	}
}

void	ft_rot_y(float roty, t_map **list)
{
	t_map	*tmp;
	float	x;
	float	z;

	tmp = *list;
	roty = roty * 0.01745329252;
	while (tmp)
	{
		x = tmp->z * cos(roty) + tmp->x * sin(roty);
		z = tmp->x * cos(roty) - tmp->z * sin(roty);
		tmp->x = x;
		tmp->z = z;
		tmp = tmp->next;
	}
}

void	ft_rot_z(float rotz, t_map **list)
{
	t_map	*tmp;
	float	x;
	float	y;

	tmp = *list;
	rotz = rotz * 0.01745329252;
	while (tmp)
	{
		x = tmp->y * cos(rotz) - tmp->x * sin(rotz);
		y = tmp->y * sin(rotz) + tmp->x * cos(rotz);
		tmp->x = x;
		tmp->y = y;
		tmp = tmp->next;
	}
}
