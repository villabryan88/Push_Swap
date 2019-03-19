/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/18 22:16:25 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define OPP(side) (side + 1) % 2

int		inc_comp(t_stack *stack, void *data, t_stack *og, int len)
{
	if (!og || !len)
		return (1);
	int		top_vals[2];
	top_vals[0] = stack->top->val;
	top_vals[1] = stack->top->next->val;
	if (top_vals[0] < top_vals[1])
		return (0);
	else
		return (1);
}
int		dec_comp(t_stack *stack, void *data, t_stack *og, int len)
{
	if (!og || !len)
		return (1);
	int		top_vals[2];
	top_vals[0] = stack->top->val;
	top_vals[1] = stack->top->next->val;
	if (top_vals[0] > top_vals[1])
		return (0);
	else
		return (1);
}
int		block_rotate_iter(t_stack **stacks, t_block block, void *data, 
		int (*f)(t_stack**, int, void*))
{
	int		i;
	int		side;
	int		top_val;
	int		moved;
	int		counter;

	counter = 0;

	if(!data)
		return (0);
	side = block.side;
	i = 0;
	while (i < block.len)
	{
		if (!(moved = f(stacks, side, data)))
			return (counter);
		else if (moved == 1)
			rotate(side, stacks, 1);
		else
			counter++;
		i++;
	}
	return (counter);
}
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


int		is_block_sorted(t_stack **stacks, int side, int len)
{
	if (side == 0)
		return (!block_iter(stacks[side], len - 1, (void*)1, inc_comp));
	return (!block_iter(stacks[side], len - 1, (void*)1, dec_comp));

}


int		until(t_stack **stacks, int side, void *p_part)
{
	t_block *block;
	int		*part;

	part = p_part;

	if (peek(stacks[side]) == *part)
		return (0);
	return (1);
}

int		if_top_push(t_stack **stacks, int side, void *p_part_top_s_bot)
{
	t_block *block;
	int		*part_top_s_bot;
	static int ret = 0;

	part_top_s_bot = p_part_top_s_bot;
	if (part_top_s_bot[1] + part_top_s_bot[3] == stack_len(stacks[side]))
		ret = 1;
	if (!part_top_s_bot[1])
	{
		part_top_s_bot[3]--;
		if (!part_top_s_bot[3])
		{
			ret = 0;
			return (1);
		}
		return (ret);
	}
	if((side == 0 && peek(stacks[side]) < *part_top_s_bot) 
			|| (side == 1 && peek(stacks[side]) > *part_top_s_bot))
	{
		push(OPP(side), stacks, 1);
		part_top_s_bot[1]--;
		return (2);
	}
	part_top_s_bot[3]--;
	return (1);
}

int		find_first(t_stack *stack, void *p_part_side, t_stack *og, int len)
{
	int		top;
	int		*part_side;
	int		side;

	part_side = p_part_side;
	if (part_side[1] == 0)
	{
		if ((top = peek(stack)) >= part_side[0])
		{
			part_side[0] = top;
			return (-1);
		}
	}
	else
	{
		if ((top = peek(stack)) <= part_side[0])
		{
			part_side[0] = top;
			return (-1);
		}
	}
	return (0);
}

int		push_top(t_stack **stacks, int side, int len, int part)
{
	t_block block;
	int		sent;
	int		start_side[2];
	int		part_top_side_bot[4];

	start_side[0] = part;
	start_side[1] = side;
	start_side[0] = block_iter(stacks[side], len, &start_side, find_first);
	block.side = side;
	block.len = len;
	part_top_side_bot[0] = part;
	part_top_side_bot[2] = side;
	part_top_side_bot[1] = block_iter(stacks[side], len, part_top_side_bot, above_than);
	part_top_side_bot[3] = len - part_top_side_bot[1];
	sent = block_rotate_iter(stacks, block, part_top_side_bot, if_top_push);
	block_reverse_iter(stacks, block, &start_side, until);	
	return (sent);
}


void	quicksort(t_stack **stacks)
{
	int		partition;
	int		sent;
	int		remain;

	print_stacks(stacks);
	if (is_block_sorted(stacks, side, len))
	{
		if (side == 1)
			while (len--)
				push(0, stacks, 1);
		return ;
	}
	if (len == 2)
	{
		swap(side, stacks, 1);
		if (side == 1)
			while (len--)
				push(0, stacks, 1);
		return ;
	}
	partition = best_partition(stacks, side, len);
	sent = push_top(stacks, side, len, partition);
	remain = len - sent;
	quicksort(stacks, 0, remain);
	quicksort(stacks, 1, sent);
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
	quicksort(stacks, block);

	return (0);
}
