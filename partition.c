/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:25:50 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 21:21:03 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define ABS(X) (X < 0 ? X * -1 : X)

int		above_than(t_node *iter, t_block *block)
{
	int		part;
	int		side;

	part = block->part;
	side = block->side;
	if (side == 0)
	{
		if (iter->val < part)
			return (1);
	}
	else
	{
		if (iter->val > part)
			return (1);
	}
	return (0);
}

int		find_best_part(t_node *iter, t_block *block)
{
	int		above;

	block->part = iter->val;
	above = block_iter(block, above_than);
	if (above == block->len / 2)
		return (-1);
	return (0);
}

void	assign_best_partition(t_block *block)
{
	block_iter(block, find_best_part);
	return ;
}
