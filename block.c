/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:32:30 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/25 12:30:35 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		block_iter(t_block *block, int (*f)(t_node*, t_block*))
{
	int		i;
	int		ret;
	int		counter;
	t_node	*iter;

	iter = block->start;
	counter = 0;
	i = 0;
	while (i < block->len)
	{
		if((ret = f(iter, block)) == iter_stop())
			return (iter->val);
		counter += ret;
		iter = iter->next;
		i++;
	}
	return (counter);
}

int		iter_stop()
{
	return (-1);
}

int		iter_count()
{
	return (1);
}

int		iter_continue()
{
	return (0);
}
int		inc_comp(t_node *iter, t_block *block)
{
	int		top_vals[2];
	top_vals[0] = iter->val;
	top_vals[1] = iter->next->val;
	if (top_vals[0] < top_vals[1])
		return (iter_continue());
	else
		return (iter_count());
}
int		dec_comp(t_node *iter, t_block *block)
{
	int		top_vals[2];

	top_vals[0] = iter->val;
	top_vals[1] = iter->next->val;
	if (top_vals[0] > top_vals[1])
		return (iter_continue());
	else
		return (iter_count());
}

