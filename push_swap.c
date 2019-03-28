/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 22:38:18 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	int		*nums;
	int		len;
	t_stack	*stacks[2];
	t_block	block;
	int		debug;

	debug = 0;
	stacks[0] = init();
	stacks[1] = init();
	if (ac == 1)
		return (error());
	if (!(nums = parse_nums(ac, av, &len, &debug)))
		return (error());
	populate_stack(nums, len, stacks);
	print_stacks(stacks, debug);
	block.side = 0;
	block.len = len;
	block.start = stacks[0]->top;
	block.alone = 1;
	block.max = block_max(&block);
	quicksort(stacks, &block, debug);
	print_stacks(stacks, debug);
	return (0);
}
