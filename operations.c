/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:37:27 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/04 21:39:17 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(int i, t_stack **stacks)
{
	int		first;
	int		second;
	int		c;

	c = i == -1 ? 0 : i == 's' ? 1 : i - 'a';
	first = stacks[c]->top->val;
	second = stacks[c]->top->next->val;
	stacks[c]->top->val = second;
	stacks[c]->top->next->val = first;
	if (i == 's' - 'a')
		swap(-1 , stacks);
	if (i >= 0)
		ft_printf("s%c\n", i);
}

int		push(int i, t_stack **stacks)
{
	t_node	*tmp;
	int		src;
	int		dst;

	dst = i - 'a';
	src = (dst + 1) % 2;
	if (isEmpty(stacks[src]))
		return (0);
	tmp = pop(stacks[src]);
	unshift(stacks[dst], tmp);
	ft_printf("p%c\n", i);
	return (1);
}

void	rotate(int i, t_stack **stacks)
{
	int		c;

	c = i == -1 ? 0 : i == 'r' - 'a' ? 1 : i - 'a';
	stacks[c]->top = stacks[c]->top->next;
	if (i == 'r' - 'a')
		rotate(-1, stacks);
	if (i >= 0)
		ft_printf("r%c\n", i);
}

void	reverse(int	i, t_stack **stacks)
{
	int		c;

	c = i == -1 ? 0 : i == 'r' - 'a' ? 1 : i - 'a';
	stacks[c]->top = stacks[c]->top->prev;
	if (i == 'r' - 'a')
		reverse(-1, stacks);
	if (i >= 0)
		ft_printf("rr%c\n", i);
}
