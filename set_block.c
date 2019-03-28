/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:13:17 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 22:55:16 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		set_value(t_node *iter, t_block *block)
{
	if (can_pushkeep(iter, block) ||
		(!ft_strstr(block->msg, "push") && !ft_strstr(block->msg, "keep")))
	{
		if (ft_strstr(block->msg, "start"))
		{
			*(t_node**)(block->set_var) = iter;
			return (iter_stop());
		}
		if (ft_strstr(block->msg, "end"))
		{
			*(t_node**)(block->set_var) = iter;
			return (iter_continue());
		}
	}
	return (iter_continue());
}

void	set_temp_value(t_block *block, t_node **var, char *var_name)
{
	block->msg = var_name;
	block->set_var = var;
	block_iter(block, set_value);
}

void	set_keep_push_above_below(t_stack **stacks, t_block *blk)
{
	t_node	*loc;

	loc = stacks[blk->side]->top;
	blk->msg = "keep";
	if (loc == blk->push_start && blk->sent > 1)
		blk->keep_above = piece_iter(next_push(blk), loc, blk, can_pushkeep);
	else
		blk->keep_above = piece_iter(blk->push_start, loc, blk, can_pushkeep);
	blk->msg = "push";
	if (loc == blk->push_start && blk->sent > 1)
		blk->push_above = piece_iter(next_push(blk), loc, blk, can_pushkeep);
	else
		blk->push_above = piece_iter(blk->push_start, loc, blk, can_pushkeep);
	blk->msg = "keep";
	if (loc == blk->push_end && blk->sent > 1)
		blk->keep_below = piece_iter(loc, prev_push(blk), blk, can_pushkeep);
	else
		blk->keep_below = piece_iter(loc, blk->push_end, blk, can_pushkeep);
	blk->msg = "push";
	if (loc == blk->push_end && blk->sent > 1)
		blk->push_below = piece_iter(loc, prev_push(blk), blk, can_pushkeep);
	else
		blk->push_below = piece_iter(loc, blk->push_end, blk, can_pushkeep);
}

void	set_block(t_stack **stacks, t_block *block)
{
	t_node	*loc;

	loc = stacks[block->side]->top;
	assign_best_partition(block);
	block->sent = block->len / 2;
	block->kept = block->len - block->sent;
	block->alone = block->len == stack_len(stacks[block->side]);
	block->min = block_min(block);
	block->max = block_max(block);
	set_temp_value(block, &(block->push_start), "push_start");
	set_temp_value(block, &(block->push_end), "push_end");
	set_temp_value(block, &(block->keep_start), "keep_start");
	set_temp_value(block, &(block->keep_end), "keep_end");
	set_temp_value(block, &(block->end), "end");
	if (piece_len(block->push_start, block->push_end) <= 2)
		block->in_pushfield = 0;
	else
		block->in_pushfield = in_field(stacks[block->side]->top,
				block->push_start->next, block->push_end->prev);
	set_keep_push_above_below(stacks, block);
}
