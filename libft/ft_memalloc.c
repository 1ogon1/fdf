/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:33:15 by rkonoval          #+#    #+#             */
/*   Updated: 2016/12/06 12:06:02 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*data;

	data = (size_t *)malloc(sizeof(size_t) * size);
	if (!data)
		return (NULL);
	ft_bzero(data, size);
	return (data);
}
