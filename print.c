/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:30:22 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 23:10:43 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	stacks_to_string_array(t_stack **stacks, char ***a_str, char ***b_str)
{
	char *tmp;

	tmp = stack_convert_string(stacks[0]);
	*a_str = ft_strsplit(tmp, '\n');
	free(tmp);
	tmp = stack_convert_string(stacks[1]);
	*b_str = ft_strsplit(tmp, '\n');
	free(tmp);
}

void	print_stacks(t_stack **stacks, int debug)
{
	char **a_str;
	char **b_str;
	char **a;
	char **b;

	if (debug)
	{
		stacks_to_string_array(stacks, &a_str, &b_str);
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
}

void	print_block(t_block *block, int debug)
{
	if (debug)
	{
		ft_printf("side: %d\n", block->side);
		ft_printf("start: %d\n", block->start->val);
		ft_printf("end: %d\n", block->end->val);
		ft_printf("len: %d\n", block->len);
		ft_printf("part: %d\n", block->part);
		ft_printf("sent: %d\n", block->sent);
		ft_printf("kept: %d\n", block->kept);
		ft_printf("push_start: %d\n", block->push_start->val);
		ft_printf("push_end: %d\n", block->push_end->val);
		ft_printf("keep_start: %d\n", block->keep_start->val);
		ft_printf("keep_end: %d\n", block->keep_end->val);
		ft_printf("push above: %d\n", block->push_above);
		ft_printf("keep above: %d\n", block->keep_above);
		ft_printf("push below: %d\n", block->push_below);
		ft_printf("keep_below: %d\n", block->keep_below);
		ft_printf("msg: %s\n", block->msg);
		ft_printf("in_pushfield: %d\n", block->in_pushfield);
		ft_printf("alone: %d\n", block->alone);
		ft_printf("min: %d\n", block->min);
		ft_printf("max: %d\n", block->max);
	}
}
