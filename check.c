/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:37:02 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/06 00:41:44 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
# define MAP_SIZE 500

void	delete_map(t_list *map[MAP_SIZE])
{
	int		i;

	i = 0;
	while (i < MAP_SIZE)
	{
		if (map[i])
			ft_lstdel(map + i, ft_lstdelnode);
		i++;
	}
}

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
			{
				delete_map(map);
				return (1);
			}
			else
				ft_lstadd(map + hash, ft_lstnew(nums + i, sizeof(nums[i])));
		}
		else
			map[hash] = ft_lstnew(nums + i, sizeof(nums[i]));
		i++;
	}
	delete_map(map);
	return (0);
}

int		is_valid_input(char **str)
{
	while (*str)
	{
		if (!ft_strisint(*str))
			return (0);
		str++;
	}
	return (1);
}
