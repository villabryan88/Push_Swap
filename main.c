/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/02/20 15:20:12 by bvilla           ###   ########.fr       */
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
	nums = arr_str_to_int(str_nums, len);
	if(!is_valid_input(str_nums) || check_repeat(nums, *len))
		return (NULL);
	return (nums);
}

int		main(int ac, char **av)
{
	int	*nums;
	int	len;

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
	while (len--)
		ft_putnbrendl(*(nums++));
	return (0);
}
