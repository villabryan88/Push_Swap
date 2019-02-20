/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:44:27 by bvilla            #+#    #+#             */
/*   Updated: 2019/02/20 13:44:38 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_arrlen(void *arr, size_t size)
{
	int		i;

	i = 0;
	while(ft_elemval((unsigned char*)arr + i * size, size))
		i++;
	return (i);
}
