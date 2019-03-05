/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:37:02 by bvilla            #+#    #+#             */
/*   Updated: 2019/02/22 13:26:35 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
# define MAP_SIZE 500

int		check_repeat(int *nums, int len)
{
	int		i;
	int		hash;
	t_list	*map[MAP_SIZE];

	ft_bzero(map, sizeof(*map) * MAP_SIZE);
	i = 0;
	while (i < len)
	{
		hash = (unsigned int)nums[i] % MAP_SIZE;
		if (map[hash])
		{
			if(ft_lstsearch(map[hash], nums + i, sizeof(nums[i])))
				return (1);
			else
				ft_lstadd(map + hash, ft_lstnew(nums + i, sizeof(nums[i])));
		}
		else
			map[hash] = ft_lstnew(nums + i, sizeof(nums[i]));
		i++;
	}

	return (0);
}

int		is_valid_input(char **str)
{
	while (*str)
	{
		if (!ft_strisnum(*str) || !ft_strisint(*str))
			return (0);
		str++;
	}
	return (1);
}