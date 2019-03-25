/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:25:50 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/20 23:10:44 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define	ABS(X) (X < 0 ? X * -1 : X)
/*
int		above_than(t_stack *stack, void *p_part_bigger_side, t_stack *og, int len)
{
	int		*part_bigger_side;
	
	if(!og || !len)
		return (0);
	part_bigger_side = p_part_bigger_side;
	if (part_bigger_side[2] == 0)
	{
		if (peek(stack) < *part_bigger_side)
			return (1);
	}
	else
	{
		if (peek(stack) > *part_bigger_side)
			return (1);
	}
	return (0);	
}
*/
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
	int		top_value;
	int		above;
	
	block->part =  iter->val;
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
