/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:32:30 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/13 17:56:07 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		block_iter(t_stack *stack, int len, void *data, int (*f)(t_stack*, void*, t_stack*, int))
{
	int		i;
	int		ret;
	int		counter;
	t_stack *iter;

	iter = init();
	iter->top = stack->top;
	counter = 0;
	i = 0;
	while (i < len)
	{
		if((ret = f(iter, data, stack, len)) == -1)
			return (*((int*)data));
		counter += ret;
		iter->top = iter->top->next;
		i++;
	}
	return (counter);
}
