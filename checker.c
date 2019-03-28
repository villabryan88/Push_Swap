/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:17:25 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/27 22:44:04 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		do_instruction(char *s, t_stack **stacks)
{
	int			len;
	int			ret;

	ret = 1;
	len = ft_strlen(s);
	if (len > 3 || len < 2)
		return (0);
	else if (len == 3)
	{
		if (s[0] != 'r' || s[1] != 'r' || (s[2] != 'a' && s[2] != 'b'))
			return (0);
		else
			return (reverse(s[2] - 'a', stacks, 0));
	}
	else if (s[1] != 'a' && s[1] != 'b')
		return (0);
	else if (s[0] == 'r')
		return (rotate(s[1] - 'a', stacks, 0));
	else if (s[0] == 'p')
		return (push(s[1] - 'a', stacks, 0));
	else if (s[0] == 's')
		return (swap(s[1] - 'a', stacks, 0));
	return (0);
}

int		run_instructions(t_stack **stacks)
{
	char	*line;
	char	*op;
	int		ok;
	t_queue	*ops;
	int		gnl;

	ok = 1;
	ops = init_q();
	while ((gnl = get_next_line(0, &line)) > 0)
		enqueue(ops, line);
	while ((op = dequeue(ops)))
	{
		if (ok)
			ok = do_instruction(op, stacks);
		free(op);
	}
	free(ops);
	return (ok);
}

int		check_order(t_stack **stacks)
{
	int		prev;
	int		curr;
	t_node	*node;

	if (!isempty(stacks[1]))
		return (ko());
	if (!isempty(stacks[0]))
	{
		node = pop(stacks[0]);
		curr = node->val;
		free(node);
	}
	while (!isempty(stacks[0]))
	{
		prev = curr;
		node = pop(stacks[0]);
		curr = node->val;
		free(node);
		if (curr < prev)
			return (ko());
	}
	ft_putendl("OK");
	return (1);
}

int		main(int ac, char **av)
{
	int		*nums;
	int		len;
	int		ok;
	int		debug;
	t_stack	*stacks[2];

	ok = 1;
	stacks[0] = init();
	stacks[1] = init();
	if (ac == 1)
		return (0);
	if (!(nums = parse_nums(ac, av, &len, &debug)))
		return (error());
	populate_stack(nums, len, stacks);
	ok = run_instructions(stacks);
	if (!ok)
		return (error());
	check_order(stacks);
	return (0);
}
