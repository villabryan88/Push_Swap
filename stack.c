/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:06:19 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 22:44:30 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		isempty(t_stack *stack)
{
	return (!stack->top);
}

int		peek(t_stack *stack)
{
	if (isempty(stack))
		return (0);
	return (stack->top->val);
}

t_stack	*init(void)
{
	t_stack *new_stack;

	new_stack = (t_stack*)malloc(sizeof(t_stack));
	new_stack->top = NULL;
	return (new_stack);
}

t_node	*pop(t_stack *stack)
{
	t_node *top;

	if (isempty(stack))
		return (NULL);
	top = stack->top;
	if (stack->top == stack->top->next)
	{
		stack->top = NULL;
	}
	else
	{
		top->prev->next = top->next;
		top->next->prev = top->prev;
		stack->top = stack->top->next;
	}
	return (top);
}

void	unshift(t_stack *stack, t_node *new_node)
{
	if (isempty(stack))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = stack->top;
		new_node->prev = stack->top->prev;
		stack->top->prev->next = new_node;
		stack->top->prev = new_node;
	}
	stack->top = new_node;
}
