/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:35:27 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/25 11:20:53 by bvilla           ###   ########.fr       */
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
	while (iter != end && iter != block->end)
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
/*
int		check_piece(t_node *start, t_node *end t_block *block)
{
	if (
}
*/
