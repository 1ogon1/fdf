/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:03:03 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/09 16:58:35 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color_error(void)
{
	ft_putstr("\x1b[31mError. Invalid color\n");
	exit(0);
}

void	ft_open_error(void)
{
	ft_putstr("\x1b[31mError open file\n");
	exit(0);
}

void	ft_line_error(void)
{
	ft_putstr("\x1b[31mError. Diferent size line\n");
	exit(0);
}

void	ft_symbol_error(void)
{
	ft_putstr("\x1b[31mError. Not allowed symbol\n");
	exit(0);
}
