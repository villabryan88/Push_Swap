/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/07 00:30:38 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		presort(t_stack **stacks, int ab, int len, int both)
{
	if (len == 1)
		return (1);
	if (len <= 2)
	{
		if (peek(stacks[ab]) > peek2(stacks[ab]))
		{
			if (both && peek(stacks[(ab + 1) % 2]) > peek2(stacks[(ab + 1) % 2]))
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
		if((i < remain && (c == sent || peek(stacks[ab]) < peek(stacks[(ab + 1) % 2]))))
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

void	split_presort(t_stack **stacks, int ab, int len)
{
	int		sent;
	int		remain;
	int		i;

	if (presort(stacks, ab, len, 1))
		return ;
	sent = len / 2;
	remain = len - sent;
	i = 0;
	while (i++ < sent)
		push((ab + 1) % 2, stacks, 1);
	split_presort(stacks, (ab + 1) % 2, sent);
	while (remain > 2)
	{
		sent = remain / 2;
		remain = remain - sent;
		i = 0;
		while (i++ < sent)
			push((ab + 1) % 2, stacks, 1);
		split_presort(stacks, (ab + 1) % 2, sent);
	}
	presort(stacks, ab, remain, 0);
	merge(stacks, ab, remain, sent);
}

void	final_merge(t_stack **stacks)
{
	int		side;
	int		prev[2];
	int		curr[2];
	side = 0;
	prev[0] = peek(stacks[0]);
	prev[1] = peek(stacks[1]);
	curr[0] = peek(stacks[0]);
	curr[1] = peek(stacks[1]);
	while (!isEmpty(stacks[1]))
	{
		if(prev[side] <= curr[side] && 
				(prev[(side + 1) % 2] > curr[(side + 1) % 2] || curr[side] < curr[(side + 1) % 2]))
		{
			prev[side] = peek(stacks[side]);
			rotate(side, stacks, 1);
			curr[side] = peek(stacks[side]);
		}
		else if (prev[(side + 1) % 2] <= curr[(side + 1) % 2])
		{
			prev[(side + 1) % 2] = peek(stacks[(side + 1) % 2]);
			push(side, stacks, 1);
			rotate(side, stacks, 1);
			curr[(side + 1) % 2] = peek(stacks[(side + 1) % 2]);
		}
		if (prev[side] > curr[side] && prev[(side + 1) % 2] > curr[(side + 1) % 2])
		{
			side = (side + 1) % 2;
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
//	final_merge(stacks);
	print_stacks(stacks);
	
	return (0);
}
