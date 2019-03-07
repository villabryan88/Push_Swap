/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:49:34 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/06 00:16:30 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#include "push_swap.h"

int		main()
{
	ft_printf("t_list size: %lu\n", sizeof(t_list));

	ft_printf("t_stack size: %lu\n", sizeof(t_stack));
	ft_printf("t_node size: %lu\n", sizeof(t_node));
}
