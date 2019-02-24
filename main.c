/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:03:21 by bvilla            #+#    #+#             */
/*   Updated: 2019/02/23 11:38:29 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>
#include <math.h>

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
double	get_avg(int	*nums, int len)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < len)
	{
		sum += nums[i];
		i++;
	}
	return ((sum * 1.0)/len);
}
double	get_sd(int *nums, int len)
{
	int		i;
	float	avg;
	double	sum;
	i = 0;
	sum = 0;
	avg = get_avg(nums, len);
	while (i < len)
		sum += pow(avg - nums[i++], 2);
	return (sqrt(sum / len));
}


void	split_stacks(int stacks[][500], int *nums, int len)
{
	int		i;
	int		c;
	int		prev;
	double	sd;
	double	avg;

	avg = get_avg(nums, len);
//	sd = get_sd(nums, len);
//	printf ("avg: %lf, sd: %lf", avg, sd);
	sd = 12;
	i = 0;
	c = 0;
	prev = 0;
	while (i < len)
	{
		if (nums[i] <= avg / 2)
		{
			prev = nums[i];
			i++;
			break;
		}
		else
		{
			stacks[0][c++] = nums[i];
		}
		i++;
	}
	while (i < len)
	{
		if (nums[i] > prev && nums[i] <= prev + sd)
			prev = nums[i];
		else
		{
			stacks[0][c++] = nums[i];
		}
		i++;
	}
	if (c == len)
		c--;
	stacks[0][c] = 0;
//	printf("%d\n",c);
	if (c != 0)
		split_stacks(stacks + 1, stacks[0], c);
}

int		arr_len(int *arr)
{
	int		i;
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
void	copy_arr(int *dst, int *src, int len)
{
	int 	i;
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

int		main(int ac, char **av)
{
	int	*nums;
	int	len;
	int	i;
	int	stacks[300][500];
	int	c;
	int	*order;
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
	i = 0;
	c = 0;
	while (i < 300)
	{
		while (c < 500)
			stacks[i][c++] = 0;
		i++;
	}

	split_stacks(stacks, nums, len);
	c = 0;
	while (stacks[c][0])
	{
		i = 0;
		while (stacks[c][i])
			i++;
		ft_putnbrendl(i);
		c++;
	}

	return (0);
}
