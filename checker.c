/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:17:25 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/04 21:39:48 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		do_instruction(char *s, t_stack **stacks)
{
	int		len;

	len = ft_strlen(s);
	if (len > 3 || len < 2)
		return (0);
	if (len == 3)
	{
		if (s[0] != 'r' || s[1] != 'r' || (s[2] != 'a' && s[2] != 'b'))
			return (0);
		reverse(s[2] - 'a', stacks);
	}
	if (s[1] != 'a' && s[1] != 'b')
		return (0);
	if (s[0] == 'r')
		rotate(s[0] - 'a', stacks);
	else if (s[0] == 'p')
		push(s[0] - 'a', stacks);
	else if (s[0] == 's')
		swap(s[0] - 'a', stacks);
	else
		return (0);
	return (1);
}

void	run_instructions(t_stack **stacks)
{
	char *line;
	char *op;
	t_queue *ops;

	ops = init_q();
	while(get_next_line(0, &line) > 0)
		enqueue(ops, line);
	while ((op = dequeue(ops)))
	{
		if(!do_instruction(op, stacks))
		{
			ft_putstr("ERROR\n");
			return ;
		}
	}
}

int		main(int ac, char **av)
{
	int		*nums;
	int		len;
	int		*order;
	int		error;
	int		ok;

	ok = 1;

	t_stack	*stacks[2];
	stacks[0] = init();
	stacks[1] = init();
	if (ac == 1)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	if(!(nums = parse_nums(ac, av, &len)))
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	populate_stack(nums, len, stacks);
//	run_instructions(stacks);
	reverse('a', stacks);
	swap('a', stacks);
	ok = push('b', stacks);
	rotate('a', stacks);
	if (!ok)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	return (0);
}
