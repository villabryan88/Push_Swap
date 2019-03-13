/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 09:24:28 by exam              #+#    #+#             */
/*   Updated: 2019/02/19 09:37:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

int isEmpty(struct s_stack *stack)
{
	return (!stack->top);
}

void *peek(struct s_stack *stack)
{
	if (isEmpty(stack))
		return (NULL);
	return (stack->top->content);
}

struct s_stack *init(void)
{
	struct s_stack *new_stack;

	new_stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	new_stack->top = NULL;
	return (new_stack);
}

void *pop(struct s_stack *stack)
{
	void	*content;
	struct s_node *top;

	if (isEmpty(stack))
		return (NULL);
	content = stack->top->content;
	top = stack->top;
	stack->top = stack->top->next;
	free(top);
	return (content);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new_node;

	new_node = (struct s_node*)malloc(sizeof(struct s_node));
	new_node->content = content;
	new_node->next = stack->top;
	stack->top = new_node;
}


