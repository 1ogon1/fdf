/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:10:21 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/06 13:46:17 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_copy_list(t_map *list)
{
	while (list)
	{
		list->x = list->x0;
		list->y = list->y0;
		list->z = list->z0;
		list = list->next;
	}
}
