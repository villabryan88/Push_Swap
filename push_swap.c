/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 01:39:05 by bvilla           ###   ########.fr       */
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

	ft_printf("push above: %d\n", block->push_above);
	ft_printf("keep above: %d\n", block->keep_above);
	ft_printf("push below: %d\n", block->push_below);

	ft_printf("keep_below: %d\n", block->keep_below);
	ft_printf("msg: %s\n", block->msg);
	ft_printf("in_pushfield: %d\n", block->in_pushfield);
	ft_printf("alone: %d\n", block->alone);
	ft_printf("min: %d\n", block->min);
	ft_printf("max: %d\n", block->max);
}


void		stack_rotate_iter(t_stack **stacks, t_block *block, int (*f)(t_stack**, t_block*))
{
	int		ret;
//int		i = 0;

	while (stacks[block->side]->top)
	{
/*i++;
if (i > 30)
break;
*/
		if ((ret = f(stacks, block)) == iter_stop())
		{

			return ;
		}
		if (ret == iter_continue())
			rotate(block->side, stacks, 1);
	}
}

void		stack_reverse_iter(t_stack **stacks, t_block *block, int (*f)(t_stack**, t_block*))
{
	int		ret;
//int	i = 0;
	while (stacks[block->side]->top)
	{
/*i++;
if (i > 30)
break;
*/
		if ((ret = f(stacks, block)) == iter_stop())
			return ;
		reverse(block->side, stacks, 1);
	}
}

int		is_block_sorted(t_block block)
{
	block.len--;
	if (block.side == 0)
		return (!block_iter(&block, inc_comp));
	return (!block_iter(&block, dec_comp));

}

int		find_start(t_stack **stacks, t_block *block)
{
//	ft_printf("start: %d\n", block->start->val);
//	ft_printf("side: %d\n", block->side);
	if (stacks[block->side]->top == block->start)
		return (iter_stop());
	return (iter_continue());
}
int		if_top_push(t_stack **stacks, t_block *block)
{
	t_node	*curr;
	int		ret;

	ret = iter_continue();
	curr = stacks[block->side]->top;
	if(can_push(curr, block))
	{
		if (!block->first_push)
			block->first_push = curr;
		block->last_push = curr;
		push(OPP(block->side), stacks, 1);
		ret = iter_count();
	}
	if(ft_strstr(block->msg, "up") && curr == block->push_start)
		ret = iter_stop();
	if(ft_strstr(block->msg, "down") && curr == block->push_end)
	{
		ret = iter_stop();
	}
	//	if (curr->val == 8 && block->start->val == 8 && block->end->val == 9)
	//		exit(0);
	return (ret);
}


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

void	push_top(t_stack **stacks, t_block *block)
{

	set_block(stacks, block);
//print_block(block);
	
	if (block->push_above == 0 || 
			(!block->in_pushfield && block->keep_above + block->push_above + block->push_above - 1 >= block->keep_below + block->push_below))
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


void	quicksort(t_stack **stacks, t_block *block)
{
	t_block	keep_block;
	t_block	sent_block;

	ft_bzero(&keep_block, sizeof(t_block));
	ft_bzero(&sent_block, sizeof(t_block));
/*
	static int i = 0;
	if (i++ > 2)
		return;
*/

	//print_stacks(stacks);
	if (is_block_sorted(*block))
	{
		stack_reverse_iter(stacks, block, find_start);
		if (block->side == 1)
			while (block->len--)
				push(0, stacks, 1);
		
//print_stacks(stacks);
		return ;
	}
	if (block->len == 2)
	{
		stack_reverse_iter(stacks, block, find_start);
		swap(block->side, stacks, 1);
		if (block->side == 1)
			while (block->len--)
				push(0, stacks, 1);
//print_stacks(stacks);
		return ;
	}
	assign_best_partition(block);
	block->sent = block->len / 2;
	block->kept = block->len - block->sent;
	push_top(stacks, block);

//print_stacks(stacks);
	if(block->alone/*block->side == 0 && block->kept == stack_len(stacks[0])*/)
		keep_block.start = stacks[block->side]->top;
	else
		keep_block.start = block->keep_start;
	keep_block.side = block->side;
	keep_block.len = block->kept;

	sent_block.side = OPP(block->side);
	sent_block.len = block->sent;
	sent_block.start = block->last_push;

	if (block->side == 0)
		quicksort(stacks, &keep_block);
	quicksort(stacks, &sent_block);
	if (block->side == 1)
		quicksort(stacks, &keep_block);

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
//print_stacks(stacks);
	block.side = 0;
	block.len = len;
	block.start = stacks[0]->top;



//	print_stacks(stacks);	
	quicksort(stacks, &block);
//	print_stacks(stacks);
	return (0);
}
