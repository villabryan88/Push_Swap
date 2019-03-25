/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:13:17 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/25 11:23:54 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		can_push(t_node *iter, t_block *block)
{
	if (block->side == 0 && iter->val < block->part)
		return (1);
	if (block->side == 1 && iter->val > block->part)
		return (1);
	return (0);
}

int		can_pushkeep(t_node *iter, t_block *block)
{
	if (ft_strstr(block->msg, "push"))
		return(can_push(iter, block));
	else if (ft_strstr(block->msg, "keep"))
		return(!can_push(iter, block));
	return (0);
}

int		set_value(t_node *iter, t_block *block)
{
	if (can_pushkeep(iter, block) || (!ft_strstr(block->msg, "push") && !ft_strstr(block->msg, "keep")))
	{
		if (ft_strstr(block->msg, "start"))
		{
			*(t_node**)(block->set_var) = iter;
			return (iter_stop());
		}
		if (ft_strstr(block->msg, "end"))
		{
			*(t_node**)(block->set_var) = iter;
			return (iter_continue());
		}
	}
	return (iter_continue());
}

void	set_temp_value(t_block *block, t_node **var, char *var_name)
{
	block->msg = var_name;
	block->set_var = var;
	block_iter(block, set_value);
}

void	set_block(t_stack **stacks, t_block *block)
{
	t_node	*loc;
	int		tmp;

	loc = stacks[block->side]->top;
	set_temp_value(block, &(block->push_start), "push_start");
	set_temp_value(block, &(block->push_end), "push_end");
	set_temp_value(block, &(block->keep_start), "keep_start");
	set_temp_value(block, &(block->keep_end), "keep_end");
	set_temp_value(block, &(block->end), "end");

	ft_printf("loc: %d\n", loc->val);

	if (loc == block->start)
	{
		block->keep_above = 0;
		block->push_above = 0;
	}
	else
	{
		block->msg = "keep";
		block->keep_above = piece_iter(block->push_start, loc->prev, block, can_pushkeep);
		block->msg = "push";
		block->push_above = piece_iter(block->push_start, loc->prev, block, can_pushkeep);
	}

	if (loc == block->end)
	{
		block->keep_below = 0;
		block->push_below = 0;
	}
	else
	{
		block->msg = "keep";
		block->keep_below = piece_iter(loc->next, block->push_end, block, can_pushkeep);
		block->msg = "push";
		block->push_below = piece_iter(loc->next, block->push_end, block, can_pushkeep);
	}

}
/*
int		set_
{
	int		part;
	int		side;
	int		*start;

	part = block->part;
	side = block->side;
	if (side == 0 && iter->val >= part)
	{
		block->keep_start = iter;
		return (-1);
	}
	if (side == 1 && iter->val <= part)
	{
		block->keep_start = iter;
		return (-1);
	}
	return (0);
}

int		set_push_start(t_node *iter, t_block *block)
{
	int		part;
	int		side;
	int		*start;

	part = block->part;
	side = block->side;
	if (side == 0 && iter->val <= part)
	{
		block->keep_start = iter;
		return (-1);
	}
	if (side == 1 && iter->val >= part)
	{
		block->keep_start = iter;
		return (-1);
	}
	return (0);
}

int		set_push_stop(t_node *iter, t_block *block)
{
	int		part;
	int		side;
	int		*start;

	part = block->part;
	side = block->side;
	if (side == 0 && iter->val <= part)
	{
		block->keep_start = iter;
		return (0);
	}
	if (side == 1 && iter->val >= part)
	{
		block->keep_start = iter;
		return (0);
	}
	return (0);
}
*/
