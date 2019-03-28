/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:32:30 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 19:36:34 by bvilla           ###   ########.fr       */
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
		if ((ret = f(iter, block)) == iter_stop())
			return (iter->val);
		counter += ret;
		iter = iter->next;
		i++;
	}
	return (counter);
}

int		iter_stop(void)
{
	return (-1);
}

int		iter_count(void)
{
	return (1);
}

int		iter_continue(void)
{
	return (0);
}
