/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/13 14:35:28 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define OPP(side) (side + 1) % 2

int		inc_comp(t_stack **stacks, int side, int top_vals[2], void *data)
{
	if (!stacks || side != 0 || !data)
		return (0);
	if (top_vals[0] > top_vals[1])
		return (0);
	else
		return (1);
}



int		block_iter(t_stack **stacks, t_block block, void *data, int (*f)(t_stack**, int, int[2], void*))
{
	int		i;
	int		top_vals[2];
	t_node	*top_elems[2];
	int		ret;
	int		counter;

	counter = 0;
	if(!data)
		return (0);
	top_elems[0] = stacks[block.side]->top;
	top_elems[1] = stacks[block.side]->top->next;
	i = 0;
	while (i < block.len)
	{
		top_vals[0] = top_elems[0]->val;
		top_vals[1] = top_elems[1]->val;
		if (!(ret = f(stacks, block.side, top_vals, data)))
			return (0);
		else if (ret == 2)
			counter++;
		top_elems[0] = top_elems[0]->next;
		top_elems[1] = top_elems[1]->next; 
		i++;
	}
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
			return (0);
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


int		is_block_sorted(t_stack *stack, int len)
{
	t_block blank;
	blank.side = 0;
	blank.len = len - 1;
	return (block_iter(&stack, blank, (void*)1, inc_comp));
}

int		if_smaller_push(t_stack **stacks, int side, void *p_part)
{
	t_block *block;
	int		*part;

	part = p_part;

	if (peek(stacks[side]) < *part)
	{
		push(OPP(side), stacks, 1);
		return (2);
	}
	return (1);
}

int		rewind_until(t_stack **stacks, int side, void *p_part)
{
	t_block *block;
	int		*part;

	part = p_part;

	if (peek(stacks[side]) == *part)
		return (0);
	return (1);
}

int		push_smaller(t_stack **stacks, int side, int len, int part)
{
	t_block block;
	int		sent;

	block.side = side;
	block.len = len - 1;
	rotate(side, stacks, 1);
	sent = block_rotate_iter(stacks, block, &part, if_smaller_push);
	block_reverse_iter(stacks, block, &part, rewind_until);	

	return (sent);
}

void	quicksort(t_stack **stacks, int side, int len)
{
	int		partition;
	int		sent;
	int		remain;

	partition = peek(stacks[side]);

	if (is_block_sorted(stacks[side], len))
		return ;
	sent = push_smaller(stacks, side, len, partition);
	quicksort(stacks, OPP(side), sent);

}

int		main(int ac, char **av)
{
	int		*nums;
	int		len;
	t_stack	*stacks[2];

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
//	ft_printf("%d\n", is_block_sorted(stacks[0], len));
	quicksort(stacks, 0, len);
	print_stacks(stacks);
	return (0);
}
