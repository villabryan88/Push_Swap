/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:32:14 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 23:00:16 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		inc_comp(t_node *iter, t_block *block)
{
	int		top_vals[2];

	if (!block)
		return (0);
	top_vals[0] = iter->val;
	top_vals[1] = iter->next->val;
	if (top_vals[0] < top_vals[1])
		return (iter_continue());
	else
		return (iter_count());
}

int		dec_comp(t_node *iter, t_block *block)
{
	int		top_vals[2];

	if (!block)
		return (0);
	top_vals[0] = iter->val;
	top_vals[1] = iter->next->val;
	if (top_vals[0] > top_vals[1])
		return (iter_continue());
	else
		return (iter_count());
}

int		can_push(t_node *iter, t_block *block)
{
	if (block->side == 0 && iter->val < block->part && in_block(iter, block))
		return (1);
	if (block->side == 1 && iter->val > block->part && in_block(iter, block))
		return (1);
	return (0);
}

int		can_pushkeep(t_node *iter, t_block *block)
{
	if (ft_strstr(block->msg, "push"))
		return (can_push(iter, block));
	else if (ft_strstr(block->msg, "keep"))
		return (!can_push(iter, block));
	return (0);
}
