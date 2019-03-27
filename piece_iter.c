/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:35:27 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 00:33:05 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		piece_iter(t_node *start, t_node *end, t_block *block, int (*f)(t_node*, t_block*))
{

	int		ret;
	int		counter;
	t_node	*iter;

	iter = start;
	counter = 0;

//	ft_printf("start: %d, end: %d\n", start->val, end->val);
	while (iter != end /*&& (block->alone || iter != block->end)*/)
	{
		if((ret = f(iter, block)) == iter_stop())
			return (iter->val);
		counter += ret;
		iter = iter->next;
	}
	if (iter != end)
		return (0);
	if((ret = f(iter, block)) == iter_stop())
		return (iter->val);
	counter += ret;
	return (counter);
}

int		piece_len(t_node *start, t_node *end)
{
	int		i;
	t_node	*iter;
	
	i = 1;
	iter = start;
	while (iter != end)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}

int		in_block(t_node *find, t_block *block)
{
	return(find->val >= block->min && find->val <= block->max);
}

int		in_field(t_node *find, t_node *start, t_node *end)
{
	int		i;
	t_node	*iter;

	iter = start;
	while (iter != end)
	{
		if(iter == find)
			return (1);
		iter = iter->next;
	}
	if(iter == find)
		return (1);

	return (0);
}

t_node	*next_push(t_block *block)
{
	t_node *iter;
	
	iter = block->push_start->next;
	while (iter != block->push_end)
	{
		if(can_push(iter, block))
			return (iter);
		iter = iter->next;
	}
	return (iter);
}

t_node	*prev_push(t_block *block)
{
	t_node *iter;
	
	iter = block->push_end->prev;
	while (iter != block->push_start)
	{
		if(can_push(iter, block))
			return (iter);
		iter = iter->prev;
	}
	return (iter);
}

int		block_min(t_block *block)
{
	int		i;
	t_node *iter;
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
	t_node *iter;
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
