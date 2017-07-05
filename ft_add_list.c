/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:33:54 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/09 17:14:22 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_add_elem(char *str, t_env **e, int x)
{
	t_map	*elem;
	char	**tmp;

	if (!(elem = (t_map *)malloc(sizeof(t_map))))
		return (0);
	tmp = ft_strsplit(str, ',');
	elem->x = x;
	elem->x0 = x;
	elem->y0 = (*e)->max_y;
	elem->y = (*e)->max_y;
	elem->z = ft_atoi(tmp[0]);
	elem->z0 = ft_atoi(tmp[0]);
	if (tmp[1] != NULL)
	{
		ft_valid_color(tmp[1]);
		tmp[1] = ft_strsub(tmp[1], 2, 6);
		elem->color = ft_atoi_base(tmp[1], 16);
	}
	else if (elem->z == 0)
		elem->color = 16777215;
	else
		elem->color = 0x8B0000;
	free(tmp);
	elem->next = NULL;
	return (elem);
}

static t_map	*ft_push(char *res, t_env **e, int x, t_map *tmp)
{
	t_map *new;

	new = ft_add_elem(res, e, x);
	if (tmp == NULL)
		tmp = new;
	else
	{
		tmp->next = new;
		tmp = tmp->next;
	}
	return (tmp);
}

static t_map	*ft_list(char **res, t_env **e, t_map *list, int x)
{
	while (res[x])
	{
		list = ft_push(res[x], e, x, list);
		x++;
	}
	return (list);
}

void			ft_add_list(char *str, int x, int fd, t_env **e)
{
	t_map	*tmp;
	t_map	*list;
	char	*line;
	char	**res;

	list = (*e)->list;
	if (!(list = (t_map *)malloc(sizeof(t_map))))
		return ;
	tmp = list;
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_open_error();
	while (get_next_line(fd, &line))
	{
		ft_validate(line, (*e));
		res = ft_strsplit(line, ' ');
		x = 0;
		list = ft_list(res, e, list, x);
		(*e)->max_y++;
		ft_free_line(res, line);
	}
	close(fd);
	tmp = tmp->next;
	(*e)->list = tmp;
}
