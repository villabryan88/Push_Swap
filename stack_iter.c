/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:41:19 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 22:59:07 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		stack_rotate_iter(t_stack **stacks, t_block *block,
								int (*f)(t_stack**, t_block*))
{
	int		ret;

	while (stacks[block->side]->top)
	{
		if ((ret = f(stacks, block)) == iter_stop())
			return ;
		if (ret == iter_continue())
			rotate(block->side, stacks, 1);
	}
}

void		stack_reverse_iter(t_stack **stacks, t_block *block,
								int (*f)(t_stack**, t_block*))
{
	int		ret;

	while (stacks[block->side]->top)
	{
		if ((ret = f(stacks, block)) == iter_stop())
			return ;
		reverse(block->side, stacks, 1);
	}
}

int			is_block_sorted(t_block block)
{
	block.len--;
	if (block.side == 0)
		return (!block_iter(&block, inc_comp));
	return (!block_iter(&block, dec_comp));
}

int			find_start(t_stack **stacks, t_block *block)
{
	if (stacks[block->side]->top == block->start)
		return (iter_stop());
	return (iter_continue());
}

int			if_top_push(t_stack **stacks, t_block *block)
{
	t_node	*curr;
	int		ret;

	ret = iter_continue();
	curr = stacks[block->side]->top;
	if (can_push(curr, block))
	{
		if (!block->first_push)
			block->first_push = curr;
		block->last_push = curr;
		push(OPP(block->side), stacks, 1);
		ret = iter_count();
	}
	if (ft_strstr(block->msg, "up") && curr == block->push_start)
		ret = iter_stop();
	if (ft_strstr(block->msg, "down") && curr == block->push_end)
	{
		ret = iter_stop();
	}
	return (ret);
}
