/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:35:27 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 21:26:22 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		piece_iter(t_node *start, t_node *end, t_block *block,
					int (*f)(t_node*, t_block*))
{
	int		ret;
	int		counter;
	t_node	*iter;

	iter = start;
	counter = 0;
	while (iter != end)
	{
		if ((ret = f(iter, block)) == iter_stop())
			return (iter->val);
		counter += ret;
		iter = iter->next;
	}
	if (iter != end)
		return (0);
	if ((ret = f(iter, block)) == iter_stop())
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

t_node	*next_push(t_block *block)
{
	t_node *iter;

	iter = block->push_start->next;
	while (iter != block->push_end)
	{
		if (can_push(iter, block))
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
		if (can_push(iter, block))
			return (iter);
		iter = iter->prev;
	}
	return (iter);
}
