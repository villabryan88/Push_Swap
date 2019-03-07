/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:19:15 by bvilla            #+#    #+#             */
/*   Updated: 2019/03/06 00:33:27 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int *arr_str_to_int(char **str, int *len)
{
	int		*arr;
	int		i;

	*len = ft_arrlen(str, sizeof(*str));
	arr = (int*)ft_memalloc(sizeof(int) * (*len + 1));
	i = 0;
	while (str[i])
	{
		arr[i] = ft_atoi(str[i]);
		i++;
	}
	return (arr);
}

int		*parse_nums(int ac, char **av, int *len)
{
	int		*nums;
	char	**str_nums;
	char	*str;

	str = ft_strnew(1);
	while (--ac)
	{
		str = ft_strjoin_free(str, *(++av), 1, 0);
		str = ft_strjoin_free(str, " ", 1, 0);
	}
	str_nums = ft_strsplit(str, ' ');
	free(str);
	nums = arr_str_to_int(str_nums, len);

	if(!is_valid_input(str_nums) || check_repeat(nums, *len))
	{
		ft_strarrdel(str_nums);
		free(nums);
		return (NULL);
	}
	ft_strarrdel(str_nums);
	return (nums);
}

void	populate_stack(int *nums, int len, t_stack **stacks)
{
	while (len--)
		unshift(stacks[0], new_node(nums[len]));
}
