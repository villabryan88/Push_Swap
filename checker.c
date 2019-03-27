/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:17:25 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 14:21:36 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		do_instruction(char *s, t_stack **stacks)
{
	int		len;
	int		ret;
	static int i = 1;

	ret = 1;
	len = ft_strlen(s);
	if (len > 3 || len < 2)
		ret = 0;
	else if (len == 3)
	{
		if (s[0] != 'r' || s[1] != 'r' || (s[2] != 'a' && s[2] != 'b'))
			ret = 0;
		else 
			reverse(s[2] - 'a', stacks, 0);
			ret = 1;
	}
	else if (s[1] != 'a' && s[1] != 'b')
		ret = 0;
	else if (s[0] == 'r')
		rotate(s[1] - 'a', stacks, 0);
	else if (s[0] == 'p')
		ret = push(s[1] - 'a', stacks, 0);
	else if (s[0] == 's')
		swap(s[1] - 'a', stacks, 0);
	else
		ret = 0;
	free (s);
	return (ret);
}

int		run_instructions(t_stack **stacks)
{
	char	*line;
	char	*op;
	int		ok;
	t_queue	*ops;
	int		gnl;

	ops = init_q();
	while((gnl = get_next_line(0, &line)) > 0)
		enqueue(ops, line);
	while ((op = dequeue(ops)))
		if(!(ok = do_instruction(op, stacks)))
		{
			free(ops);
			return (ok);
		}
	free(ops);
	return (ok);
}

int		check_order(t_stack **stacks)
{
	int		prev;
	int		curr;
	t_node	*node;

	if(!isEmpty(stacks[1]))
	{
		ft_putendl("KO");
		return (0);
	}
	if (!isEmpty(stacks[0]))
	{
		node = pop(stacks[0]);
		curr = node->val;
		free(node);
	}
	while (!isEmpty(stacks[0]))
	{
		prev = curr;
		node = pop(stacks[0]);
		curr = node->val;
		free(node);
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
	int		ok;
	int		debug;

	ok = 1;

	t_stack	*stacks[2];
	stacks[0] = init();
	stacks[1] = init();
	if (ac == 1)
	{
		return (0);
	}
	if(!(nums = parse_nums(ac, av, &len, &debug)))
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
