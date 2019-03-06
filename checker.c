/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:17:25 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/05 19:10:38 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		do_instruction(char *s, t_stack **stacks)
{
	int		len;
	int		ok;
	static int i = 1;

	ok = 1;
	len = ft_strlen(s);
	if (len > 3 || len < 2)
		return (0);
	if (len == 3)
	{
		if (s[0] != 'r' || s[1] != 'r' || (s[2] != 'a' && s[2] != 'b'))
			return (0);
		reverse(s[2] - 'a', stacks, 0);
		return (1);
	}
	if (s[1] != 'a' && s[1] != 'b')
		return (0);
	if (s[0] == 'r')
		rotate(s[1] - 'a', stacks, 0);
	else if (s[0] == 'p')
		ok = push(s[1] - 'a', stacks, 0);
	else if (s[0] == 's')
		swap(s[1] - 'a', stacks, 0);
	else
		return (0);
	return (1);
}

int		run_instructions(t_stack **stacks)
{
	char	*line;
	char	*op;
	int		ok;
	t_queue	*ops;

	ops = init_q();
	while(get_next_line(0, &line) > 0)
		enqueue(ops, line);
	while ((op = dequeue(ops)))
		if(!(ok = do_instruction(op, stacks)))
			return (ok);
	return (ok);
}

int		check_order(t_stack **stacks)
{
	int		prev;
	int		curr;

	if(!isEmpty(stacks[1]))
	{
		ft_putendl("KO");
		return (0);
	}
	if (!isEmpty(stacks[0]))
		curr = pop(stacks[0])->val;
	while (!isEmpty(stacks[0]))
	{
		prev = curr;
		curr = pop(stacks[0])->val;
		if (curr < prev)
		{
		 	ft_putendl("KO");
		  	return (0);
		}
	}
	ft_putendl("OK");
	return (1);
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
	ok = run_instructions(stacks);
	if (!ok)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	check_order(stacks);
	return (0);
}
