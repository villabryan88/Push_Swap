/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:29:05 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/04 14:45:15 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*new_node(int	val)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	print_stack(t_stack *stack)
{
	t_node *start;
	t_node *i;

	if (!stack || isEmpty(stack))
	{
		ft_printf("empty\n");
		return ;
	}
	start = stack->top;
	i = start;
	while (i != start->prev)
	{
		ft_printf("%d\n", i->val);
		i = i->next;
	}
	ft_printf("%d\n", i->val);
}
