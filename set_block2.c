/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_block2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:23:14 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 21:28:29 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		block_min(t_block *block)
{
	int		i;
	t_node	*iter;
	int		min;

	iter = block->start;
	min = block->start->val;
	i = 0;
	while (i < block->len)
	{
		if (iter->val < min)
			min = iter->val;
		iter = iter->next;
		i++;
	}
	return (min);
}

int		block_max(t_block *block)
{
	int		i;
	t_node	*iter;
	int		max;

	iter = block->start;
	max = block->start->val;
	i = 0;
	while (i < block->len)
	{
		if (iter->val > max)
			max = iter->val;
		iter = iter->next;
		i++;
	}
	return (max);
}

int		in_block(t_node *find, t_block *block)
{
	return (find->val >= block->min && find->val <= block->max);
}

int		in_field(t_node *find, t_node *start, t_node *end)
{
	t_node	*iter;

	iter = start;
	while (iter != end)
	{
		if (iter == find)
			return (1);
		iter = iter->next;
	}
	if (iter == find)
		return (1);
	return (0);
}
