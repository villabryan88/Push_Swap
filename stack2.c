/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:29:05 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 22:57:42 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*new_node(int val)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int		stack_len(t_stack *stack)
{
	t_node	*start;
	t_node	*i;
	int		c;

	c = 0;
	if (!stack || isempty(stack))
		return (0);
	start = stack->top;
	i = start;
	while (i != start->prev)
	{
		i = i->next;
		c++;
	}
	return (c + 1);
}

char	*stack_convert_string(t_stack *stack)
{
	t_node	*start;
	t_node	*i;
	char	*str;

	str = ft_memalloc(1);
	if (!stack || isempty(stack))
	{
		free(str);
		str = ft_strdup("empty\n");
		return (str);
	}
	start = stack->top;
	i = start;
	while (i != start->prev)
	{
		str = ft_strjoin_free(str, ft_itoa(i->val), 1, 1);
		str = ft_strjoin_free(str, "\n", 1, 0);
		i = i->next;
	}
	str = ft_strjoin_free(str, ft_itoa(i->val), 1, 1);
	str = ft_strjoin_free(str, "\n", 1, 0);
	return (str);
}

void	print_stack(t_stack *stack)
{
	char *str;

	str = stack_convert_string(stack);
	ft_printf("%s", str);
	free(str);
}
