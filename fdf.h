/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:33:58 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/15 12:20:58 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1400
# define HEIGHT 1200
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				x0;
	int				y0;
	int				z0;
	int				color;
	struct s_map	*next;
}					t_map;

typedef struct		s_line
{
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
	int				x1;
	int				y1;
	int				y2;
	int				x2;
	int				color;
}					t_line;

typedef struct		s_env
{
	int				x;
	int				y;
	int				z;
	int				k;
	int				p;
	int				nx;
	int				ny;
	int				mx;
	int				my;
	int				mz;
	int				res_k;
	int				max_x;
	int				max_y;
	void			*mlx;
	void			*win;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	t_map			*list;
}					t_env;

void				ft_line(t_map *a, t_map *b, t_env *e);
void				ft_start(t_env *e);
void				ft_free(t_map **list);
void				ft_rot_x(float rotx, t_map **list);
void				ft_rot_y(float roty, t_map **list);
void				ft_rot_z(float rotz, t_map **list);
void				ft_error_line(void);
void				ft_print(t_map *list, t_env *e);
void				ft_center(t_map **list, t_env *e);
void				ft_validate(char *line, t_env *e);
void				ft_free_line(char **res, char *line);
void				ft_add_list(char *str, int x, int fd, t_env **e);
void				ft_open_error(void);
void				ft_line_error(void);
void				ft_symbol_error(void);
void				ft_top_line(t_env *e);
void				ft_color_error(void);
void				ft_valid_color(char *color);

t_map				*ft_addcoord(t_map **tmp, t_env *e, int i, int j);
void				ft_copy_list(t_map *list);
int					key_init(int keycode, t_env *e);
int					ft_size(char *line);

#endif
