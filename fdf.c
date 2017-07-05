/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:33:01 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/23 11:15:18 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_top_line(t_env *e)
{
	int			c;

	c = 0x009966;
	mlx_string_put(e->mlx, e->win, 5, 5, c, "{'W' 'A' 'S' 'D'} for rotation");
	mlx_string_put(e->mlx, e->win, 5, 50, c, "{'Q', 'E'} for change 'Z'");
	mlx_string_put(e->mlx, e->win, 5, 35, c, "{'+', '-'} for zoon");
	mlx_string_put(e->mlx, e->win, 5, 65, c, "{'R'} for reset");
	mlx_string_put(e->mlx, e->win, 5, 20, c, "Use arrows for move");
}

static void		ft_check_zoom(t_env *e)
{
	e->k = WIDTH / (e->max_x + e->max_y);
	e->p = WIDTH / (e->max_x + e->max_y);
	e->res_k = e->k;
}

static void		first_param(char **argv)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return ;
	e->mx = 0;
	e->my = 0;
	e->mz = 0;
	e->max_x = 0;
	e->max_y = 0;
	ft_add_list(argv[1], 0, 0, &e);
	ft_check_zoom(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FDF_42");
	ft_start(e);
	mlx_hook(e->win, 2, 3, key_init, e);
	mlx_loop(e->mlx);
}

static void		second_param(char **argv)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return ;
	e->mx = 0;
	e->my = 0;
	e->mz = 0;
	e->max_x = 0;
	e->max_y = 0;
	ft_add_list(argv[2], 0, 0, &e);
	ft_check_zoom(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FDF_42");
	ft_start(e);
	mlx_hook(e->win, 2, 3, key_init, e);
	mlx_loop(e->mlx);
}

int				main(int argc, char **argv)
{
	pid_t		pid;

	if (argc == 2 || argc == 3)
	{
		pid = fork();
		if (pid <= 0)
			first_param(argv);
		else if (argc >= 3 && argc <= 4)
			second_param(argv);
	}
	else
	{
		ft_putendl("\x1b[32musage: ./fdf [file_name] or");
		ft_putendl("\x1b[32musage: ./fdf [file_name1] [file_name2]");
		return (0);
	}
	return (0);
}
