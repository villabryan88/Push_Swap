/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/11 21:00:54 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define OPP(side) (side + 1) % 2

int		presort(t_stack **stacks, int ab, int len, int both)
{
	if (len == 1)
		return (1);
	if (len <= 2)
	{
		if (peek(stacks[ab]) > peek2(stacks[ab]))
		{
			if (both && peek(stacks[OPP(ab)]) > peek2(stacks[OPP(ab)]))
				swap(-1, stacks, 1);
			else
				swap(ab, stacks, 1);
		}
		return (1);
	}
	return (0);
}

void	merge(t_stack **stacks, int ab, int remain, int sent)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < remain || c < sent)
	{
		if((i < remain && (c == sent || peek(stacks[ab]) < peek(stacks[OPP(ab)]))))
		{
			rotate(ab, stacks, 1);
			i++;
		}
		else if (c < sent)
		{
			push(ab, stacks, 1);
			rotate(ab, stacks, 1);
			c++;
		}
	}
}

int		is_block_sorted(t_stack *stack, int len)
{
	int		i;
	t_node	*next;
	t_node	*curr;

	curr = stack->top;
	next = stack->top->next;
	i = 0;
	while (i < len - 1)
	{
		if (curr->val > next->val)
			return (0);
		curr = curr->next;
		next = next->next;
		i++;
	}
	return (1);
}

void	split_presort(t_stack **stacks, int ab, int len)
{
	int		sent;
	int		remain;
	int		i;

	if (is_block_sorted(stacks[ab], len))
			return ;
	if (presort(stacks, ab, len, 1))
		return ;
	sent = len / 2;
	remain = len - sent;
	i = 0;
	while (i++ < sent)
		push(OPP(ab), stacks, 1);
	split_presort(stacks, OPP(ab), sent);
	while (remain > 2)
	{
		if (remain > 4 && is_block_sorted(stacks[ab], remain))
			break ;
		sent = remain / 2;
		remain = remain - sent;
		i = 0;
		while (i++ < sent)
			push(OPP(ab), stacks, 1);
		split_presort(stacks, OPP(ab), sent);
	}
	presort(stacks, ab, remain, 0);
	merge(stacks, ab, remain, sent);
}

int		count_blocks(t_stack *stack)
{
	int		len;
	int		i;
	t_node	*next;
	t_node	*curr;
	int		blocks;

	len = stack_len(stack);
	if (!len)
		return (0);
	blocks = 1;
	curr = stack->top;
	next = stack->top->next;
	i = 0;
	while (i < len - 1)
	{
		if (curr->val > next->val)
			blocks++;
		curr = curr->next;
		next = next->next;
		i++;
	}
	return (blocks);
}

void	final_merge(t_stack **stacks)
{
	int		side;
	int		prev[2];
	int		curr[2];
	int		blocks[2];
	side = 0;
	prev[0] = peek(stacks[0]);
	prev[1] = peek(stacks[1]);
	curr[0] = peek(stacks[0]);
	curr[1] = peek(stacks[1]);
	while (!isEmpty(stacks[1]))
	{
		if(prev[side] <= curr[side] && 
				(prev[OPP(side)] > curr[OPP(side)] || curr[side] < curr[OPP(side)]))
		{
			prev[side] = peek(stacks[side]);
			rotate(side, stacks, 1);
			curr[side] = peek(stacks[side]);
		}
		else if (prev[OPP(side)] <= curr[OPP(side)])
		{
			prev[OPP(side)] = peek(stacks[OPP(side)]);
			push(side, stacks, 1);
			curr[OPP(side)] = peek(stacks[OPP(side)]);
			prev[side] = peek(stacks[side]);
			rotate(side, stacks, 1);
			curr[side] = peek(stacks[side]);
		}
		if (prev[side] > curr[side] && prev[OPP(side)] > curr[OPP(side)])
		{
			blocks[0] = count_blocks(stacks[0]);
			blocks[1] = count_blocks(stacks[1]);
			if (blocks[0] > blocks[1])
				side = 1;
			else
				side = 0;
			prev[0] = peek(stacks[0]);
			prev[1] = peek(stacks[1]);
			curr[0] = peek(stacks[0]);
			curr[1] = peek(stacks[1]);

		}

	}	
}

int		main(int ac, char **av)
{
	int		*nums;
	int		len;
	int		ok;
	t_stack	*stacks[2];
	int		blocks[2];

	ft_bzero(blocks, sizeof(int) * 2);
	ok = 1;
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
	split_presort(stacks, 0, len);
//	print_stacks(stacks);
//	ft_printf("left blocks: %d, right blocks: %d\n", count_blocks(stacks[0]), count_blocks(stacks[1]));
	final_merge(stacks);
//	print_stacks(stacks);
	
	return (0);
}
