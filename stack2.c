/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:29:05 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/06 20:49:14 by bvilla           ###   ########.fr       */
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

int		stack_len(t_stack *stack)
{
	t_node *start;
	t_node *i;
	int		c;

	c = 0;
	if (!stack || isEmpty(stack))
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
	if (!stack || isEmpty(stack))
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
	free (str);
}

void	print_stacks(t_stack **stacks)
{
	char **a_str;
	char **b_str;
	char **a;
	char **b;

	a = (char**)stack_convert_string(stacks[0]);
	a_str = ft_strsplit((char*)a, '\n');
	free(a);
	a = (char**)stack_convert_string(stacks[1]);
	b_str = ft_strsplit((char*)a, '\n');
	free(a);
	a = a_str;
	b = b_str;
	ft_printf("%10s    %10s\n", "stack a", "stack b");
	ft_printf("%10s    %10s\n", "-------", "-------");
	while (*a || *b)
	{
		ft_printf("%10s    %10s\n", *a ? *a : "", *b ? *b : "");
		if (*a)
			a++;
		if (*b)
			b++;
	}
	ft_strarrdel(a_str);
	ft_strarrdel(b_str);
}

