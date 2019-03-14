/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:25:50 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/13 17:07:24 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define	ABS(X) (X < 0 ? X * -1 : X)

int		bigger_than(t_stack *stack, void *p_part, t_stack *og, int len)
{
	int		*part;
	
	if(!og || !len)
		return (0);
	part = p_part;
	if (peek(stack) > *part)
		return (1);
	return (0);	
}

int		find_best_part(t_stack *stack, void *p_part_bigger, t_stack *og, int len)
{
	int		*part_bigger;
	int		bigger;
	
	part_bigger = p_part_bigger;
	bigger = block_iter(og, len, &(stack->top->val), bigger_than);
	if (!part_bigger[0] || ABS(len - 2 * bigger) < ABS(len - 2 * part_bigger[1]))
	{
		part_bigger[0] = peek(stack);
		part_bigger[1] = bigger;
	}	
	return (0);
}

int		best_partition(t_stack **stack, int side, int len)
{
	int		part_bigger[2];

	ft_bzero(part_bigger, sizeof(int) * 2);	
	block_iter(stack[side], len, part_bigger, find_best_part);	
	return (part_bigger[0]);
}
