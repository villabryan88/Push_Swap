/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/25 12:09:30 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	print_block(t_block *block)
{
	ft_printf("side: %d\n", block->side);
	ft_printf("start: %d\n", block->start->val);
	ft_printf("end: %d\n", block->end->val);
	ft_printf("len: %d\n", block->len);
	ft_printf("part: %d\n", block->part);
	ft_printf("sent: %d\n", block->sent);
	ft_printf("kept: %d\n", block->kept);
	ft_printf("push_start: %d\n", block->push_start->val);
	ft_printf("push_end: %d\n", block->push_end->val);
	ft_printf("keep_start: %d\n", block->keep_start->val);
	ft_printf("keep_end: %d\n", block->keep_end->val);

	ft_printf("keep above: %d\n", block->keep_above);

	ft_printf("keep_below: %d\n", block->keep_below);
	ft_printf("push above: %d\n", block->push_above);

	ft_printf("push below: %d\n", block->push_below);
}


void		stack_rotate_iter(t_stack **stacks, t_block *block, int (*f)(t_stack**, t_block*))
{

	while (f(stacks, block))
		rotate(block->side, stacks, 1);
}
/*
int		block_reverse_iter(t_stack **stacks, t_block block, void *data, 
		int (*f)(t_stack**, int, void*))
{
	int		i;
	int		side;
	int		top_val;
	int		moved;

	if(!data)
		return (0);
	side = block.side;
	i = 0;
	while (i < block.len)
	{
		if (!(moved = f(stacks, side, data)))
			return (0);
		else if (moved == 1)
			reverse(side, stacks, 1);
		i++;
	}
	return (1);
}

*/
int		is_block_sorted(t_block block)
{
	block.len--;
	if (block.side == 0)
		return (!block_iter(&block, inc_comp));
	return (!block_iter(&block, dec_comp));

}


int		if_top_push(t_stack **stacks, t_block *block)
{
	t_node	*curr;
	
	curr = stacks[block->side]->top;
	ft_printf("pushing down\n");
/*
	if (block_len == stack_len(stacks[side]))
		see if rotate or reverse rotate is fastest way to get where you wanna go
*/
	if(can_push(curr, block))
		push(OPP(block->side), stacks, 1);
	if(ft_strstr(block->msg, "up") && curr == block->push_start)
		return (0);
	if(ft_strstr(block->msg, "down") && curr == block->push_end)
	{
		return (0);
//		reverse(block->side, stacks, 1);
	}
	return (1);
}


void	push_direction(t_stack **stacks, t_block *block, char *direction)
{
	block->msg = direction;
	if (ft_strstr(direction, "down"))
		stack_rotate_iter(stacks, block, if_top_push);
	if (ft_strstr(direction, "up"))
		stack_reverse_iter(stacks, block, if_top_push);
}

void	push_top(t_stack **stacks, t_block *block)
{

	set_block(stacks, block);
//	print_block(block);
	
	if (block->push_below == 0)
		push_direction(stacks, block, "up");
	else if (block->push_above == 0)
		push_direction(stacks, block, "down");
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


void	quicksort(t_stack **stacks, t_block *block)
{
	t_block	keep_block;
	t_block	sent_block;

	//print_stacks(stacks);
	if (is_block_sorted(*block))
	{
		//rewind to start
		if (block->side == 1)
			while (block->len--)
				push(0, stacks, 1);
		return ;
	}
	if (block->len == 2)
	{
		//rewind to start
		swap(block->side, stacks, 1);
		if (block->side == 1)
			while (block->len--)
				push(0, stacks, 1);
		return ;
	}
	assign_best_partition(block);
	block->sent = block->len / 2;
	block->kept = block->len - block->sent;
	push_top(stacks, block);
	keep_block.side = block->side;
	keep_block.len = block->kept;
	keep_block.start = block->keep_start;
	quicksort(stacks, &keep_block);

	sent_block.side = OPP(block->side);
	sent_block.len = block->sent;
	sent_block.start = block->push_start;
	quicksort(stacks, &sent_block);
}

int		main(int ac, char **av)
{
	int		*nums;
	int		len;
	t_stack	*stacks[2];
	t_block	block;

	stacks[0] = init();
	stacks[1] = init();
	if (ac == 1)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	if(!(nums = parse_nums(ac, av, &len)))
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	populate_stack(nums, len, stacks);

	block.side = 0;
	block.len = len;
	block.start = stacks[0]->top;
		
	quicksort(stacks, &block);
	print_stacks(stacks);	
	return (0);
}
