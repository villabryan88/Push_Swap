/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:48:23 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 22:34:49 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_direction(t_stack **stacks, t_block *block, char *direction)
{
	block->msg = direction;
	if (ft_strstr(direction, "down"))
	{
		if (stacks[block->side]->top == block->push_end && block->sent > 1)
			block->push_end = prev_push(block);
		stack_rotate_iter(stacks, block, if_top_push);
	}
	if (ft_strstr(direction, "up"))
	{
		if (stacks[block->side]->top == block->push_start && block->sent > 1)
			block->push_start = next_push(block);
		stack_reverse_iter(stacks, block, if_top_push);
	}
}

void	push_top(t_stack **stacks, t_block *block, int debug)
{
	print_block(block, debug);
	if (block->push_above == 0 ||
			(!block->in_pushfield &&
				block->keep_above + block->push_above + block->push_above - 1
				>= block->keep_below + block->push_below))
		push_direction(stacks, block, "down");
	else if (block->push_below == 0 || !block->in_pushfield)
		push_direction(stacks, block, "up");
	else if (block->keep_below + 1 <= block->keep_above)
	{
		push_direction(stacks, block, "down");
		push_direction(stacks, block, "up");
	}
	else
	{
		push_direction(stacks, block, "up");
		push_direction(stacks, block, "down");
	}
}

int		small_blocks(t_stack **stacks, t_block *block, int debug)
{
	if (is_block_sorted(*block))
	{
		stack_reverse_iter(stacks, block, find_start);
		if (block->side == 1)
			while (block->len--)
				push(0, stacks, 1);
		print_stacks(stacks, debug);
		return (1);
	}
	if (block->len == 2)
	{
		stack_reverse_iter(stacks, block, find_start);
		swap(block->side, stacks, 1);
		if (block->side == 1)
			while (block->len--)
				push(0, stacks, 1);
		print_stacks(stacks, debug);
		return (1);
	}
	return (0);
}

int		end_cases(t_stack **stacks, t_block *block, int debug)
{
	t_block	keep_block;

	ft_bzero(&keep_block, sizeof(t_block));
	if (small_blocks(stacks, block, debug))
		return (1);
	if (block->len == 3 && block->alone)
	{
		if (stacks[0]->top->val == block->max)
			rotate(block->side, stacks, 1);
		else if (stacks[0]->top->next->val == block->max)
			reverse(block->side, stacks, 1);
		keep_block.side = block->side;
		keep_block.len = 2;
		keep_block.start = stacks[block->side]->top;
		quicksort(stacks, &keep_block, debug);
		return (1);
	}
	return (0);
}

void	quicksort(t_stack **stacks, t_block *block, int debug)
{
	t_block	keep_block;
	t_block	sent_block;

	ft_bzero(&keep_block, sizeof(t_block));
	ft_bzero(&sent_block, sizeof(t_block));
	if (end_cases(stacks, block, debug))
		return ;
	set_block(stacks, block);
	push_top(stacks, block, debug);
	print_stacks(stacks, debug);
	if (block->alone)
		keep_block.start = stacks[block->side]->top;
	else
		keep_block.start = block->keep_start;
	keep_block.side = block->side;
	keep_block.len = block->kept;
	sent_block.side = OPP(block->side);
	sent_block.len = block->sent;
	sent_block.start = block->last_push;
	if (block->side == 0)
		quicksort(stacks, &keep_block, debug);
	quicksort(stacks, &sent_block, debug);
	if (block->side == 1)
		quicksort(stacks, &keep_block, debug);
}
