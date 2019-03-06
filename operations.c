/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:37:27 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/04 22:28:11 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(int i, t_stack **stacks, int ver)
{
	int		first;
	int		second;
	int		c;

	c = i == -1 ? 0 : i == 's' - 'a' ? 1 : i;
	first = stacks[c]->top->val;
	second = stacks[c]->top->next->val;
	stacks[c]->top->val = second;
	stacks[c]->top->next->val = first;
	if (i == -1)
		swap('s' - 'a', stacks, ver);
	if (ver && i >= 0)
		ft_printf("s%c\n", i + 'a');
}

int		push(int i, t_stack **stacks, int ver)
{
	t_node	*tmp;
	int		src;
	int		dst;

	dst = i;
	src = (dst + 1) % 2;
	if (isEmpty(stacks[src]))
		return (0);
	tmp = pop(stacks[src]);
	unshift(stacks[dst], tmp);
	if (ver)
		ft_printf("p%c\n", i + 'a');
	return (1);
}

void	rotate(int i, t_stack **stacks, int ver)
{
	int		c;

	c = i == -1 ? 0 : i == 'r' - 'a' ? 1 : i;
	stacks[c]->top = stacks[c]->top->next;
	if (i == -1)
		rotate('r' - 'a', stacks, ver);
	if (ver && i >= 0)
		ft_printf("r%c\n", i + 'a');
}

void	reverse(int	i, t_stack **stacks, int ver)
{
	int		c;

	c = i == -1 ? 0 : i == 'r' - 'a' ? 1 : i;
	stacks[c]->top = stacks[c]->top->prev;
	if (i == -1)
		rotate('r' - 'a', stacks, ver);
	if (ver && i >= 0)
		ft_printf("rr%c\n", i + 'a');
}
