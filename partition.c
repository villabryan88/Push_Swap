/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:25:50 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/14 13:18:39 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define	ABS(X) (X < 0 ? X * -1 : X)

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

int		find_best_part(t_stack *stack, void *p_part_bigger_side, t_stack *og, int len)
{
	int		*part_bigger_side;
	int		part_tmp;
	int		bigger;
	
	part_bigger_side = p_part_bigger_side;
	part_tmp = part_bigger_side[0];
	part_bigger_side[0] = peek(stack);
	bigger = block_iter(og, len, part_bigger_side, above_than);
	part_bigger_side[0] = part_tmp;
	if (!part_bigger_side[0] || ABS(len - 2 * bigger) < ABS(len - 2 * part_bigger_side[1]))
	{
		part_bigger_side[0] = peek(stack);
		part_bigger_side[1] = bigger;
	}	
	return (0);
}

int		best_partition(t_stack **stack, int side, int len)
{
	int		part_bigger_side[3];

	ft_bzero(part_bigger_side, sizeof(int) * 3);	
	block_iter(stack[side], len, part_bigger_side, find_best_part);	
	return (part_bigger_side[0]);
}
